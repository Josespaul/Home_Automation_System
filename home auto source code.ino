#include <LiquidCrystal.h>                     //Library include lcd

int c=0;                                       //initilize counter                          
LiquidCrystal lcd(8,9,10,11,12,13);       //Initilize pins for lcd
void setup()
{                       
  pinMode(16,INPUT);                           //declare pin 16 as input (tsop-A)   
  pinMode(17,INPUT);                           //declare pin 17 as input (tsop-B)
  pinMode(11,OUTPUT);                          //declare pin 11 as Output(LED RED)
  pinMode(12,OUTPUT);                          //declare pin 12 as Output(LED Blue)
  pinMode(13,OUTPUT);                          //declare pin 13 as Output(LED WHITE)
  pinMode(2,OUTPUT);                           //declare pin 2 as Output (RELAY)
  Serial.begin(9600);                          //serial communication with computer
  lcd.begin(16,2);                             //declare LCD as 16x2 type
  lcd.clear();                                 //clear lcd (clear Garbage values on the screen)
  lcd.write("calibrate sensor ");              
  delay(4000);
  lcd.setCursor(0,1);                          //set lcd cursor to second line
  lcd.write("please wait..");
  delay(5000);                                //delay in ms
  lcd.blink();                                //cursor blink
  delay(2000);
  lcd.clear();
  lcd.write("System Ready...");
  delay(1000);
  lcd.blink();
}
void loop()                                   //program logic starts
{
  a:
       if(c>0)
        {
         digitalWrite(2,1); 
        }
       else
        {         
         digitalWrite(2,0); 
        }
   digitalWrite(12,0);
   digitalWrite(13,0);
   digitalWrite(11,0);  
  
    if(pulseIn(16,0)==LOW)
     {
      digitalWrite(11,1);
       if(pulseIn(17,0)==LOW)
         {
         digitalWrite(12,1);
         digitalWrite(13,1); 
         c++;
         Serial.print("Total persons Inside  ");
         Serial.println(c);
         lcd.print("Motion detected");
         lcd.clear();
         lcd.print("Total persons:");
         lcd.setCursor(0,1);
         lcd.print(c);
         delay(10);
         }
        else
         { 
         digitalWrite(11,0);
         digitalWrite(12,0);
         digitalWrite(13,0);    
         goto a;
         }
      }
else
  {
      if(pulseIn(17,0)==LOW)
       {
         digitalWrite(12,1);
          if(pulseIn(16,0)==LOW)
           {
            digitalWrite(11,1);
            digitalWrite(13,1);
            c--;
            Serial.print("Total persons Inside  ");
            Serial.println(c);
            lcd.print("Motion detected");
            lcd.clear();
            lcd.print("Total persons:");
            lcd.setCursor(0,1);
            lcd.print(c);
            delay(10);
            }
            else
            { 
            digitalWrite(11,0);
            digitalWrite(12,0);
            digitalWrite(13,0);
            goto a;
           }
       }
   }
}

 // Joses:Akshay:kiran
