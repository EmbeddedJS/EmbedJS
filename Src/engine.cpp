/*
 * engine.cpp
 *
 *  Created on: 2015. 10. 5.
 *      Author: InhoChoi
 */
#include "engine.h"

static CTinyJS *js;
extern void registerFunctions(CTinyJS *tinyJS);
extern "C"{
	void EngineInit(){
		js = new CTinyJS();
		RegisterNative();
	}

	static void RegisterNative(){
		registerFunctions(js);

		js->addNative("function Delay(msec)",&Delay,0);
		js->addNative("function pinMode(type,pin,mode)",&js_pinMode,0);
		js->addNative("function digitalWrite(type,pin,value)",&js_digitalWrite,0);
		js->addNative("function digitalRead(type,pin)",&js_digitalRead,0);
		js->addNative("function analogWrite(type,pin,value)",&js_analogWrite,0);

		/** Serial 3 **/
		js->addNative("function Serial3.begin(speed)",&js_Serial3_Begin,0);
		js->addNative("function Serial3.print(str)",&js_Serial3_Print,0);
		js->addNative("function Serial3.read()",&js_Serial3_Read,0);
	}
	void Execute(const char *str){
		js->execute(str);
	}

	void Delay(CScriptVar *v, void *userdata){
		int delay = v->getParameter("msec")->getInt();
		osDelay(delay);
	}
}

