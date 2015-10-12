
Serial3.begin(9600);
pinMode(4,13,1);

while(1){
	var value = analogRead(2,3);
	Serial3.print(value);
	Serial3.print("\n");
	Delay(1000);
}
