## Button

Detects whether the button is being pressed or not.

![Button Schematic](/Components/button/Schematic_bb.png)

```../Components/button/button.ino

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

```

## Passive Buzzer Module

Emits sound at a given frequency.

![Passive Buzzer Module Schematic](/Components/passive_buzzer_module/Schematic_bb.png)

```../Components/passive_buzzer_module/passive_buzzer_module.ino

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

## Potentiometer

Reads the potentiometer knob's value which is in the range [0, 1023].

![Potentiometer Schematic](/Components/potentiometer/Schematic_bb.png)

```../Components/potentiometer/potentiometer.ino

const int POT_PIN = A0;
int potVal = 0;

void setup() {
    pinMode(POT_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    potVal = analogRead(POT_PIN);
    Serial.println(potVal);
}

```
