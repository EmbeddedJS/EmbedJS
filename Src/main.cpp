#include "main.h"
#include "TinyJS.h"
#include "TinyJS_Functions.h"
extern "C"{void _init(){};}
//Private define
#define FLASH_USER_START_ADDR   ADDR_FLASH_SECTOR_9   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     ADDR_FLASH_SECTOR_10   /* End @ of user Flash area */

#define DATA_32                 ((uint32_t)0x12345678)

//Private Function
static void SystemClock_Config(void);
static uint32_t GetSector(uint32_t Address);

//Public function
void commandWrite();
void LEDToggle(CScriptVar *v, void *userdata);

//Private variable
static GPIO_InitTypeDef  GPIO_InitStruct;
static FLASH_EraseInitTypeDef EraseInitStruct;


uint32_t FirstSector = 0, NbOfSectors = 0;
uint32_t Address = 0, SectorError = 0;
__IO uint32_t data32 = 0 , MemoryProgramStatus = 0;


int main(int argc,char* argv[]){
	HAL_Init();
	/* Configure the system clock */
	SystemClock_Config();
	commandWrite();
    __GPIOE_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    CTinyJS *js = new CTinyJS();
    registerFunctions(js);
    js->addNative("function Toggle()", &LEDToggle, 0);

	while(1){
		try{
			js->execute((const char *)ADDR_FLASH_SECTOR_9);
			//js->execute("Toggle(100);");
			//js->execute("Toggle(1000);");
			//js->execute("Toggle(2000);");
			//js->execute("Toggle(3000);");
		}catch(CScriptException e){

		}
	}
	return 0;
}

void LEDToggle(CScriptVar *v, void *userdata){
	//int delay = v->getParameter("delay")->getInt();

    HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
    /* Insert delay 100 ms */
    HAL_Delay(1000);
}

static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 240;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 5;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3);
}


void commandWrite(){
	HAL_FLASH_Unlock();
	/* Get the 1st sector to erase */
	FirstSector = GetSector(FLASH_USER_START_ADDR);
	  /* Get the number of sector to erase from 1st sector*/
	NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;

	  /* Fill EraseInit structure*/
	EraseInitStruct.TypeErase = TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange = VOLTAGE_RANGE_3;
	EraseInitStruct.Sector = FirstSector;
	EraseInitStruct.NbSectors = NbOfSectors;

	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK)
	{
	    /*
	      Error occurred while sector erase.
	      User can add here some code to deal with this error.
	      SectorError will contain the faulty sector and then to know the code error on this sector,
	      user can call function 'HAL_FLASH_GetError()'
	    */
	  while (1)
	  {
	  }
	}
	// String Toggle();
	Address = FLASH_USER_START_ADDR;
	int ret = HAL_FLASH_Program(TYPEPROGRAM_WORD, Address, (uint32_t) 0x67676f54);
	if(ret != HAL_OK) while(1);
	Address = Address + 4;
	HAL_FLASH_Program(TYPEPROGRAM_WORD, Address, (uint32_t)  0x2928656c);
	if(ret != HAL_OK) while(1);
	Address = Address + 4;
	HAL_FLASH_Program(TYPEPROGRAM_WORD, Address, (uint32_t)  0x0000003b);
	if(ret != HAL_OK) while(1);

	HAL_FLASH_Lock();
}

static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
  else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;
  }
  else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
  {
    sector = FLASH_SECTOR_6;
  }
  else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
  {
    sector = FLASH_SECTOR_7;
  }
  else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
  {
    sector = FLASH_SECTOR_8;
  }
  else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
  {
    sector = FLASH_SECTOR_9;
  }
  else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
  {
    sector = FLASH_SECTOR_10;
  }
  else /* (Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_11) */
  {
    sector = FLASH_SECTOR_11;
  }

  return sector;
}
