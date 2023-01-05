#define SWITCH_PIN  3

int switchRead;

void setup() {
    pinMode(SWITCH_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    switchRead = digitalRead(SWITCH_PIN);
    Serial.println(switchRead);
}
