// C++ code
//
int pir=10;
int relay=12;
int buzzar=11;
void setup()
{
  Serial.begin(9600);
  pinMode(pir,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(buzzar,OUTPUT);
   
}
  void loop()
  {
    if(digitalRead(pir)==HIGH)
    {
      Serial.println("Motion detected.");
      digitalWrite(relay,HIGH);
      digitalWrite(buzzar,HIGH);
      
    }
    else
    {
      Serial.println("Motion not detected.");
      digitalWrite(relay,LOW);
      digitalWrite(buzzar,LOW);
    }
  }