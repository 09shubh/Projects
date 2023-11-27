#include <WiFi.h>
#include <Espalexa.h>
#include <Adafruit_NeoPixel.h>

#define RGB_PIN_RED    15  // D15
#define RGB_PIN_GREEN  2   // D2
#define RGB_PIN_BLUE   4   // D4
#define RGB_LED_COUNT  1   // Number of RGB LEDs

#define wifiLed        13  // D13

Adafruit_NeoPixel rgbLed = Adafruit_NeoPixel(RGB_LED_COUNT, RGB_PIN_RED, NEO_GRB + NEO_KHZ800);
Espalexa espalexa;

// WiFi Credentials
const char* ssid = "RNDROBOKART";
const char* password = "ROBOKART@321";

// Device name for Alexa
String Device_RGB_Name = "RGB LED";

boolean wifiConnected = false;

void connectWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void setColor(uint8_t red, uint8_t green, uint8_t blue) {
  rgbLed.fill(rgbLed.Color(red, green, blue), 0, RGB_LED_COUNT);
  rgbLed.show();
}

void rgbLightChanged(uint8_t brightness) {
  // Convert brightness (0-255) to RGB values
  uint8_t red = map(brightness, 0, 255, 0, 255);
  uint8_t green = map(brightness, 0, 255, 0, 255);
  uint8_t blue = map(brightness, 0, 255, 0, 255);
  
  setColor(red, green, blue);
}

void addDevices() {
  espalexa.addDevice(Device_RGB_Name, rgbLightChanged);
  espalexa.begin();
}

void setup() {
  Serial.begin(115200);

  pinMode(wifiLed, OUTPUT);

  // Connect to WiFi
  connectWiFi();

  // Initialize RGB LED
  rgbLed.begin();
  rgbLed.setBrightness(50); // Set brightness (0 to 255)

  // Set initial color (White)
  setColor(255, 255, 255);

  // Connect to Alexa
  if (WiFi.status() == WL_CONNECTED) {
    addDevices();
    wifiConnected = true;
  }
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifiLed, LOW);
  } else {
    digitalWrite(wifiLed, HIGH);

    if (wifiConnected) {
      espalexa.loop();
    } else {
      wifiConnected = true;
      addDevices();
    }
  }
}
