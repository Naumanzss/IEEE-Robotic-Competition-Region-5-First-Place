#include <Adafruit_TCS34725.h>

#include <Wire.h>


// Pick analog outputs, for the UNO these three work well
// use ~560  ohm resistor between Red & Blue, ~1K for green (its brighter)
#define redpin 3
#define greenpin 5
#define bluepin 6
// for a common anode LED, connect the common pin to +5V
// for common cathode, connect the common to ground

// set to false if using a common cathode LED
#define commonAnode true

// our RGB -> eye-recognized gamma color
byte gammatable[256];





// standard value for color // this will be re calibrated in comp... 

float RED[3] = {163, 55.36, 52.23} ; // D1 goes with Red **
float GREEN[3] = {79.26, 113.53 ,61.82};// D2 goes with Red ** 
float BLUE[3] = {50.35 , 84.04 , 125.36} ;// D3 goes with Red 
float ORANGE[3] = { 124.58, 84.11 , 50.72};// D4 goes with Red **
float YELLOW[3] = {101.66 , 99.05, 55.95};// D5 goes with Red 
float MAGENTA[3] = {111.14, 68.27 , 85.35};// D6 goes with Red 
float CYAN[3] = {45.91 , 102.46 , 110.53};// D7 goes with Red 
float GREY[3] = {80.83 , 92.49, 85.46};// D8 goes with Red 









// end of standard values of color 






Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

float distance(float [], float []);

#include <QTRSensors.h>






#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       1000  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2



