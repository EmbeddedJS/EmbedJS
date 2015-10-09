#include "main.h"
#include "TinyJS.h"

extern "C"{
void js_pinMode(CScriptVar *v, void *userdata);
void js_digitalWrite(CScriptVar *v, void *userdata);
void js_digitalRead(CScriptVar *v, void *userdata);
}
