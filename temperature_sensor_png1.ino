#include <Servo.h>
#define temperature A0
#define ledIndicator 2
Servo mainServo;
int position = 0;
int previousPosition;
void setup() {
  pinMode(temperature, INPUT);
  pinMode(ledIndicator, OUTPUT);
  mainServo.attach(3);
  Serial.begin(9600);
}
void loop() {
  // Temperature analysis
  int tempReading = analogRead(temperature);
  // If using 5v input
  float voltage = tempReading * 5.0;
  // Divided by 1024
  voltage /= 1024.0;
  //Converting from 10mv per degree
  float tempC = (voltage - 0.5) * 100;
  // This maps temperature to degrees open for the flap
  int position = map(tempC, 0, 30, 0, 90);
  Serial.println(position);
  if(previousPosition >=30){
     mainServo.write(position);
  digitalWrite(ledIndicator, HIGH);
     delay(1000);
  }
  else{
     mainServo.write(position);
  digitalWrite(ledIndicator,LOW);
     delay(1000);
  }
  digitalWrite(ledIndicator, LOW);
  previousPosition = position;
}

  
  
