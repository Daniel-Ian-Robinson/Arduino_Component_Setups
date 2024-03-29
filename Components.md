# Contents

- [Active Buzzer Module](#active-buzzer-module)
- [Button](#button)
- [Button Module](#button-module)
- [Joystick Module](#joystick-module)
- [Light Cup Module](#light-cup-module)
- [Passive Buzzer Module](#passive-buzzer-module)
- [Photoresistor](#photoresistor)
- [Potentiometer](#potentiometer)
- [RGB LED Module](#rgb-led-module)
- [Rotary Encoder Module](#rotary-encoder-module)
- [Single-Colour LED](#single-colour-led)
- [SMD RGB Module](#smd-rgb-module)
- [SSD1331 OLED Display](#ssd1331-oled-display)

## Active Buzzer Module

A single-frequency buzzer.

![Active Buzzer Module Schematic](/Components/active_buzzer_module/Schematic_bb.png)

```.ino

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

A simple up/down button.

![Button Schematic](/Components/button/Schematic_bb.png)

```.ino

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

```

## Button Module

A simple up/down button.

![Button Module Schematic](/Components/button_module/Schematic_bb.png)

```.ino

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

```

## Joystick Module

A joystick similar to that on a PlayStation 2 Controller which outputs the following:

- A value in the range [0, 1023] representing the joystick's position on the x-axis.
- A value in the range [0, 1023] representing the joystick's position on the y-axis.
- 0 if the button is not pressed or 1 if the button is pressed.

![Joystick Module Schematic](/Components/joystick_module/Schematic_bb.png)

```.ino

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

## Light Cup Module

A binary tilt sensor coupled with an LED.

![Light Cup Module Schematic](/Components/light_cup_module/Schematic_bb.png)

```.ino

#define LED_PIN     6
#define SWITCH_PIN  7

int switchRead;

void setup() {
    pinMode(LED_PIN, OUTPUT); 
    pinMode(SWITCH_PIN, INPUT);
}

void loop() {
    switchRead = digitalRead(SWITCH_PIN);
    
    if (switchRead == HIGH) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}

```

## Passive Buzzer Module

Emits sound at a given frequency.

![Passive Buzzer Module Schematic](/Components/passive_buzzer_module/Schematic_bb.png)

```.ino

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

```

## Photoresistor

Measures the environment's brightness using a value in the range [0, 1023] where 0 is the darkest measurement and 1023 is the brightest measurement.

![Photoresistor Schematic](/Components/photoresistor/Schematic_bb.png)

```.ino

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

```

## Potentiometer

A knob with physical lower and upper bounds. It outputs the knob's position using a value in the range [0, 1023].

![Potentiometer Schematic](/Components/potentiometer/Schematic_bb.png)

```.ino

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

An LED that displays a colour based on the inputted red, green, and blue values.

![RGB LED Module Schematic](/Components/rgb_led_module/Schematic_bb.png)

```.ino

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

## Rotary Encoder Module

A knob which turns in distinct physical increments either clockwise or anti-clockwise. It has no limit on how many times it can be turned in a given direction. It can also be pressed down which activates a button.

![Rotary Encoder Module Schematic](/Components/rotary_encoder_module/Schematic_bb.png)

```.ino

#define CLK_PIN 2
#define DT_PIN  3
#define SW_PIN  4

int counter = 0;
int curClockState;
int lastClockState;
String currentDir = "";
unsigned long lastButtonPressTime = 0;

void setup() {
    pinMode(CLK_PIN, INPUT);
    pinMode(DT_PIN, INPUT);
    pinMode(SW_PIN, INPUT_PULLUP);
    
    lastClockState = digitalRead(CLK_PIN);
    
    Serial.begin(9600);
}

void loop() {
    curClockState = digitalRead(CLK_PIN);

    if (curClockState != lastClockState) {
        if (digitalRead(DT_PIN) != curClockState) {
            counter++;
            currentDir = "Clockwise";
        } else {
            counter--;
            currentDir = "Anti-Clockwise";
        }

        Serial.println((String)counter + "\t" + currentDir);
    }

    lastClockState = curClockState;

    int buttonState = digitalRead(SW_PIN);
    
    if (buttonState == LOW) {
        if (millis() - lastButtonPressTime > 50) {
            Serial.println("Button Pressed");
        }

        lastButtonPressTime = millis();
    }
    
    delay(1);
}

```

## Single-Colour LED

A single-colour LED.

![LED Schematic](/Components/single_colour_led/Schematic_bb.png)

```.ino

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

## SMD RGB Module

A light that displays a colour based on inputted red, green, and blue values.

![SMD RGB Module Schematic](/Components/smd_rgb_module/Schematic_bb.png)

```.ino

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

## SSD1331 OLED Display

A fully controllable 96x64 pixel OLED display.

![SSD1331 OLED Display Schematic](/Components/ssd1331_oled_display/Schematic_bb.png)

```.ino

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

#define SCL_PIN 13
#define SDA_PIN 11
#define CS_PIN  10
#define RES_PIN 9
#define DC_PIN  8

#define SCREEN_WIDTH    96
#define SCREEN_HEIGHT   64

#define BLACK   0x0000
#define WHITE   0xFFFF

Adafruit_SSD1331 display = Adafruit_SSD1331(CS_PIN, DC_PIN, RES_PIN);

void setup() {
    display.begin();

    display.fillScreen(BLACK);
    display.setCursor(15, 25);
    display.println("Hello world!");
    delay(3000);

    display.fillScreen(BLACK);
    for (int i = 0; i < 120; i++) {
        int xVal = random(0, SCREEN_WIDTH);
        int yVal = random(0, SCREEN_HEIGHT);
        int colour = random(BLACK, WHITE);
        display.drawPixel(xVal, yVal, colour);
        delay(50);
    }
}

void loop() {}

```
