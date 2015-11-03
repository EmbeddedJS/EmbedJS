#include "js_Serial2.h"
#include <string.h>
extern "C"{
#define BUFSIZE 256

	UART_HandleTypeDef Serial2;
	static uint8_t RxBuffer2[BUFSIZE];

	void js_Serial2_Begin(CScriptVar *v, void *userdata){
		int speed = v->getParameter("speed")->getInt();
		Serial2_init();
		Serial2.Instance        = USART3;
		Serial2.Init.BaudRate   = speed;
		Serial2.Init.WordLength = UART_WORDLENGTH_8B;
		Serial2.Init.StopBits   = UART_STOPBITS_1;
		Serial2.Init.Parity     = UART_PARITY_NONE;
		Serial2.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
		Serial2.Init.Mode       = UART_MODE_TX_RX;
		if (HAL_UART_Init(&Serial2) != HAL_OK){
			v->getReturnVar()->setInt(0);
			return;
		}
		if (HAL_UART_Receive_IT(&Serial2,RxBuffer2,BUFSIZE) != HAL_OK){
			v->getReturnVar()->setInt(0);
			return;
		}
		v->getReturnVar()->setInt(1);

	}

	void js_Serial2_Print(CScriptVar *v, void *userdata){
		const char *str = v->getParameter("str")->getString().c_str();
		int len = strlen(str);
		HAL_UART_Transmit(&Serial2,(uint8_t *)str,len,60*1000);
	}

	void js_Serial2_Read(CScriptVar *v, void *userdata){
		HAL_NVIC_DisableIRQ(USART2_IRQn);
		char str[2] = {RxBuffer2[0],0};
		int RxXferCount = 0;

		RxXferCount = Serial2.RxXferCount;
		if(RxXferCount == BUFSIZE){
			v->getReturnVar()->setInt(0);
			return;
		}

		for(int i=0;i<RxXferCount;i++){
			RxBuffer2[i] = RxBuffer2[i+1];
		}

		Serial2.RxXferCount ++;
		Serial2.pRxBuffPtr --;
		v->getReturnVar()->setString(str);
		HAL_NVIC_EnableIRQ(USART2_IRQn);
	}

	void js_Serial2_Available(CScriptVar *v, void *userdata){
		int size = BUFSIZE - Serial2.RxXferCount;
		v->getReturnVar()->setInt(size);
	}
	static void Serial2_init(){
	  GPIO_InitTypeDef  GPIO_InitStruct;

	  __GPIOD_CLK_ENABLE();
	  __USART2_CLK_ENABLE();


	  GPIO_InitStruct.Pin       = GPIO_PIN_5;
	  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
	  GPIO_InitStruct.Pull      = GPIO_PULLUP;
	  GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
	  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;

	  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_6;
	  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;

	  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	  //USART3_IRQn
	  HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
	  HAL_NVIC_EnableIRQ(USART2_IRQn);
	}
}
