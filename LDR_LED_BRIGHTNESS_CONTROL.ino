// LED BRIGHTNESS CONTROL BASED ON LDR VALUE

#define ldr 34
#define led 18

void setup() {
  Serial.begin(9600);
  pinMode(ldr,INPUT); 
  pinMode(led,OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldr);
  Serial.print("ldr Value = ");
  Serial.println(ldrValue);

  int brightness = map(ldrValue, 0, 4095, 0, 255);

  analogWrite(led, brightness);

}
