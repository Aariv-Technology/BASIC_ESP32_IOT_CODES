Measuring distance in cm using ultrasonic sensor HCSR04

#define trig 26
#define echo 18

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int duration = pulseIn(echo,HIGH);

  float distance = 0.0343*duration/2;
  Serial.print("Distance = ");
  Serial.println(distance);
  delay(10);
}
