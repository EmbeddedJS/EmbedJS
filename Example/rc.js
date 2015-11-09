//Bluetooth
Serial3.begin(9600);

// analogWrite(PINC,6,512);
// analogWrite(PINC,7,0);
// analogWrite(PINC,8,512);
// analogWrite(PINC,9,0);

while (1) {
    while (Serial3.available()) {
        var ch = Serial3.read();
        if (ch == 'x') {
            analogWrite(PINC,6,0);
            analogWrite(PINC,7,512);
            analogWrite(PINC,8,0);
            analogWrite(PINC,9,512);
        }
        if (ch == 'w') {
            analogWrite(PINC,6,512);
            analogWrite(PINC,7,0);
            analogWrite(PINC,8,512);
            analogWrite(PINC,9,0);
        }
        if (ch == 'd') {
            analogWrite(PINC,6,512);
            analogWrite(PINC,7,0);
            analogWrite(PINC,8,0);
            analogWrite(PINC,9,0);
        }
        if (ch == 'a') {
            analogWrite(PINC,6,0);
            analogWrite(PINC,7,0);
            analogWrite(PINC,8,512);
            analogWrite(PINC,9,0);
        }
        if (ch == 's') {
            analogWrite(PINC,6,0);
            analogWrite(PINC,7,0);
            analogWrite(PINC,8,0);
            analogWrite(PINC,9,0);
        }
        
        if(ch == 'e'){
            analogWrite(PINC,6,256);
            analogWrite(PINC,7,0);
            analogWrite(PINC,8,512);
            analogWrite(PINC,9,0);
        }
        
        if(ch == 'q'){
            analogWrite(PINC,6,512);
            analogWrite(PINC,7,0);
            analogWrite(PINC,8,256);
            analogWrite(PINC,9,0);
        }
        
        if(ch == 'c'){
            analogWrite(PINC,6,0);
            analogWrite(PINC,7,256);
            analogWrite(PINC,8,0);
            analogWrite(PINC,9,512);
        }
        
        if(ch == 'z'){
            analogWrite(PINC,6,0);
            analogWrite(PINC,7,512);
            analogWrite(PINC,8,0);
            analogWrite(PINC,9,256);
        }

    }


}
