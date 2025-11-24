#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

#define DHTPIN 4       // DHT11 data pin
#define DHTTYPE DHT11  // DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

// Wi-Fi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Handle root page
void handleRoot() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  String html = "<!DOCTYPE html><html><head>";
  html += "<meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";  // Auto-refresh every 5 sec
  html += "<title>DHT11 Data</title></head>";
  html += "<body style='text-align:center; font-size:30px; margin-top:20%;'>";
  html += "Temperature: " + String(temp) + " &deg;C<br>";
  html += "Humidity: " + String(hum) + " %";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
}
