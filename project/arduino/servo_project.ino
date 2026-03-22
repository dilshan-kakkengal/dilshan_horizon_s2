#include<Servo.h> //library for functioning servo motor
Servo Servo1; //object of servo
int potPin=A0;//pin of potentiometer connected to A0 to covert into 0 to 1023
int ledPin=7;//led connected to 7th pin
void setup()
{
  Servo1.attach(9);//servo attached to 9th pin of arduino
  pinMode(ledPin,OUTPUT);//7th pin as output of led
}

void loop()
{
  int reading=analogRead(potPin);//reading as avariable to read the value at A0
  int angle=map(reading,0,1023,0,180);//coverting the reading value to corresponding mapped value
  if(angle>68){//led will be bright
    angle=68;
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  Servo1.write(angle);
  delay(10);
}
