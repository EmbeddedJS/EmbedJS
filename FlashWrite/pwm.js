

//JavaScript Binding GPIO Setting
var A = 0;
var B = 1;
var C = 2;
var D = 3;
var E = 4;
var INPUT = 0;
var OUTPUT = 1;
var LOW = 0;
var HIGH = 1;	

//PWM Setting
var PWM_Pin = 9;
var value = 1024;

while(1){	
	analogWrite(C,PWM_Pin,100);
	Delay(1000);
	analogWrite(C,PWM_Pin,512);
	Delay(1000);
	analogWrite(C,PWM_Pin,1000);
	Delay(1000);
}