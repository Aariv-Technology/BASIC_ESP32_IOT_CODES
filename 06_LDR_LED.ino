// TURN ON LED WHEN ROOM IS DARK.. TURN OFF LED WHEN ROOM IS BRIGHT

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
 
 if(ldrValue >= 2047)
 {
  digiatalWrite(led,HIGH);
 }
 else{
  digiatalWrite(led,LOW);
 }

}
