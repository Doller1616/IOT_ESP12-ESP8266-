// ESP8266 (NodeMCU 0.9/ESP-12)
// GET, POST Request with JSON Parser (Using ArduinoJson v6)

#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

WiFiClient wifiClient;

void setup() {
   // -------------------Wifi/Internet Connection ---------------------------------
  Serial.begin(115200);
  WiFi.begin("Oscars", "abhi1abhi");
  Serial.print("Connecting");
  // Waiting to be connected to the internet
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  // ------------------Wifi/Internet Connection End -------------------------------

}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    // -----------------Hitting API----------------------------
    http.begin(wifiClient, "http://jsonplaceholder.typicode.com/posts");
    //  http.begin(wifiClient, "http://esp8266socketserver.herokuapp.com/");

    int httpCode = http.POST("{\"name\":\"Vijay\"}");
    //  int httpCode = http.GET();
    String response = http.getString();
    // -----------------Hitting API End------------------------


    // ----------------- JSON parse ---------------------------
    DynamicJsonDocument doc(1024);

    DeserializationError error = deserializeJson(doc, response);
    if (error) return;

    int value = doc["id"];
    Serial.printf("\nResponse:  %d", value);
    // ---------------JSON parse end --------------------------

    http.end();

  } else {
    Serial.println("Error in WiFi connection");
  }

  delay(30000);
}