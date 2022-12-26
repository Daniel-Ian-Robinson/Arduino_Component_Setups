## Passive Buzzer Module

This module emits sound at a given frequency.

![Passive Buzzer Module Schematic](/Components/passive_buzzer_module/Schematic_bb.png)

```.ino
const int BUZZER_PIN = 7;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    for (int frequency = 250; frequency <= 2000; frequency += 250) {
        tone(BUZZER_PIN, frequency);
        delay(1000);
        noTone(BUZZER_PIN);
        delay(500);
    }
}

```
