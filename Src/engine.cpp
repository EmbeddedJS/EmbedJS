/*
 * engine.cpp
 *
 *  Created on: 2015. 10. 5.
 *      Author: InhoChoi
 */

#include "TinyJS.h"
#include "engine.h"

CTinyJS *js;
extern "C"{
	#include "main.h"

	void EngineInit(){
		js = new CTinyJS();
		RegisterNative();
	}

	static void RegisterNative(){
		js->addNative("function Toggle()", &LEDToggle, 0);
	}
	void Execute(const char *str){
		js->execute(str);
	}

	void LEDToggle(CScriptVar *v, void *userdata){
		(void *)userdata;
	    HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	}
}

