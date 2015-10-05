/*
 * engine.h
 *
 *  Created on: 2015. 10. 5.
 *      Author: InhoChoi
 */

#ifndef DRIVERS_ENGINE_H_
#define DRIVERS_ENGINE_H_
extern "C"{
	void EngineInit();
	void Execute(const char * str);
	static void RegisterNative();

	//BSP LED1 Toggle
	void LEDToggle(CScriptVar *v, void *userdata);
}




#endif /* DRIVERS_ENGINE_H_ */
