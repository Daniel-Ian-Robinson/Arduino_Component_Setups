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
