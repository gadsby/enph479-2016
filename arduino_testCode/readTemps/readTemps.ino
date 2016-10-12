
// Test Suite v1

int temp1_pin = A0;

double rawTemp;
double temp1;

// Setup
void setup() {
    Serial.begin(9600);
    Serial.println("Temperature (C)");
}

// Main Loop
void loop() {
    rawTemp = analogRead(temp1_pin);
    temp1 = (rawTemp * 5.0/1023) * 100.0;
    Serial.println(temp1);
    delay(500);
}


