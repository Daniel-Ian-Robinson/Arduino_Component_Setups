const int PHOTORESISTOR_PIN = A0;
int photoresistorVal = 0;

void setup() {
    Serial.begin(9600);
    pinMode(PHOTORESISTOR_PIN, INPUT);
}

void loop() {
    photoresistorVal = analogRead(PHOTORESISTOR_PIN);
    Serial.println(photoresistorVal);
}
