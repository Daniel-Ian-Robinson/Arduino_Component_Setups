const int BUZZER_PIN = 7;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    for (int frequency = 200; frequency < 1200; frequency++) {
        tone(BUZZER_PIN, frequency);
        delay(10);
    }
}
