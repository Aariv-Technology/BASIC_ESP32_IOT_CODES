// Wifi Station Mode

#include <WiFi.h>

#define led 2

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(led, LOW);
  }
  Serial.println("\nConnected!");
  digitalWrite(led, HIGH);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
