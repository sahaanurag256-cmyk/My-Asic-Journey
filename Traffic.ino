 /*Traffic Control System for Road & Pedestrian crossing safety
* Created by : Anurag Saha
*/     
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
 
  digitalWrite(red, LOW); //off
  digitalWrite(yellow, LOW);//off
  digitalWrite(green, LOW); }//off 

void loop() //pattern continues
{ digitalWrite(red, HIGH);//red is on (stop)
 
  loop_number++;
 if (loop_number >=2) {//happens every 2 loops
   //when cars stop at 2nd red light, pedestrians cross
   for (int b=0; b<3; b++) //3 times
{digitalWrite(blue,HIGH); //light glows
 tone(buzzer, 1500); //going to beep at 1500 hz
 delay(500);

 digitalWrite(blue,LOW);//doesnt glow
 noTone(buzzer); //sound stops
 delay(500); }
  loop_number=0; //resets the loop count so it doesnt buzz again for another 2 cycles
   } 
 else{
  delay(glow_time);} //stay red for normal stated time
  digitalWrite(red, LOW);//red is off

  digitalWrite(green, HIGH);//green is on (go)
  delay(glow_time);
  digitalWrite(green, LOW); //green is off

  for (int i = 0; i < 3; i++) //warning phase for vehicles
    { digitalWrite(green, HIGH); 
    delay(blink_time); //green led is off for some time
    digitalWrite(green, LOW);
    delay(blink_time); } //green is off for some time
  
  digitalWrite(yellow, HIGH);//yellow is on (slow down)
  delay(glow_time);
  digitalWrite(yellow, LOW); }//yellow is off



