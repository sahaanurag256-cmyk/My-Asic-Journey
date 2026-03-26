/* 2 player game checking reaction time of each
*Creator: Anurag Saha
*/

const int btn1 = 2 ;//1st player
const int led = 13;
const int btn2= 3 ;//player 2 for dual player response and competition

int pl1score = 0; //initial score 0 for scoreboard
int pl2score=0;

long start; //long instead of int to not cause integer overflow
long stop;
long reaction;

void setup();
{Serial.begin(115200):
pinMode(led, OUTPUT);
pinMode(btn1, INPUT_PULLUP);

randomSeed(analogRead(0)); // so random delay time changes each turn by getting electrical noise as its a floating pin

Serial.println("Reaction Competition");
Serial.println("Wait for the LED to glow ... first clicker WINS!!!");

void loop()
{


  
