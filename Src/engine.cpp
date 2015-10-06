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
		js->addNative("function Delay(msec)",&Delay,0);
		js->addNative("function pinMode(type,pin,mode)",&js_pinMode,0);
		js->addNative("function digitalWrite(type,pin,value)",&js_digitalWrite,0);
		js->addNative("function digitalRead(type,pin)",&js_digitalRead,0);
	}
	void Execute(const char *str){
		js->execute(str);
	}

	void Delay(CScriptVar *v, void *userdata){
		int delay = v->getParameter("msec")->getInt();
		osDelay(delay);
	}
}

