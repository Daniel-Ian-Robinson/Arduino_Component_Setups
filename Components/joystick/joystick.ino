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
