#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library

const char* ssid     = "Timbl_2.4G";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "9315622254";     // The password of the Wi-Fi network

void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println("................................");
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); 

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); 
    Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void loop() { 
  Serial.print(" Walla!...............");
  delay(5000);
}
