int irPin = 5;      // IR sensor connected to digital pin 5
int ledPin = 13;    // LED connected to digital pin 13
int previousState = LOW;  // Stores the previous state of the IR sensor

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int currentState = digitalRead(irPin);

  // Check if the state of the IR sensor has changed
  if (currentState != previousState) {
    if (currentState == HIGH) {
      digitalWrite(ledPin, !digitalRead(ledPin));  // Toggle the LED state
    }
    previousState = currentState;
    delay(100);  // Debounce delay to avoid rapid toggling due to sensor noise
  }
}
