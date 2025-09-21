// turn on and off led with same button with debounce delay

#define led 2
#define button 4

int currentState = 0;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  int buttonState = digitalRead(button);

  if(buttonState == 0)
  {
    delay(200);                         // debounce delay
  }

  if(buttonState == 0 && currentState == 0)
  {
    digitalWrite(led, HIGH);
    currentState = 1;
  }
  else if(buttonState == 0 && currentState == 1)
  {
    digitalWrite(led, HIGH);
    currentState = 0;
  }

}
