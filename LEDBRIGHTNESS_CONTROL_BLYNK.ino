#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN  "YourAuthToken"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define led1 4
#define led2 5

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

int led1input = 0;
int led2input = 0;
int led1brightness = 0;
int led2brightness = 0;

BLYNK_WRITE(V0) {
  led1input = param.asInt();
}

BLYNK_WRITE(V1) {
  led2input = param.asInt();
}

BLYNK_WRITE(V2) {
  led1brightness = param.asInt();
}

BLYNK_WRITE(V3) {
  led2brightness = param.asInt();
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  Blynk.run();

  if (led1input == 1) {
    analogWrite(led1, led1brightness);
  } else {
    analogWrite(led1, 0);
  }

  if (led2input == 1) {
    analogWrite(led2, led1brightness);
  } else {
    analogWrite(led2, 0);
  }
}
