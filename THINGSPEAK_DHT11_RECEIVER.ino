#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>   // Library for JSON parsing (install from Library Manager)


// ---------------- WiFi Credentials ----------------
const char* ssid = "vivo 1812";
const char* password = "abhi@123";


// ---------------- ThingSpeak Settings ----------------
String channelID = "3092881";        // Your ThingSpeak Channel ID
String readAPIKey = "OZCDNSYQWZVRSDX0";     // ThingSpeak Read API Key
String server = "http://api.thingspeak.com/channels/";


void setup() {
  Serial.begin(115200);


  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}


void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;


    // Construct URL to get latest entry in JSON format
    String url = server + channelID + "/feeds/last.json?api_key=" + readAPIKey;


    http.begin(url);
    int httpCode = http.GET();


    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("Received Data: " + payload);


      // Parse JSON response
      JSONVar data = JSON.parse(payload);


      if (JSON.typeof(data) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }


      String temperature = (const char*) data["field1"];
      String humidity    = (const char*) data["field2"];


      Serial.println("Latest Temperature: " + temperature + " °C");
      Serial.println("Latest Humidity: " + humidity + " %");
    }
    else {
      Serial.println("Error in HTTP request");
    }


    http.end();
  }
  else {
    Serial.println("WiFi Disconnected!");
  }


  delay(15000);  // Read every 15 seconds
}
