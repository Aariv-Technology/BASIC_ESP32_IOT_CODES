#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN  "YourAuthToken"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define soilSensor 34
#define relay 4

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

int autoMode = 0;
int manualMode = 1;
int relayValue = 0;

BLYNK_WRITE(V0) {
  int mode = param.asInt();
  if (mode == 0) {
    manualMode = 1;
    autoMode = 0;
  } else {
    autoMode = 1;
    manualMode = 0;
  }
}

BLYNK_WRITE(V1) {
  relayValue = param.asInt();
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(soilSensor, INPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  Blynk.run();
  int sensorValue = analogRead(soilSensor);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  int percentage = map(sensorValue, 0, 4095, 100, 0);
  Serial.print("Percentage: ");
  Serial.println(percentage);
  delay(100);

  if(autoMode == 1) {
    if (percentage < 10) {
      digitalWrite(relay, HIGH);
    }
    if (percentage > 45) {
      digitalWrite(relay, LOW);
    }
  }

  if(manualMode == 1)
  {
    if(relayValue == 1)
    {
      digitalWrite(relay, HIGH);
    }
    else
    {
      digitalWrite(relay, LOW);
    }
  }
}
