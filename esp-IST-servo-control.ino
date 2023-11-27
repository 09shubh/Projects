#include <Servo.h>
Servo servo;

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

// Replace with your network credentials
const char* ssid = "RNDROBOKART";
const char* password = "ROBOKART@321";

// NTP settings for IST
const char* ntpServer = "in.pool.ntp.org";
const long  gmtOffset = 19800;  // GMT+5:30 for IST
const int   daylightOffset = 0;

// Define NTP Client
WiFiUDP udpClient;
NTPClient timeClient(udpClient, ntpServer, gmtOffset, daylightOffset);

void setup() {
  // Start serial communication
  Serial.begin(115200);
  servo.attach(0);     //pin D3 = GPIO 0

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize NTP Client
  timeClient.begin();
  timeClient.update();
  
  servo.write(0);
  delay(10);
  Serial.println("Setup complete");


}

void loop() {
  // Update NTP Client
  timeClient.update();

  // Get the current time
  unsigned long epochTime = timeClient.getEpochTime();
  String formattedTime = timeClient.getFormattedTime();

  // Display current time on serial monitor
  Serial.println("Epoch Time: " + String(epochTime));
  Serial.println("Formatted Time: " + formattedTime);

  delay(10000); // Update every 10 seconds

if (formattedTime.substring(0, 2).toInt() == 12 && formattedTime.substring(3, 5).toInt() == 40) {
  servo.write(90);
  delay(10000);
  servo.write(0);
}

}
