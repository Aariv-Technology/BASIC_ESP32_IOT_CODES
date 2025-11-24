#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN  "YourAuthToken"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
