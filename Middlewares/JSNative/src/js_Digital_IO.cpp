#include "js_Digital_IO.h"

extern "C"{
	static GPIO_InitTypeDef  GPIO_InitStruct;
	static uint16_t Pins[] = {
			GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7,GPIO_PIN_8,
			GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15
	};

	static uint32_t Modes[] = {
			GPIO_MODE_INPUT,GPIO_MODE_OUTPUT_PP,GPIO_MODE_OUTPUT_OD
	};

	static GPIO_TypeDef* Types[] = {
			GPIOA,GPIOB,GPIOC,GPIOD,GPIOE
	};

	static GPIO_PinState Values[] = {
			GPIO_PIN_RESET,GPIO_PIN_SET
	};

	void js_pinMode(CScriptVar *v, void *userdata){
		int type = v->getParameter("type")->getInt();
		int pin = v->getParameter("pin")->getInt();
		int mode = v->getParameter("mode")->getInt();

		GPIO_InitStruct.Pin = Pins[pin];
		GPIO_InitStruct.Mode = Modes[mode];
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
		HAL_GPIO_Init(Types[type], &GPIO_InitStruct);
	}
	void js_digitalWrite(CScriptVar *v, void *userdata){
		int type = v->getParameter("type")->getInt();
		int pin = v->getParameter("pin")->getInt();
		int value = v->getParameter("value")->getInt();
		HAL_GPIO_WritePin(Types[type],Pins[pin],Values[value]);
	}
	void js_digitalRead(CScriptVar *v, void *userdata){
		int type = v->getParameter("type")->getInt();
		int pin = v->getParameter("pin")->getInt();
		int ret = HAL_GPIO_ReadPin(Types[type],Pins[pin]);

		v->getReturnVar()->setInt(ret);
	}

}

