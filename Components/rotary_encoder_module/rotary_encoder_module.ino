// Rotary Encoder Inputs
#define CLK_PIN 2
#define DT_PIN  3
#define SW_PIN  4

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;

void setup() {
    pinMode(CLK_PIN, INPUT);
    pinMode(DT_PIN, INPUT);
    pinMode(SW_PIN, INPUT_PULLUP);

    lastStateCLK = digitalRead(CLK_PIN);

    Serial.begin(9600);
}

void loop() {
    
    // Read the current state of CLK
    currentStateCLK = digitalRead(CLK_PIN);

    // If last and current state of CLK are different, then pulse occurred
    // React to only 1 state change to avoid double count
    if (currentStateCLK != lastStateCLK){

        // If the DT state is different than the CLK state then
        // the encoder is rotating CCW so decrement
        if (digitalRead(DT_PIN) != currentStateCLK) {
            counter --;
            currentDir ="Anti-Clockwise";
        } else {
            // Encoder is rotating CW so increment
            counter ++;
            currentDir ="Clockwise";
        }

        Serial.println((String)counter + "\t" + currentDir);
    }

    // Remember last CLK state
    lastStateCLK = currentStateCLK;

    // Read the button state
    int btnState = digitalRead(SW_PIN);

    //If we detect LOW signal, button is pressed
    if (btnState == LOW) {
        //if 50ms have passed since last LOW pulse, it means that the
        //button has been pressed, released and pressed again
        if (millis() - lastButtonPress > 50) {
            Serial.println("Button Pressed");
        }

        // Remember last button press event
        lastButtonPress = millis();
    }

    // Put in a slight delay to help debounce the reading
    delay(1);
}
