// MUX CODE -- TEST SUITE V2


void setMuxState(int temp_index);

int readMux_pin = A0;
int muxControl_pins[3] = {5,6,7}; //{a,b,c}, lowest to highest
int temps_muxStates[2] = {0,1};

float rawRead;
float temps[2];


// Setup
void setup() {
    Serial.begin(9600);
    Serial.println("Temperature (C)");

    for (int i = 0; i < 3; i++){
        pinMode(muxControl_pins[i], OUTPUT);
    }

}

// Main Loop
void loop() {
    for (int i = 0; i < 2; i++){
        setMuxState(temps_muxStates[i]);
        rawRead=analogRead(readMux_pin);
        temps[i] = (rawRead * 3.3/1023) * 100.0;
        Serial.print(i);
        Serial.print(": ");
        Serial.print(temps[i]);
        Serial.print("\n");
        delay(500);
    }

    Serial.println();


    delay(500);
}



void setMuxState(int temp_index){

    for (int i = 0; i < 3; i++){
        if ((temp_index >> i) & 1 == 1){
            digitalWrite(muxControl_pins[i], HIGH);
        } else {
            digitalWrite(muxControl_pins[i], LOW);
        }
    }
}