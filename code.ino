const int s0 = 1; // this is the key switch thingy
const int s1 = 2; // this is the toggle switch
const int s2 = 3; // this is the power button 
const int LED = 13; // Blinker LEDs for visuals 
const int Switch = 4; // this could be a relay that would connect to your pc power button header pins

int ledStd = LOW;
unsigned long vrgMillis = 0;
const long INT = 500;

void setup() {
  pinMode(s0, INPUT_PULLUP);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(Switch, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int s0std = digitalRead(s0);
  int s1std = digitalRead(s1);
  int s2std = digitalRead(s2);
  bool allowS2 = false;
  
  if (s0std == LOW && s1std == LOW) { //s0 is the key thingy and s1 is the toggle switch, so this part checks if the key switch AND the toggle switch pins are pulled low, if so blink the LEDs.
    unsigned long hdgMillis = millis();
    if (hdgMillis - vrgMillis >= INT) {
      vrgMillis = hdgMillis;
      if (ledStd == LOW) {
        ledStd = HIGH;
      } else {
        ledStd = LOW;
      }
      digitalWrite(LED, ledStd);
    }
    allowS2 = true; // while those pins are pulled high, we set this boolean to true so we can allow the use of s2 for in the next if statement.

  } else {
    ledStd = LOW;
    digitalWrite(LED, LOW);
  }

  if (allowS2 == true && s2std == LOW) {
    digitalWrite(Switch, HIGH);

  } else {
    digitalWrite(Switch, LOW);
  }
}
