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
