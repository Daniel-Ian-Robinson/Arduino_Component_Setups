# Contents

- [Active Buzzer Module](#active-buzzer-module)
- [Button](#button)
- [Button Module](#button-module)
- [Joystick Module](#joystick-module)
- [LED](#led)
- [Passive Buzzer Module](#passive-buzzer-module)
- [Photoresistor](#photoresistor)
- [Potentiometer](#potentiometer)
- [RGB LED Module](#rgb-led-module)
- [SSD1331 OLED Display](#ssd1331-oled-display)

## Active Buzzer Module

A buzzer which either buzzes or stays silent.

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

A simple up/down button.

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

const int PHOTORESISTOR_PIN = A0;
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

## SMD RGB Module

A light that displays a colour based on the inputted Red, Green, and Blue values.

![SMD RGB Module Schematic](/Components/smd_rgb_module/Schematic_bb.png)

```../Components/smd_rgb_module/smd_rgb_module.ino

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

```../Components/ssd1331_oled_display/ssd1331_oled_display.ino

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
#define RED     0xF800
#define GREEN   0x07E0
#define BLUE    0x001F

Adafruit_SSD1331 display = Adafruit_SSD1331(CS_PIN, DC_PIN, RES_PIN);

void setup() {
    display.begin();

    // Draw text.
    display.fillScreen(BLACK);
    display.setCursor(0, 0);
    display.print("Hello world!");
    delay(3000);

    // Draw pixels.
    display.fillScreen(BLACK);
    for (int i = 0; i < 30; i++) {
        int xVal = random(0, SCREEN_WIDTH);
        int yVal = random(0, SCREEN_HEIGHT);
        display.drawPixel(xVal, yVal, WHITE);
        delay(100);
    }

    // Draw lines.
    display.fillScreen(BLACK);
    display.drawLine(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, RED);
    delay(300);
    display.drawLine(20, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, RED);
    delay(300);
    display.drawLine(0, 20, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, RED);
    delay(3000);

    // Draw empty rectangle.
    display.fillScreen(BLACK);
    display.drawRect(15, 15, 30, 30, GREEN);
    delay(3000);
    
    // Draw filled rectangle.
    display.fillScreen(BLACK);
    display.fillRect(15, 15, 30, 30, GREEN);
    delay(3000);
    
    // Draw circle.
    display.fillScreen(BLACK);
    display.drawCircle(SCREEN_WIDTH / 2 - 1, SCREEN_HEIGHT / 2 - 1, 30, BLUE);
    delay(3000);
}

void loop() {}

```
