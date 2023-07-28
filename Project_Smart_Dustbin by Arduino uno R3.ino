// C++ code
//
#include<Servo.h>
int distance_function(int Trig,int Echo);
int servo_pin=8;
int Trig=10;
int Echo=7;
int distance;
int red=5;
Servo myServo;
void setup()
{
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  pinMode(red,OUTPUT);
  myServo.attach(servo_pin);
}
void loop()
{
 int value=distance_function(Trig,Echo);
  Serial.println(value);
  if(value<=30)
    
  {
    digitalWrite(red,HIGH);
    myServo.write(90);
    
    
  }
  
  else
    
  {
    digitalWrite(red,LOW);
    myServo.write(0);
    
    
  }
  

}

int distance_function(int Trig,int Echo)
{
  digitalWrite(Trig,LOW);
  delayMicroseconds(1);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(1);
  digitalWrite(Trig,LOW);
  delayMicroseconds(1);
  int duration=pulseIn(Echo,HIGH);
  distance=(0.0347*duration)/2;
    return distance;
}
  
  