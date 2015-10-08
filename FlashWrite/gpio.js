
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
pinMode(E,14,OUTPUT);
pinMode(E,15,OUTPUT);

while(1){
	digitalWrite(E,13,0);
	digitalWrite(E,14,1);
	digitalWrite(E,15,1);
	Delay(1000);
	digitalWrite(E,13,1);
	digitalWrite(E,14,0);
	digitalWrite(E,15,1);
	Delay(1000);
	digitalWrite(E,13,1);
	digitalWrite(E,14,1);
	digitalWrite(E,15,0);
	Delay(1000);
}
