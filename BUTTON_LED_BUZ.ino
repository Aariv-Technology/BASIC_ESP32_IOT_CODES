// led blink when button1 is pressed.
// Buzzer beep when button2 is pressed.
// both running when 2 buttons pressed together.

#define led 2
#define buzzer 4
#define button 12
#define button2 14

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button2, INPUT);
}

void loop() {
  int button1State = digitalRead(button);
  int button2State = digitalRead(button2);

  if(button1State == 0) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }

  if(button2State == 0) {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
}
