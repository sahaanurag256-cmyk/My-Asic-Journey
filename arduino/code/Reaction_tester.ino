/* 2 player game checking reaction time of each
*Creator: Anurag Saha
*/

const int btn1 = 2 ;//1st player
const int led = 13;
const int btn2= 3 ;//player 2 for dual player response and competition

int pl1score = 0; //initial score 0 for scoreboard
int pl2score=0;

long start; //long instead of int to not cause integer overflow
long stop1;
long stop2; 
long reaction1;
long reaction2;

void setup()
{Serial.begin(115200);
pinMode(led, OUTPUT);
pinMode(btn1, INPUT_PULLUP);

randomSeed(analogRead(0)); // so random delay time changes each turn by getting electrical noise as its a floating pin

Serial.println("Reaction Competition");
Serial.println("Wait for the LED to glow ... first clicker WINS!!!");

pinMode(btn2, INPUT_PULLUP); }

void loop()
{ Serial.println("Get Ready Now......");

stop1=0;
stop2=0;

delay(random(2000,5000)); //cause a random delay each time between 2 sec to 5 sec

digitalWrite(led,HIGH); //starts timer when the led glows
start=millis();

while (stop1 ==0 ||
  stop2==0){
if (digitalRead(btn1)==LOW && stop1==0)
{stop1 = millis(); }

if (digitalRead(btn2)==LOW &&stop2==0)
{stop2=millis();} }

  digitalWrite(led, LOW);

reaction1=stop1-start;
reaction2=stop2-start;

Serial.println("* Results Gotten *");
  Serial.print("Player 1 : "); Serial.print(reaction1); Serial.println(" ms");
Serial.print("Player 2 : "); Serial.print(reaction2); Serial.println(" ms");

if (reaction1<reaction2)
{Serial.println("Player 1 was WON!");
pl1score++; }

else if(reaction1>reaction2)
{Serial.println("Player 2 was WON");
pl2score++; } 

else
{Serial.println("both players have TIED");}

Serial.print("Score- Player 1 : "); Serial.print(pl1score);
Serial.print(" | Player 2 : "); Serial.println(pl2score);
Serial.println("~~~~~~~~~~~~~~~");

delay(3000); }





  
