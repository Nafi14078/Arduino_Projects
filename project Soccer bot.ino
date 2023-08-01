//rm_ren=4,rm_len=7,rm_rpwm=3,rm_lpwm=5,lm_ren=8,lm_len=12,lm_rpwm=9,lm_lpwm=10
//enable pins are used for activating the bts motors
//pwm pins are used for speed controlling and turning
//Turning right =rm backward and lm forward,Turning left=lm backward and rm forward
//forward=rpwm HIGH,lpwm LOW
//backward=rpwm LOW,lpwm HIGH
//pwm pin=0-255 max

int speed;
char data;

//------------------function declaration-----------------

void forward();
void backward();
void turn_right();
void turn_left();
void stop();

//-------------------defining motor pins-----------------------
//----------Right motor--------------

#define rm_ren 4
#define rm_len 7
#define rm_rpwm 3
#define rm_lpwm 5

//-------------Left motor----------------

#define lm_ren 8
#define lm_len 12
#define lm_rpwm 9
#define lm_lpwm 10


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rm_ren,OUTPUT);
  pinMode(rm_len,OUTPUT);
  pinMode(rm_rpwm,OUTPUT);
  pinMode(rm_lpwm,OUTPUT);
  pinMode(lm_ren,OUTPUT);
  pinMode(lm_len,OUTPUT);
  pinMode(lm_rpwm,OUTPUT);
  pinMode(lm_lpwm,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    data=Serial.read();
    if(data=='0'||data=='1'||data=='2'||data=='3'||data=='4'||data=='5'||data=='6'||data=='7'||data=='8'||data=='9')
    {
      int value=(int)data;//typecasting
      speed=28*value;
      Serial.println(value);
    }
    if(data=='F')
    {
      forward();
      Serial.println("F");
    }
    if(data=='B')
    {
      backward();
      Serial.println("B");
    }
    if(data=='R')
    {
      turn_right();
      Serial.println("R");
    }
    if(data=='L')
    {
      turn_left();
      Serial.println("L");
    }
    if(data=='S')
    {
      stop();
      Serial.println("S");
    }

  }
  
}
void forward()//running forward
{
  digitalWrite(rm_ren,HIGH);
  digitalWrite(rm_len,HIGH);
  analogWrite(rm_rpwm,speed);
  analogWrite(rm_lpwm,0);

  digitalWrite(lm_ren,HIGH);
  digitalWrite(lm_len,HIGH);
  analogWrite(lm_rpwm,speed);
  analogWrite(lm_lpwm,0);
}
void backward()//running backward
{
  digitalWrite(rm_ren,HIGH);
  digitalWrite(rm_len,HIGH);
  analogWrite(rm_rpwm,0);
  analogWrite(rm_lpwm,speed);

  digitalWrite(lm_ren,HIGH);
  digitalWrite(lm_len,HIGH);
  analogWrite(lm_rpwm,0);
  analogWrite(lm_lpwm,speed);
}
void turn_right()//Turning right
{
  digitalWrite(rm_ren,HIGH);
  digitalWrite(rm_len,HIGH);
  analogWrite(rm_rpwm,0);
  analogWrite(rm_lpwm,speed);

  digitalWrite(lm_ren,HIGH);
  digitalWrite(lm_len,HIGH);
  analogWrite(lm_rpwm,speed);
  analogWrite(lm_lpwm,0);
}
void turn_left()//Turning left
{
  digitalWrite(rm_ren,HIGH);
  digitalWrite(rm_len,HIGH);
  analogWrite(rm_rpwm,speed);
  analogWrite(rm_lpwm,0);

  digitalWrite(lm_ren,HIGH);
  digitalWrite(lm_len,HIGH);
  analogWrite(lm_rpwm,0);
  analogWrite(lm_lpwm,speed);
}
void stop()//To stop the car
{
  digitalWrite(rm_ren,LOW);
  digitalWrite(rm_len,LOW);
  

  digitalWrite(lm_ren,LOW);
  digitalWrite(lm_len,LOW);
  
}