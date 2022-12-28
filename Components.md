## Active Buzzer Module

A simple on/off buzzer.

![Active Buzzer Module Schematic](/Components/active_buzzer_module/Schematic_bb.png)

```../Components/active_buzzer_module/active_buzzer_module.ino

const int BUZZER_PIN = 7;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZER_PIN, LOW);
    delay(1000);
}

```

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

## Joystick Module

Receives the following joystick input:

- A value in the range [0, 1023] representing the joystick's position on the x-axis.
- A value in the range [0, 1023] representing the joystick's position on the y-axis.
- 0 if the button is not pressed or 1 if the button is pressed.

![Joystick Module Schematic](/Components/joystick_module/Schematic_bb.png)

```../Components/joystick_module/joystick_module.ino

const int X_AXIS_PIN = A0;
const int Y_AXIS_PIN = A1;
const int BUTTON_PIN = 6;
int xAxisVal = 0;
int yAxisVal = 0;
int buttonVal = 0;

void setup() {   
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT);
    digitalWrite(BUTTON_PIN, HIGH);
}

void loop() {
    xAxisVal = analogRead(X_AXIS_PIN);
    yAxisVal = analogRead(Y_AXIS_PIN);
    buttonVal = !digitalRead(BUTTON_PIN);
    Serial.println((String)xAxisVal + "\t" + (String)yAxisVal + "\t" + (String)buttonVal);
}

```

## LED

A single-colour LED.

![LED Schematic](/Components/led/Schematic_bb.png)

```../Components/led/led.ino

const int LED_PIN = 12;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
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

## Photoresistor

Detects the brightness of the environment and reports it in the range [0, 1023] where 0 is the darkest measurement and 1023 is the brightest measurement.

![Photoresistor Schematic](/Components/photoresistor/Schematic_bb.png)

```../Components/photoresistor/photoresistor.ino

const int PHOTORESISTOR_PIN = A5;
int photoresistorVal = 0;

void setup() {
    Serial.begin(9600);
    pinMode(PHOTORESISTOR_PIN, INPUT);
}

void loop() {
    photoresistorVal = analogRead(PHOTORESISTOR_PIN);
    Serial.println(photoresistorVal);
    delay(10);
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

## RGB LED Module

An LED that displays a colour based on the inputted Red, Green, and Blue values.

![RGB LED Module Schematic](/Components/rgb_led_module/Schematic_bb.png)

```../Components/rgb_led_module/rgb_led_module.ino

const int RED_PIN = 3;
const int GREEN_PIN = 5;
const int BLUE_PIN = 6;

void setup() {}

void loop() {
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    delay(1000);
    
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 0);
    delay(1000);
    
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 255);
    delay(1000);
}

```
