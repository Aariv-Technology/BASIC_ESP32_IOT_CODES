//Creating analog output using dac pin and measuring its adc value and calculating its equivalent voltage

#define dac 26    //ONLY GPIO25 OR GPIO26
#define adc 34

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(adc, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i<=255; i++)
  {
    dacWrite(dac,i);
    float adcValue = analogRead(adc);

    Serial.print("ADC Value = ");
    Serial.println(adcValue);

    float voltage = adcValue/4095*3.3;
    Serial.print("Voltage Value = ");
    Serial.println(voltage);

    delay(100);
  }
  delay(3000);
  for(int i=255; i>=0; i--)
  {
    dacWrite(dac,i);
    float adcValue = analogRead(adc);

    Serial.print("ADC Value = ");
    Serial.println(adcValue);

    float voltage = adcValue/4095*3.3;
    Serial.print("Voltage Value = ");
    Serial.println(voltage);

    delay(100);
  }

}
