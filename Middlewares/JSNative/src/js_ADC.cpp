#include "js_ADC.h"

extern "C"{
	static ADC_HandleTypeDef    AdcHandle;
	static __IO uint16_t uhADCxConvertedValue = 0;
	static GPIO_TypeDef* Types[] = {
		0,0,GPIOC,0,0
	};
	static uint32_t Pins[] = {
			ADC_CHANNEL_10,ADC_CHANNEL_11,ADC_CHANNEL_12,ADC_CHANNEL_13,0,0,0,0,0,
			0,0,0,0,0,0,0
	};

	void js_analogRead(CScriptVar *v, void *userdata){
		int type = v->getParameter("type")->getInt();
		int pin = v->getParameter("pin")->getInt();
		if(Types[type] == 0 || Pins[pin] ==0){
			v->getReturnVar()->setInt(0);
			return;
		}

		if(AdcHandle.Instance != ADC3){
		  AdcHandle.Instance          = ADC3;
		  AdcHandle.Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV2;
		  AdcHandle.Init.Resolution            = ADC_RESOLUTION12b;
		  AdcHandle.Init.ScanConvMode          = DISABLE;
		  AdcHandle.Init.ContinuousConvMode    = DISABLE;
		  AdcHandle.Init.DiscontinuousConvMode = DISABLE;
		  AdcHandle.Init.NbrOfDiscConversion   = 0;
		  AdcHandle.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
		  AdcHandle.Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T1_CC1;
		  AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
		  AdcHandle.Init.NbrOfConversion       = 1;
		  AdcHandle.Init.DMAContinuousRequests = DISABLE;
		  AdcHandle.Init.EOCSelection          = DISABLE;

		  if (HAL_ADC_Init(&AdcHandle) != HAL_OK)
		  {
			  v->getReturnVar()->setInt(0);
			  return;
		  }
		}
		  ADC_ChannelConfTypeDef sConfig;
		  sConfig.Channel      = Pins[pin];
		  sConfig.Rank         = 1;
		  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
		  sConfig.Offset       = 0;

		  if (HAL_ADC_ConfigChannel(&AdcHandle, &sConfig) != HAL_OK)
		  {
			  v->getReturnVar()->setInt(0);
			  return;
		  }
		  if (HAL_ADC_Start(&AdcHandle) != HAL_OK)
		  {
			  v->getReturnVar()->setInt(0);
			  return;
		  }

		  HAL_ADC_PollForConversion(&AdcHandle, 10);
		  if (HAL_ADC_GetState(&AdcHandle) == HAL_ADC_STATE_EOC_REG)
		  {
			  uhADCxConvertedValue = HAL_ADC_GetValue(&AdcHandle);
		  }

		  v->getReturnVar()->setInt(uhADCxConvertedValue);
		  return;
	}
	void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc){
		  GPIO_InitTypeDef          GPIO_InitStruct;

		  __ADC3_CLK_ENABLE();
		  __GPIOC_CLK_ENABLE();

		  GPIO_InitStruct.Pin = GPIO_PIN_0;
		  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		  GPIO_InitStruct.Pin = GPIO_PIN_1;
		  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		  GPIO_InitStruct.Pin = GPIO_PIN_2;
		  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		  GPIO_InitStruct.Pin = GPIO_PIN_3;
		  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	}
}
