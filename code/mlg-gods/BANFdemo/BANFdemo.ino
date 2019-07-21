int one = 2;
int two = 3;
int LOn = 9;
int LIN2 = 7;
int LIN1 = 8;
int ROn = 10;
int RIN4 = 11;
int RIN3 = 12;
int LS = 200;
int RS = 190;
int threshhold = 20; 
int turningTime=1025; 
int driveTime=1600; 

int state = 0;
const int state_straightline = 0;
const int state_square = 1;
const int state_following_the_light = 2;
const int state_following_light_ramp = 3;


const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3;

volatile int leftcounter = 0;
volatile int rightcounter = 0;

#include <NewPing.h>

#define light_sensor_right 2
#define light_sensor_middle 6
#define light_sensor_left 7

#define DOWN_TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define DOWN_ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


NewPing sonar(DOWN_TRIGGER_PIN, DOWN_ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.   //sonar for not falling off cliff

NewPing sonar_forward(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.   //sonar for not hitting object

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(one,OUTPUT);
  //pinMode(two,OUTPUT);
  pinMode(LOn,OUTPUT);
  pinMode(LIN2,OUTPUT);
  pinMode(LIN1,OUTPUT);
  pinMode(ROn,OUTPUT);
  pinMode(RIN4,OUTPUT);
  pinMode(RIN3,OUTPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  
 Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

  Serial.print(light_sensor_left);
  Serial.print(light_sensor_middle);
  Serial.print(light_sensor_right);
}

// the loop function runs over and over again forever
void loop() {

 analogWrite(LOn, LS);   // turn the Motor on (HIGH is the voltage level)                         
 analogWrite(ROn, RS);
 Serial.println(state); 
  switch(state){
    case state_straightline:
      forward2metres();
    break;

    case state_square:
      right_square(true);
      state = 2;
    break;

    case state_following_the_light:
      follow_light_until_wall();
      state = 3;
    break;

    case state_following_light_ramp:
      follow_light_until_cliff();
     
   break;
  }


 /* 
  if(RS > 255)
  {
    RS=255;
  }
  if(LS > 255)
  {
    LS=255;
  }
  */
}

void LeftMotorISR() {
  leftcounter++;
  //Serial.println(leftcounter);
}

void RightMotorISR() {
  rightcounter++;
  //Serial.println(rightcounter);
}

  //turn(false);





/*void functionName(itemValue)
{
  Code runs here using this number itemValue;
}

if(leftCounter > rightCounter)
{
  do something
}
if(x = 0; x < 5; x++)  // x == 0, x >= 6, not same as !=, And is &&, or is or 
{
  if True run this code;
}
*/
