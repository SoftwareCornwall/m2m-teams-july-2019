// Include the NewPing library
#include <NewPing.h>

// Feedback pins for the motor ticks
int LEFT_FEEDBACK = 2;
int RIGHT_FEEDBACK = 3;

// Pins for forward and down sensors
int DWN_TRIGGER_PIN = 13;
int DWN_ECHO_PIN = 17;
int FWD_TRIGGER_PIN = 4;
int FWD_ECHO_PIN = 5;

// Maxiumum distance the sensors will record
int MAX_DISTANCE= 200;

// Pins used for the motor.
int LB = 7;
int LF = 8;
int LE = 9;
int RB = 11;
int RF = 12;
int RE = 10;

// Speed of motors
volatile int leftSpeed = 225;
volatile int rightSpeed = 255;

// Keeps count of motor ticks
volatile int leftcounter = 0;
volatile int rightcounter = 0;

// Decides whether the loop should run or not
volatile bool stopped = false;

// Used for Demo Mode
volatile int demo = 8;
volatile bool demoMode = false;

// Create Sensor objects for forward and down
NewPing fwd(FWD_TRIGGER_PIN, FWD_ECHO_PIN, MAX_DISTANCE);
NewPing dwn(DWN_TRIGGER_PIN, DWN_ECHO_PIN, MAX_DISTANCE);

void setup() {
  
  // Set pins LB, LF, LS, RS, RB, RF to output  
  pinMode(LB, OUTPUT); // Left Backwards
  pinMode(LF, OUTPUT); // Left Forwards
  pinMode(LE, OUTPUT); // Left Enable
  pinMode(RE, OUTPUT); // Right Enable
  pinMode(RB, OUTPUT); // Right Backwards
  pinMode(RF, OUTPUT); // Right Forwards

  // Begin recording updates to sensor
  Serial.begin(115200);

  // Call Motor Tick Updates
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);

  // Call sensor update intially to stabalise them
  dwn.ping_cm();
  fwd.ping_cm();
}

// The main loop.
void loop() {
  if (!stopped){
    
    goStraight();
    story16();
    
  }
}

// Function to count the amount of ticks the left motor has done
void LeftMotorISR(){
  leftcounter++;
}

// Function to count the amount of ticks the right motor has done
void RightMotorISR(){
  rightcounter++;
}

