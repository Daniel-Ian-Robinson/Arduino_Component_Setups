const int BUTTON_PIN = 12;
int buttonValue = 0;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    buttonValue = digitalRead(BUTTON_PIN);
    Serial.println(buttonValue);
}
