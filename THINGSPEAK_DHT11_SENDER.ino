#include <WiFi.h>
#include "DHT.h"
#include "HTTPClient.h"


// ---------------- WiFi Credentials ----------------
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";


// ---------------- ThingSpeak Settings ----------------
String apiKey = "YOUR_API_KEY";   // Write API Key from ThingSpeak
const char* server = "http://api.thingspeak.com/update";


// ---------------- DHT Sensor ----------------
#define DHTPIN 4       // GPIO4 connected to DHT sensor data pin
#define DHTTYPE DHT11  // Change to DHT22 if using DHT22
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(115200);
  dht.begin();


  // Connect to Wi-Fi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}


void loop() {
  // Read data from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();  // Celsius


  // Check if reading is valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");


  // Upload data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(server) + "?api_key=" + apiKey + "&field1=" + String(temperature) + "&field2=" + String(humidity);


    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.println("Data uploaded to ThingSpeak successfully!");
    } else {
      Serial.println("Error in uploading data.");
    }
    http.end();
  }


  delay(15000);  // ThingSpeak requires minimum 15 sec delay between updates
}
