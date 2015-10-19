//Bluetooth
Serial3.begin(9600);

//GPIO
pinMode(2, 12, 1);
pinMode(2, 13, 1);
pinMode(2, 14, 1);
pinMode(2, 15, 1);


while (1) {
    while (Serial3.available()) {
        var ch = Serial3.read();
        if (ch == 'x') {
            digitalWrite(2, 12, 1);
            digitalWrite(2, 13, 0);
            digitalWrite(2, 14, 1);
            digitalWrite(2, 15, 0);
        }
        if (ch == 'w') {
            digitalWrite(2, 12, 0);
            digitalWrite(2, 13, 1);
            digitalWrite(2, 14, 0);
            digitalWrite(2, 15, 1);
        }
        if (ch == 'd') {
            digitalWrite(2, 12, 0);
            digitalWrite(2, 13, 1);
            digitalWrite(2, 14, 0);
            digitalWrite(2, 15, 0);
        }
        if (ch == 'a') {
            digitalWrite(2, 12, 0);
            digitalWrite(2, 13, 0);
            digitalWrite(2, 14, 0);
            digitalWrite(2, 15, 1);
        }
        if (ch == 's') {
            digitalWrite(2, 12, 0);
            digitalWrite(2, 13, 0);
            digitalWrite(2, 14, 0);
            digitalWrite(2, 15, 0);
        };

    }


}
