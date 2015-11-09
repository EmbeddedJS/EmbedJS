#include "js_PWM.h"
extern "C"{
	static GPIO_TypeDef* Types[] = {
		0,0,GPIOC,0,0
	};
	static uint32_t Pins[] = {
			-1,-1,-1,-1,-1,-1,TIM_CHANNEL_1,TIM_CHANNEL_2,TIM_CHANNEL_3,
			TIM_CHANNEL_4,-1,-1,-1,-1,-1,-1
	};

	TIM_HandleTypeDef    TimHandle;
	TIM_OC_InitTypeDef sConfig;
	uint32_t uhPrescalerValue = 0;

	void js_analogWrite(CScriptVar *v, void *userdata){
		int type = v->getParameter("type")->getInt();
		int pin = v->getParameter("pin")->getInt();
		int value = v->getParameter("value")->getInt();

		if( Types[type] == 0 || Pins[pin] == -1 || value < 0 || value > 1024)
			return;

		TimHandle.Instance = TIMx;

		uhPrescalerValue = (uint32_t)((SystemCoreClock / 2) / 15000000) - 1;
		TimHandle.Init.Prescaler = uhPrescalerValue;
		TimHandle.Init.Period = 1024;
		TimHandle.Init.ClockDivision = 0;
		TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	    if(HAL_TIM_PWM_Init(&TimHandle) != HAL_OK)
	    	return;


		sConfig.OCMode = TIM_OCMODE_PWM1;
		sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfig.OCFastMode = TIM_OCFAST_DISABLE;
		sConfig.Pulse = value;

//		if(value ==0){
//			HAL_TIM_PWM_Stop(TimHandle,Pins[pin]);
//			return;
//		}

		if(HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, Pins[pin]) != HAL_OK)
			return;

		if( value == 0){
			HAL_TIM_PWM_Stop(&TimHandle,Pins[pin]);
			return;
		}

		if(HAL_TIM_PWM_Start(&TimHandle, Pins[pin]) != HAL_OK)
			return;
	}

	void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
	{
	  GPIO_InitTypeDef   GPIO_InitStruct;
	  /*##-1- Enable peripherals and GPIO Clocks #################################*/
	  /* TIMx Peripheral clock enable */
	  TIMx_CLK_ENABLE();

	  /* Enable GPIO Channels Clock */
	  TIMx_CHANNEL_GPIO_PORT();

	  /* Configure PC.6 (TIM3_Channel1), PC.7 (TIM3_Channel2), PC.8 (TIM3_Channel3),
	     PC.9 (TIM3_Channel4) in output, push-pull, alternate function mode
	  */
	  /* Common configuration for all channels */
	  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	  GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;

	  GPIO_InitStruct.Pin = GPIO_PIN_CHANNEL1;
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_CHANNEL2;
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_CHANNEL3;
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_CHANNEL4;
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	}
}

