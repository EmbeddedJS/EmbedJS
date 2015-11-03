#include "main.h"
#include "TinyJS.h"

extern "C"{

	void js_Serial1_Begin(CScriptVar *v, void *userdata);
	void js_Serial1_Print(CScriptVar *v, void *userdata);
	void js_Serial1_Read(CScriptVar *v, void *userdata);
	void js_Serial1_Available(CScriptVar *v, void *userdata);

	static void Serial1_init();
}
