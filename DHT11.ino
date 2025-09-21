#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(DHTPIN, INPUT);
  dht.begin();
}

void loop() {

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println(" c");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");
  delay(2000);
}
