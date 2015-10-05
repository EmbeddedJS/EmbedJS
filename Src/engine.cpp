/*
 * engine.cpp
 *
 *  Created on: 2015. 10. 5.
 *      Author: InhoChoi
 */
#include "engine.h"

static CTinyJS *js;
extern "C"{
	void EngineInit(){
		js = new CTinyJS();
		RegisterNative();
	}

	static void RegisterNative(){
		js->addNative("function Toggle()", &LEDToggle, 0);
		js->addNative("function Delay(msec)",&Delay,0);
	}
	void Execute(const char *str){
		js->execute(str);
	}

	void LEDToggle(CScriptVar *v, void *userdata){
		(void *)userdata;
	    HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	}

	void Delay(CScriptVar *v, void *userdata){
		int delay = v->getParameter("msec")->getInt();
		osDelay(delay);
	}
}

