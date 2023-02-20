const int fFI1 = 2;
const int fFR1 = 3;
const int fFI2 = 4;
const int fFR2 = 5;
const int fFI3 = 6;
const int fFR3 = 7;
const int enableOutput1 = 8;
const int enableOutput2 = 9;
const int enableOutput3 = 10;

void setup(){
    Serial.begin(115200);
    pinMode(fFI1, INPUT);
    pinMode(fFR1, OUTPUT);
    pinMode(enableOutput1, OUTPUT);
    pinMode(fFI2, INPUT);
    pinMode(fFR2, OUTPUT);
    pinMode(enableOutput2, OUTPUT);
    pinMode(fFI3, INPUT);
    pinMode(fFR3, OUTPUT);
    pinMode(enableOutput3, OUTPUT);
}

void loop(){
    const int fFI1Read = digitalRead(fFI1);
    const int fFI2Read = digitalRead(fFI2);
    const int fFI3Read = digitalRead(fFI3);
    
    if(fFI1Read == 1 && fFI2Read == 0 && fFI3Read == 0){
        Serial.println("Output 1 ::: ON");
        digitalWrite(enableOutput1, HIGH);
        digitalWrite(enableOutput2, LOW);
        digitalWrite(enableOutput3, LOW);
        digitalWrite(fFR1, LOW);
        digitalWrite(fFR2, HIGH);
        digitalWrite(fFR3, HIGH);
        delay(1000);
    } else if(fFI1Read == 0 && fFI2Read == 1 && fFI3Read == 0){
        Serial.println("Output 2 ::: ON");
        digitalWrite(enableOutput1, LOW);
        digitalWrite(enableOutput2, HIGH);
        digitalWrite(enableOutput3, LOW);
        digitalWrite(fFR1, HIGH);
        digitalWrite(fFR2, LOW);
        digitalWrite(fFR3, HIGH);
        delay(1000);

    } else if(fFI1Read == 0 && fFI2Read == 0 && fFI3Read == 1){
        Serial.println("Output 3 ::: ON");
        digitalWrite(enableOutput1, LOW);
        digitalWrite(enableOutput2, LOW);
        digitalWrite(enableOutput3, HIGH);
        digitalWrite(fFR1, HIGH);
        digitalWrite(fFR2, HIGH);
        digitalWrite(fFR3, LOW);
        delay(1000);

    } else {
        Serial.println("Outputs ::: OFF");
        digitalWrite(enableOutput1, LOW);
        digitalWrite(enableOutput2, LOW);
        digitalWrite(enableOutput3, LOW);
        delay(1000);
        
    }
}