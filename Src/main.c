#include "main.h"
//#include "TinyJS.h"
#include "cmsis_os.h"

//extern "C"{
//	void _init(){};
//}

void _init(){};

// System Clock
static void SystemClock_Config(void);
static void GPIOClock_Enable(void);

// LED Tooggle
static void BSP_LED_Init(void);
//void LEDToggle(CScriptVar *v, void *userdata);

static void EngineThread(void const * argument);
static GPIO_InitTypeDef  GPIO_InitStruct;

int main(int argc,char* argv[]){
	HAL_Init();

	SystemClock_Config();
	GPIOClock_Enable();
	BSP_LED_Init();

	osThreadDef(Engine, EngineThread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 4 * 2);
	osThreadCreate (osThread(Engine), NULL);

	/* Start scheduler */
	osKernelStart (NULL, NULL);
	while(1);
	return 0;
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

static void GPIOClock_Enable(void){
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();
    __GPIOE_CLK_ENABLE();
	__GPIOF_CLK_ENABLE();
	__GPIOG_CLK_ENABLE();
	__GPIOH_CLK_ENABLE();
	__GPIOI_CLK_ENABLE();
}

static void BSP_LED_Init(void){
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_14;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_15;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}


extern void excute(const char *command);
static void EngineThread(void const * argument){
    //CTinyJS *js = new CTinyJS();
    //js->addNative("function Toggle()", &LEDToggle, 0);
	EngineInit();
	while(1){
		Execute("Toggle();");
		osDelay(1000);
		/*
		try{
			//js->execute((const char *)ADDR_FLASH_SECTOR_9);
			osDelay(1000);
		}catch(CScriptException e){

		}*/
	}
}
