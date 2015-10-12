
#include "main.h"
#include "TinyJS.h"
extern "C"{
	void js_analogRead(CScriptVar *v, void *userdata);
	void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc);
}
