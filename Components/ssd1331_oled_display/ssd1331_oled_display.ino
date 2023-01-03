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
