#include <Wire.h>
#include <LiquidCrystal_I2C.h>
/*Traffic Control System for Road & Pedestrian crossing safety
* Created by : Anurag Saha
*/
LiquidCrystal_I2C lcd(0x27,16,2);
byte man[8] = {0b01100,0b01100,0b00100,0b01110,0b10101,0b00100,0b01010,0b10001}; //pixel map i made from bit mapping
byte hand[8]   = {0b01010,0b01010,0b11111,0b11111,0b11111,0b01110,0b01110,0b00000}; //pixel map i made from bit mapping
const int red = 8; //pins on breadboard
const int yellow = 9;//pins on breadboard
const int green = 10;//pins on breadboard
const int blue = 11; //pedestrian light
const int buzzer = 12 ;//speaker

const int glow_time = 3000; //light will glow for 1 sec
const int blink_time = 500; //green is going to blink for 0.5 sec each
int loop_number = 0; //no. of times of loop

void setup() //setup first time
{  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);

 
  lcd.init(); //turns led on
lcd.backlight(); //turns led background light on
lcd.createChar(0,man); //saves icon into CGRAM or the led's brain
lcd.createChar(1,hand); //saves icon into CGRAM or the led's brain 

 
  digitalWrite(red, LOW); //off
  digitalWrite(yellow, LOW);//off
  digitalWrite(green, LOW); }//off 

void loop() //pattern continues
{ 
     //red light time

digitalWrite(red, HIGH);//red is on (stop)
 lcd.clear(); //clears everything
 lcd.write(1); //shows the stop hand
  lcd.print("STOP!!! RED"); //stays at top
  
  loop_number++;

         //blue pedestrian light time

 if (loop_number >=2) {//happens every 2 loops
   //when cars stop at 2nd red light, pedestrians cross
   for (int b=0; b<3; b++) //3 times
    { lcd.setCursor(0,1);
   lcd.write(0); //shows man
    lcd.print("CROSS NOW!!!");
    
digitalWrite(blue,HIGH); //light glows
 tone(buzzer, 1500); //going to beep at 1500 hz
 delay(500);

  lcd.setCursor (0,1); //erases only bottom row so man blinks and stop hand remains
   lcd.print("                "); //16 speaces to wipe out bottom line completely 

 digitalWrite(blue,LOW);//doesnt glow
 noTone(buzzer); //sound stops
 delay(500); }
  loop_number=0; //resets the loop count so it doesnt buzz again for another 2 cycles
   } 
 else{
  lcd.setCursor(0,1);
  lcd.print("WAIT....");
  delay(glow_time);} //stay red for normal stated time
  digitalWrite(red, LOW);//red is off

         //green light time

  digitalWrite(green, HIGH);//green is on (go)
 lcd.clear();
 lcd.print("GO: GREEN");
  delay(glow_time);
  digitalWrite(green, LOW); //green is off

         //green warning time
         
  for (int i = 0; i < 3; i++) //warning phase for vehicles
    { digitalWrite(green, HIGH); 
    delay(blink_time); //green led is off for some time
    digitalWrite(green, LOW);
    delay(blink_time); } //green is off for some time

       //yellow light time
 
  digitalWrite(yellow, HIGH);//yellow is on (slow down)
 lcd.clear();
 lcd.print("CAUTION: SLOW DOWN");
  delay(glow_time);
  digitalWrite(yellow, LOW); }//yellow is off


