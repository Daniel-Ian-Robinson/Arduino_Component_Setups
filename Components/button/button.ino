const int BUTTON_PIN = 12;
int buttonValue = 0;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    buttonValue = digitalRead(BUTTON_PIN);
    
    if (buttonValue == 1) {
        Serial.println("Button Unpressed");
    } else if (buttonValue == 0) {
        Serial.println("Button Pressed");
    }
}
