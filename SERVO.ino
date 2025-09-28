//Rotating Servo from 0 to 180 degree and then from 180 to 0 degree

#include <ESP32Servo.h>

#define servoPin 14

Servo myservo;

void setup() {

  	ESP32PWM::allocateTimer(0); // Allow allocation of timer
    myservo.setPeriodHertz(50); // standard 50 hz servo
    myservo.attach(servoPin, 500, 2400);
    myservo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
	for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(15);             // waits 15ms for the servo to reach the position
	}
	for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(15);             // waits 15ms for the servo to reach the position
	}
  

}
