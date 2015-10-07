/*
 * js_PWM.h
 *
 *  Created on: 2015. 10. 7.
 *      Author: InhoChoi
 */

#ifndef MIDDLEWARES_JSNATIVE_INC_JS_PWM_H_
#define MIDDLEWARES_JSNATIVE_INC_JS_PWM_H_


#include "main.h"
#include "TinyJS.h"
extern "C"{
	#define TIMx                           TIM3
	#define TIMx_CLK_ENABLE                __TIM3_CLK_ENABLE
	#define TIMx_CHANNEL_GPIO_PORT()       __GPIOC_CLK_ENABLE()
	#define GPIO_PIN_CHANNEL1              GPIO_PIN_6
	#define GPIO_PIN_CHANNEL2              GPIO_PIN_7
	#define GPIO_PIN_CHANNEL3              GPIO_PIN_8
	#define GPIO_PIN_CHANNEL4              GPIO_PIN_9

	void js_analogWrite(CScriptVar *v, void *userdata);
	void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim);
}


#endif /* MIDDLEWARES_JSNATIVE_INC_JS_PWM_H_ */
