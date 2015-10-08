
Serial3.begin(9600);
pinMode(4,13,1);

while(1){
	var input = Serial3.read();
	if(input == "a"){
		digitalWrite(4,13,0);
	}else{
		digitalWrite(4,13,1);
	}
	Delay(1000);
}