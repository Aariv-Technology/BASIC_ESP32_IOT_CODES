// led ON when button pressed and off when not pressed

#define led 2
#define button 4

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  int buttonState = digitalRead(button);
  if (buttonState == 0) {                 //Reads 0 when pressed due to pullup
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
