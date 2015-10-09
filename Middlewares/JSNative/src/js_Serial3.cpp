#include "js_Serial3.h"
#include <string.h>
extern "C"{
#define BUFSIZE 256

	UART_HandleTypeDef Serial3;
	static uint8_t RxBuffer3[BUFSIZE];

	void js_Serial3_Begin(CScriptVar *v, void *userdata){
		int speed = v->getParameter("speed")->getInt();
		Serial3_init();
		Serial3.Instance        = USART3;
		Serial3.Init.BaudRate   = speed;
		Serial3.Init.WordLength = UART_WORDLENGTH_8B;
		Serial3.Init.StopBits   = UART_STOPBITS_1;
		Serial3.Init.Parity     = UART_PARITY_NONE;
		Serial3.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
		Serial3.Init.Mode       = UART_MODE_TX_RX;
		if (HAL_UART_Init(&Serial3) != HAL_OK){
			v->getReturnVar()->setInt(0);
			return;
		}
		if (HAL_UART_Receive_IT(&Serial3,RxBuffer3,BUFSIZE) != HAL_OK){
			v->getReturnVar()->setInt(0);
			return;
		}
		v->getReturnVar()->setInt(1);

	}

	void js_Serial3_Print(CScriptVar *v, void *userdata){
		const char *str = v->getParameter("str")->getString().c_str();
		int len = strlen(str);
		HAL_UART_Transmit(&Serial3,(uint8_t *)str,len,60*1000);
	}

	void js_Serial3_Read(CScriptVar *v, void *userdata){

		char str[2] = {RxBuffer3[0],0};
		int RxXferCount = 0;

		RxXferCount = Serial3.RxXferCount;
		if(RxXferCount == BUFSIZE){
			v->getReturnVar()->setInt(0);
			return;
		}

		for(int i=0;i<RxXferCount;i++){
			RxBuffer3[i] = RxBuffer3[i+1];
		}

		Serial3.RxXferCount ++;
		Serial3.pRxBuffPtr --;
		v->getReturnVar()->setString(str);

	}

	void js_Serial3_Available(CScriptVar *v, void *userdata){
		int size = BUFSIZE - Serial3.RxXferCount;
		v->getReturnVar()->setInt(size);
	}
	static void Serial3_init(){

	  GPIO_InitTypeDef  GPIO_InitStruct;

	  __GPIOC_CLK_ENABLE();
	  __USART3_CLK_ENABLE();


	  GPIO_InitStruct.Pin       = GPIO_PIN_10;
	  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
	  GPIO_InitStruct.Pull      = GPIO_PULLUP;
	  GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
	  GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = GPIO_PIN_11;
	  GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	  //USART3_IRQn
	  HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	  HAL_NVIC_EnableIRQ(USART3_IRQn);
	}
}
