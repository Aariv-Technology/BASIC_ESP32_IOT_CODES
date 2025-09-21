// LED Brightness control usign pwm

#define pwmLed 18

void setup() {
  // put your setup code here, to run once:
  pinMode(pwmLed, OUTPUT);
  analogWriteFrequency(pwmLed, 1000);
  analogWriteResolution(pwmLed, 12);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 4095; i++) {
    analogWrite(pwmLed, i);
    delay(30);
  }
  for (int i = 4095; i >= 0; i--) {
    analogWrite(pwmLed, i);
    delay(30);
  }
}