QTRSensorsRC qtrrc((unsigned char[]) {3, 4, 5, 6, 7, 8, 9, 10},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

long int countEventOn, countEventOff;

byte M1 = B01000000;
byte M2 = B00010000;
byte M3 = B00000100;
byte M4 = B00000001;
//*********bitch

float posSum = 0;
float stepf = 0;


//************************
volatile int cnt;
volatile boolean flag1;
volatile int countCompareValue, steps1;
volatile byte allmotors = B01010101;
volatile long steps;
byte fwd = B00000000;
byte rev = B10101010;
byte rotright = B10001000;
byte rotleft = B00100010;
byte strafeleft = B00101000;
byte straferight = B10000010;
byte rightmotors = B01000100;
byte leftmotors = B00010001;
byte frontmotors = B01010000;
byte rearmotors = B00000101;
byte l45 = B01000001;
byte r45 = B00010100;
byte mastermove, slavemove;
float steps_per_inch = 215.602;
float steps_per_degree = 23.6;
float startdist = 0.3;
float straight = 0.997;
float pos = 0;
float oldPos = 0;
float posCount = 0;
float ocvar3, ocvar4;
float baseTurnRatio = 0.25;
int testCounter = 0;
bool sensorOn[8] = {false, false, false, false, false, false, false, false};
bool oldSensorOn[8] = {false, false, false, false, false, false, false, false};
                  //sp0    sp1    sp2    sp3
bool coins[8][4] ={false, false, false, false,  
                   true, true, true, true,  
                   true, true, true, true,  
                   true, true, true, true,  
                   false, false, false, false,
                   true, true, true, true,  
                   true, true, true, true,  
                   true, true, true, true,  
                   };
 
int degree = 0;// degree for return color rotation
//first color is always yellow number 3
int nextColor[27] = {2,1,7,6,5,3,2,1,7,6,5,3,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int c = 0, c1 = 0, c2 = 0, c3 = 0, c4=0, c5 = 0, c6=0, c7=0,c8=0, c9=0,
    c10= 0, c11=0, bc = 0, box = 0, sp = 0, numOfCoins, box1 = 0, sp1 = 0,
    res = 0, color1 = 8, comingBack = 0, MC = 0, CI= 5, greycoin = 0;
    
int sensorOnAt = 300;
long del = 375;


/*
 * 0 = Home 41 inches
 * 1 = Cyan 50 inches
 * 2 = Magenda 36 inches
 * 3 = Yellow 50 inches
 * 4 = Home 2 41 inches
 * 5 = Blue 50 inches
 * 6 = Green 36 inches
 * 7 = Red 50 inches
 * 
 * 1 = R135
 * 2 = R90
 * 3 = R45
 * 4 = 0
 * 5 = L45
 * 6 = L90
 * 
 */





void setup() {
DDRL = B11111111;

  //******************************************Line Sensor QTR************
  pinMode(27, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(31, OUTPUT);
  digitalWrite(13, HIGH);    // turn on Arduino's LED to indicate we are in calibration mode
  Serial.begin(9600);
  int a;
  selfCal();  
  DDRL = B11111111; 
  fixSensors();
  //autoCal();


magnetOff();
moveServoUp();
myacc(fwd, 44, del);
turnacc (rotleft, 45, del);
comingBack = 1;
goFwd_LSSP3 (100, del);
comingBack = 0;
goFwd_LS(3,del);

turnacc (rotleft, 180, del);
fixSensors();
pickupSP1();
detectColor();
checkIfNoCoin();
nextColor[bc] = color1;

box = 3;
sp = 0;
if (color1 == 8) greycoin = 1;

gotoMiddle();
coins[box][sp] = false;
numOfCoins = 23;
if (color1 == 8){
numOfCoins++;
goto middleDrop; 
}
returnToColor();
while(numOfCoins > 0)
{
  box = nextColor[bc];
  bc++;
  if (box%2 == 0) mov(fwd, 2, del);
  if (box%2 == 1) mov(fwd, 2 , del);    

resolved: 
 turnacc (rotleft, 180, del);

  
  if(coins[box][0] == false && coins[box][1] == false && coins[box][2] == false){   
    if(coins[1][0]  == true || coins[1][1] == true || coins[1][2] == true || coins[1][3] == true){
        gotoMiddleR(); 
        box1 = 1;
        rotate();
        box = box1;
        nextColor[bc] = box1;
        gotoColor();    
    }
   else if(coins[2][0]  == true || coins[2][1] == true || coins[2][2] == true || coins[2][3] == true){
      gotoMiddleR(); 
      box1 = 2;
      rotate();
      box = box1;
      nextColor[bc] = box1;
      gotoColor();
    }
   else if(coins[3][0]  == true || coins[3][1] == true || coins[3][2] == true|| coins[3][3] == true){
        gotoMiddleR(); 
        box1 = 3;
        rotate();
        box = box1;
        nextColor[bc] = box1;
        gotoColor();
    }
    else if(coins[5][0]  == true || coins[5][1] == true || coins[5][2] == true || coins[5][3] == true){
      gotoMiddleR();
      box1 = 5;
      rotate();
      box = box1;
      nextColor[bc] = box1;
      gotoColor();     
    }
    else if(coins[6][0]  == true || coins[6][1] == true || coins[6][2] == true || coins[6][3] == true){
        gotoMiddleR(); 
        box1 = 6;
        rotate();
        box = box1;
        nextColor[bc] = box1;
        gotoColor();      
    }
    else if(coins[7][0]  == true || coins[7][1] == true || coins[7][2] == true || coins[7][3] == true){
      gotoMiddleR(); 
      box1 = 7;
      rotate();
      box = box1;
      nextColor[bc] = box1;
      gotoColor();      
    }
     mov(fwd, 2, del); 
     goto resolved; 
  }

 else if (box%2 == 0){            // FOR HORIZONTAL COLORS
    if (coins[box][3] == true){         //
        pickupSP0N();                   //
        detectColor();
        checkIfNoCoin();
        nextColor[bc] = color1;
        if (color1 == 8) greycoin = 1;
        sp = 3;                         // 
        gotoMiddleN();                  //
        if (color1 == 8){
          coins[box][sp] = false;
          goto middleDrop;
          }
        returnToColor(); 
        coins[box][sp] = false;   
    }
 else if (coins[box][2] == true){         //
        pickupSP1N();                   //
        detectColor();
        checkIfNoCoin();
        nextColor[bc] = color1;
        if (color1 == 8) greycoin = 1;
        sp = 2;                         // 
        gotoMiddleN();                  //
        if (color1 == 8){
          coins[box][sp] = false;
          goto middleDrop;
          }
        returnToColor(); 
        coins[box][sp] = false;   
    }

 else if (coins[box][1] == true){         //
        pickupSP2N();                   //
        detectColor();
        checkIfNoCoin();
        nextColor[bc] = color1;
        if (color1 == 8) greycoin = 1;
        sp = 1;                         // 
        gotoMiddleN();                  //
       if (color1 == 8){
          coins[box][sp] = false;
          goto middleDrop;
          }
        returnToColor(); 
        coins[box][sp] = false;   
    }

 else if (coins[box][0] == true){       //
        pickupSP3N();   
        detectColor();
        checkIfNoCoin();
        nextColor[bc] = color1;
        if (color1 == 8) greycoin = 1;
        sp = 0;                         //
        gotoMiddleN();                  //
         if (color1 == 8){
          coins[box][sp] = false;
          goto middleDrop;
          }
        returnToColor(); 
        coins[box][sp] = false;
        
    }
  }
  
else if (box%2 == 1){
     if (coins[box][3] == true){      // FOR DIAGONAL COLORS  
        pickupSP0();                     
        detectColor();
        checkIfNoCoin();
        nextColor[bc] = color1;
        if (color1 == 8) greycoin = 1;
        sp = 3;                          
        gotoMiddle();
         if (color1 == 8){
          coins[box][sp] = false;
          goto middleDrop;
          }
        returnToColor(); 
        coins[box][sp] = false;
      }
 else if (coins[box][2] == true){      // FOR DIAGONAL COLORS  
        pickupSP1();                     
        detectColor();
        checkIfNoCoin();
        nextColor[bc] = color1;
        if (color1 == 8) greycoin = 1;
        sp = 2;                          
        gotoMiddle();
         if (color1 == 8){
          coins[box][sp] = false;
          goto middleDrop;
          }
        returnToColor(); 
        coins[box][sp] = false;
      }

  else if (coins[box][1] == true){      // FOR DIAGONAL COLORS  
        pickupSP2();                     
        detectColor();
        checkIfNoCoin();
        nextColor[bc] = color1;
        if (color1 == 8) greycoin = 1;
        sp = 1;                          //
        gotoMiddle();
        if (color1 == 8){
          coins[box][sp] = false;
          goto middleDrop;
          }
        returnToColor(); 
        coins[box][sp] = false;
      }
      
   else if (coins[box][0] == true) {
        pickupSP3();
        detectColor();
        checkIfNoCoin();
        nextColor[bc] = color1;
        if (color1 == 8) greycoin = 1;
        sp = 0;
        gotoMiddle();
        if (color1 == 8){
          coins[box][sp] = false;
          goto middleDrop;
          }
        returnToColor();
        coins[box][sp] = false;
      }
   }
 numOfCoins--;
     
}


mov(fwd, 2, del);
box = nextColor[bc];
turnacc (rotleft, 180, del);
sp = 3;
box1 = 4;
if (box%2 == 0)  gotoMiddleN();
if (box%2 == 1)  gotoMiddle();   
 
gotoHome:
 sp = 3;
 box1 = 4; 
 rotate();
 myacc(fwd, 41, del);
 delay(200);
 homeRecenter();

//// FOR MIDDLE COINS 

if(MC==1){
middleDrop:
        numOfCoins--;
        if (numOfCoins <= 0)goto gotoHome;
        
     if(coins[1][0]  == true || coins[1][1] == true || coins[1][2] == true || coins[1][3] == true){
        box1 = 1;
        rotate();
        nextColor[bc] = box1;
        box = box1;
        gotoColor();   
    }
   else if(coins[2][0]  == true || coins[2][1] == true || coins[2][2] == true || coins[2][3] == true){
      box1 = 2;
      rotate();
      nextColor[bc] = box1;
      box = box1;
      gotoColor();  
    }
   else if(coins[3][0]  == true || coins[3][1] == true || coins[3][2] == true || coins[3][3] == true){
        box1 = 3;
        rotate();
        nextColor[bc] = box1;
        box = box1;
        gotoColor();       
    }
    else if(coins[5][0]  == true || coins[5][1] == true || coins[5][2] == true || coins[5][3] == true){
      box1 = 5;
      rotate();
      nextColor[bc] = box1;
      box = box1;
      gotoColor();        
    }
    else if(coins[6][0]  == true || coins[6][1] == true || coins[6][2] == true || coins[6][3] == true){
        box1 = 6;
        rotate();
        nextColor[bc] = box1;
        box = box1;
        gotoColor();    
    }
    else if(coins[7][0]  == true || coins[7][1] == true || coins[7][2] == true|| coins[7][3] == true){
      box1 = 7;
      rotate();
      nextColor[bc] = box1;
      box = box1;
      gotoColor();      
    }
     mov(fwd, 2, del); 
     goto resolved; 
    
  }

}   //**Main Function End*****




void loop() {
  
unsigned int position = qtrrc.readLine(sensorValues);

 for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    
    Serial.print( sensorValues[i]);
    Serial.print('\t');
  
   
    
  }
fixSensors();
delay(10);
Serial.println();
/*
 for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    if( sensorValues[i]> sensorOnAt){
    Serial.print("ON");
    Serial.print('\t');}
    else if (1)
    {Serial.print("--");
    Serial.print('\t');}
    
  }
fixSensors();
delay(10);
Serial.println();

*/
}

void movcheck(byte dir, float dist, long del)
{
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  long steps = stepf;

  for ( int i = 0; i < steps ; i++)
  {
    PORTL ^= M3;
    delayMicroseconds(del);

  }
} 


