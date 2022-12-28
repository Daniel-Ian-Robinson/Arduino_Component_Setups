const int CLOCK_PIN = 5;
const int DATA_PIN = 6;

int prevVal = 0;
int curVal = 0;
int clockVal = 0;

void setup() {
    pinMode(CLOCK_PIN, INPUT);
    pinMode(DATA_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    prevVal = curVal;
    curVal = digitalRead(DATA_PIN);
    clockVal = digitalRead(CLOCK_PIN);

    Serial.println("curVal: " + (String)curVal);
    Serial.println("clockVal: " + (String)clockVal);

    delay(500);

    /*if (curVal == 1 && prevVal == 0) {
        if (clockVal == 1) {
            Serial.println("Clockwise Rotation");
        } else {
            Serial.println("Anti-clockwise Rotation");
        }
    }*/
}
