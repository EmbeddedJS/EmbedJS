Serial3.begin(9600);
pinMode(4,13,1);
while(1){
		while(Serial3.available()){
				var ch = Serial3.read();
				if( ch != 0){
						Serial3.print(ch);
				}
		}
		digitalWrite(4,13,0);
		Delay(500);
		digitalWrite(4,13,1);
		Delay(500);
}
