#define pot 34

void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
}

void loop() {
  int potValue = analogRead(pot);  //Reading Potentiometer Value (0-4095)
  Serial.println(potValue);
  delay(200);
}
