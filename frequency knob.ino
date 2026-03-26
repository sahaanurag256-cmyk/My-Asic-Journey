/*Light & Potentiometer indicating frequency of sound player
*Creator: Anurag Saha
*/

//defining the fixed pins

int light = A0;
int rotator = A1;
  int speaker = 5;

int green=2;
int yellow=3;
int red=4;

void setup()
{pinMode(speaker, OUTPUT);//output sources
pinMode(green, OUTPUT); //output sources
pinMode(yellow, OUTPUT);//output sources
pinMode(red, OUTPUT);//output sources

Serial.begin(115200); }

void loop()
{ int lval= analogRead(light);
int rval=analogRead(rotator);

int lpitch= map(lval,200,800,0,2000); //sets the maximum pitch, made limits 200 to 800 to increase light sensetivity
int rpitch=map(rval,0,1023,0,2000); //plots it out in scale of 0hz to 2khz

int pitch= lpitch+rpitch + 50; //combination of pitches produced by light & potentiometer. 50hz is he base sound so something is always heard

pitch= constrain(pitch,50,4050); //keeps the sound in safe limit of 50hz to 4050 hz to avoid buzzer glitches at absurd frequencies
tone(speaker, pitch,20); //makes sound for 20ms before checking sensors again

//led conditions

digitalWrite(red, pitch>3050); //led indicating range of frequency
digitalWrite(yellow, pitch>1550);  //led indicating range of frequency
digitalWrite(green, pitch>550);  //led indicating range of frequency

//code to plot these values of frequency on a computer

Serial.print(50);
  Serial.print(" ");
  Serial.print(pitch);
Serial.print(" ");
Serial.println(rpitch);

delay(10); }





  
