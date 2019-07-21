#include <NewPing.h>

// Sensors
// Light sensors
const int LS_LEFT = 14;
const int LS_MIDDLE = 15;
const int LS_RIGHT = 16;

// Ultrasonic forward
#define US_FWD_TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define US_FWD_ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
// Ultrasonic
#define US_DWN_TRIGGER_PIN 13
#define US_DWN_ECHO_PIN A3

#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

// Motor pins
const int LEFT_MOTOR_FBK = 2;
const int RIGHT_MOTOR_FBK = 3;
const int LEFT_MOTOR_REV = 7;
const int LEFT_MOTOR_FWD = 8;
const int LEFT_MOTOR_ENABLE = 9;
const int RIGHT_MOTOR_ENABLE = 10;
const int RIGHT_MOTOR_REV = 11;
const int RIGHT_MOTOR_FWD = 12;
const int LEFT = 0;
const int RIGHT = 1;
const int FORWARDS = 2;
bool rightEnable = false;
bool leftEnable = false;

volatile int leftCounter = 0;
volatile int rightCounter = 0;

int leftMotorPower = 105;
int rightMotorPower = 105;

int loops = 0;

NewPing sonarFwd(US_FWD_TRIGGER_PIN, US_FWD_ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonarDwn(US_DWN_TRIGGER_PIN, US_DWN_ECHO_PIN, MAX_DISTANCE); 

void setup() {
  // Put your setup code here, to run once:
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);
  pinMode(LEFT_MOTOR_REV, OUTPUT);
  pinMode(LEFT_MOTOR_FWD, OUTPUT);

  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
  pinMode(RIGHT_MOTOR_REV, OUTPUT);
  pinMode(RIGHT_MOTOR_FWD, OUTPUT);

  sonarFwd.ping_cm();
  sonarDwn.ping_cm();
  
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_FBK), leftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_FBK), rightMotorISR, RISING);
}

void rightMotorISR() {
  // Serial.println("rightMotorISR");
  rightCounter++;
}

void leftMotorISR() {
  // Serial.println("leftMotorISR");
  leftCounter++;
}

void loop() {
  straightLineNoFall();
  delay(50);  
}

