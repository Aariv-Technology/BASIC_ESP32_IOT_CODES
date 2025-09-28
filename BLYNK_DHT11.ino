
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN  "YourAuthToken"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";     // change this
char pass[] = "YourWiFiPassword"; // change this

#define DHTPIN 4       // DHT11 data pin
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

// Function to send sensor data
void sendSensor() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V1, temp);  // Send temp to Blynk on V1
  Blynk.virtualWrite(V2, hum);   // Send humidity on V2

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C  Hum: ");
  Serial.print(hum);
  Serial.println(" %");
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  Blynk.begin(auth, ssid, pass);

  // Run sendSensor() every 2 seconds
  timer.setInterval(2000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}

