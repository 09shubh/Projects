#define MLa 4   // left motor 1st pin
#define MLb 5   // left motor 2nd pin
#define MRa 6   // right motor 1st pin
#define MRb 7   // right motor 2nd pin

char command; // Stores the received command from Bluetooth

void setup()
{
  Serial.begin(9600); // Initialize the built-in UART for serial communication
  pinMode(MLa, OUTPUT);   // left motors forward
  pinMode(MLb, OUTPUT);   // left motors reverse
  pinMode(MRa, OUTPUT);   // right motors forward
  pinMode(MRb, OUTPUT);   // right motors reverse
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
   analogWrite(8, 90);
  analogWrite(9, 90);
}

void loop()
{

  if (Serial.available() > 0)
  {
    command = Serial.read(); // Read the received command from Bluetooth

    // Process the received command
    switch (command)
    {
      case 'F': // Move forward
        forward();
        break;

      case 'B': // Move backward
        backward();
        break;

      case 'L': // Turn left
        left();
        break;

      case 'R': // Turn right
        right();
        break;

      case 'S': // Stop
        stop();
        break;

      default:
        break;
    }
  }
}

// Function to move the car forward
void forward()
{
  digitalWrite(MLa, HIGH);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
}

// Function to move the car backward
void backward()
{
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, HIGH);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, HIGH);
}

// Function to turn the car left
void left()
{
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
}

// Function to turn the car right
void right()
{
  digitalWrite(MLa, HIGH);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
}

// Function to stop the car
void stop()
{
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
}
