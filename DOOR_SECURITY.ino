#include <ESP32Servo.h>

#define trig 26
#define echo 18
#define servoPin 14
#define irSensor 4

Servo myservo;

void setup() {
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(irSensor, INPUT);
  ESP32PWM::allocateTimer(0);  // Allow allocation of timer
  myservo.setPeriodHertz(50);  // standard 50 hz servo
  myservo.attach(servoPin, 500, 2400);
  myservo.write(0);
}

void loop() {

  String password;

  if (Serial.available()) {
    password = Serial.readStringUntil('\n');
    Serial.print("Password: ");
    Serial.println(password);
  }

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int duration = pulseIn(echo, HIGH);

  float distance = 0.0343 * duration / 2;
  Serial.print("Distance = ");
  Serial.println(distance);

  if ((password == "1234") && (distance <=10)) {
    myservo.write(180);
    while(digitalRead(irSensor)!=0)
    {

    }
    myservo.write(0);
  }

delay(300);
}
