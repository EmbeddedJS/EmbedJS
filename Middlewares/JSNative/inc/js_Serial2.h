#include "main.h"
#include "TinyJS.h"

extern "C"{

	void js_Serial2_Begin(CScriptVar *v, void *userdata);
	void js_Serial2_Print(CScriptVar *v, void *userdata);
	void js_Serial2_Read(CScriptVar *v, void *userdata);
	void js_Serial2_Available(CScriptVar *v, void *userdata);

	static void Serial2_init();
}
