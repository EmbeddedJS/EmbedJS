#include "js_Serial1.h"
#include <string.h>
extern "C"{
#define BUFSIZE 256

	UART_HandleTypeDef Serial1;
	static uint8_t RxBuffer1[BUFSIZE];

	void js_Serial1_Begin(CScriptVar *v, void *userdata){
		int speed = v->getParameter("speed")->getInt();
		Serial1_init();
		Serial1.Instance        = USART3;
		Serial1.Init.BaudRate   = speed;
		Serial1.Init.WordLength = UART_WORDLENGTH_8B;
		Serial1.Init.StopBits   = UART_STOPBITS_1;
		Serial1.Init.Parity     = UART_PARITY_NONE;
		Serial1.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
		Serial1.Init.Mode       = UART_MODE_TX_RX;
		if (HAL_UART_Init(&Serial1) != HAL_OK){
			v->getReturnVar()->setInt(0);
			return;
		}
		if (HAL_UART_Receive_IT(&Serial1,RxBuffer1,BUFSIZE) != HAL_OK){
			v->getReturnVar()->setInt(0);
			return;
		}
		v->getReturnVar()->setInt(1);

	}

	void js_Serial1_Print(CScriptVar *v, void *userdata){
		const char *str = v->getParameter("str")->getString().c_str();
		int len = strlen(str);
		HAL_UART_Transmit(&Serial1,(uint8_t *)str,len,60*1000);
	}

	void js_Serial1_Read(CScriptVar *v, void *userdata){
		HAL_NVIC_DisableIRQ(USART1_IRQn);
		char str[2] = {RxBuffer1[0],0};
		int RxXferCount = 0;

		RxXferCount = Serial1.RxXferCount;
		if(RxXferCount == BUFSIZE){
			v->getReturnVar()->setInt(0);
			return;
		}

		for(int i=0;i<RxXferCount;i++){
			RxBuffer1[i] = RxBuffer1[i+1];
		}

		Serial1.RxXferCount ++;
		Serial1.pRxBuffPtr --;
		v->getReturnVar()->setString(str);
		HAL_NVIC_EnableIRQ(USART1_IRQn);
	}

	void js_Serial1_Available(CScriptVar *v, void *userdata){
		int size = BUFSIZE - Serial1.RxXferCount;
		v->getReturnVar()->setInt(size);
	}
	static void Serial1_init(){
	  GPIO_InitTypeDef  GPIO_InitStruct;

	  __GPIOA_CLK_ENABLE();
	  __USART1_CLK_ENABLE();


	  GPIO_InitStruct.Pin       = GPIO_PIN_9;
	  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
	  GPIO_InitStruct.Pull      = GPIO_PULLUP;
	  GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
	  GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_10;
	  GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	  //USART3_IRQn
	  HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
	  HAL_NVIC_EnableIRQ(USART1_IRQn);
	}
}
