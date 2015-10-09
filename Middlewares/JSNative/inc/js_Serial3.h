#include "main.h"
#include "TinyJS.h"

extern "C"{

	void js_Serial3_Begin(CScriptVar *v, void *userdata);
	void js_Serial3_Print(CScriptVar *v, void *userdata);
	void js_Serial3_Read(CScriptVar *v, void *userdata);
	void js_Serial3_Available(CScriptVar *v, void *userdata);

	static void Serial3_init();
}
