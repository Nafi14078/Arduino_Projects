// C++ code
//
#include<LiquidCrystal_I2C.h>
#include<Keypad.h>
int relay=5;
int buzzer=2;

const int LCD_Row=2;//LCD Display total row number
const int LCD_Col=16;//LCD display total col number
const int LCD_Address=0x27;
LiquidCrystal_I2C lcd(LCD_Address,LCD_Col,LCD_Row);//create a object of lcd
const byte Row=4;
const byte Col=4;
char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowpin[4]={13,12,11,10};
byte colpin[4]={9,8,7,6};
String inputpassword="";//blank string
String systempassword="1234";//Password set//we can set any password we want
int len1=4;//systempassword length

//-----------creating keypad object--------------

Keypad keypad=Keypad(makeKeymap(keys),rowpin,colpin,Row,Col);

void setup()
{
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();
 
}
void loop()
{

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter your pass");
  int i=0;
  while(1)
  {
  
  char key=keypad.getKey();
  if(key)
  {
    
    if(inputpassword.length()<len1)
    {
      inputpassword=inputpassword+key;
      lcd.clear();
      lcd.setCursor(i,0);
      lcd.print("*");
      i++;
    
    if(inputpassword.length()==len1)
    {
      if(inputpassword==systempassword)
      {
        
        Serial.println(key);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Door Unlocked");
        digitalWrite(relay,HIGH);
        digitalWrite(buzzer,HIGH);
        delay(5000);
        //inputpassword="";
        //digitalWrite(relay,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Door gets locked");
        digitalWrite(relay,LOW);
        digitalWrite(buzzer,LOW);
        delay(3000);
        inputpassword="";
        break;
        
      }
      else
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Access denied");
        digitalWrite(relay,LOW);
        digitalWrite(buzzer,LOW);
        delay(5000);
        inputpassword="";
        break;
      }
    }
  }
 }
}
}