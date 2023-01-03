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
            counter --;
            currentDir = "Anti-Clockwise";
        } else {
            counter ++;
            currentDir = "Clockwise";
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
