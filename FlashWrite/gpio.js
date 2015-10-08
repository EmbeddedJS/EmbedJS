
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

pinMode(E,13,OUTPUT);
while(1){
	digitalWrite(E,13,1);
	Delay(100);
	digitalWrite(E,13,0);
	Delay(100);
}
