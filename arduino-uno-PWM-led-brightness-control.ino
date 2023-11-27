
const int ledPin = 6; // Pin connected to the LED
int brightness = 0;   // Initial brightness level
int fadeAmount = 5;   // Amount to increment or decrement the brightness

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  // Increase brightness
  analogWrite(ledPin, brightness);

  // Change the brightness direction when limits are reached
  brightness += fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; // Reverse the direction
  }

  // Delay to control the speed of the fade
  delay(50); // You can adjust this value to change the fade speed
}
