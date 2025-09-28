#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  // Start Access Point
  WiFi.softAP("Abhi", "12345678");
  Serial.print("AP started, IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  static int lastCount = 0;
  int count = WiFi.softAPgetStationNum();   // number of connected devices

  if (count != lastCount) {
    Serial.print("Connected devices: ");
    Serial.println(count);
    lastCount = count;
  }

  delay(1000);
}
