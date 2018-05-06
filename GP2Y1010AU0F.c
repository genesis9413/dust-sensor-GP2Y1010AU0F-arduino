// dust sensor pin number
int dustPin=0;
// UV led pin number
int ledPower=2;

// sampling interval
int delayTime=280;
int delayTime2=40;
float offTime=9680;

// analog value
float voMeasured = 0;
// voltage
float calcVoltage = 0;
// result
float pm10 = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
  pinMode(4, OUTPUT);
}
 
void loop(){
  digitalWrite(ledPower,LOW); // power on the UV LED
  delayMicroseconds(delayTime);

  //dustVal=analogRead(dustPin); 
  voMeasured = analogRead(dustPin); // read the analog value
  delayMicroseconds(delayTime2);

  digitalWrite(ledPower,HIGH); // power off the UV LED
  delayMicroseconds(offTime);
  
  // voltage calc
  calcVoltage = voMeasured * (3.3 / 1024);
  // pm10 calc
  pm10 = 0.17 * calcVoltage - 0.1;
  
  Serial.print("Raw Signal Value (0-1023): ");
  Serial.print(voMeasured);
 
  Serial.print(" - Voltage: ");
  Serial.print(calcVoltage);
 
  Serial.print(" - Dust Density(µg/m3): ");
  Serial.println(pm10*1000);
  
}