const int THERMISTOR_PIN = A0;
int thermistorValue = 0;

void setup() {
    pinMode(THERMISTOR_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    thermistorValue = analogRead(THERMISTOR_PIN);
    Serial.println(thermistorValue);
}
