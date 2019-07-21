
const int LEFT_FEEDBACK = 2; //pin numbers on rover
const int RIGHT_FEEDBACK = 3;

#include <NewPing.h>
#define fTRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define fECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define fMAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing fsonar(fTRIGGER_PIN, fECHO_PIN, fMAX_DISTANCE); // NewPing setup of pins and maximum distance.
volatile int fpng = 0;

#define dTRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define dECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define dMAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing dsonar(dTRIGGER_PIN, dECHO_PIN, dMAX_DISTANCE); // NewPing setup of pins and maximum distance.
volatile int dpng = 0;

volatile int leftcounter = 0; //initiate counter to zero for start
volatile int rightcounter = 0; //counter could always be reset

volatile int leftAdd = 0; 
volatile int rightAdd = 0;

int leftMotorON_OFF = 9;
int leftMotorFwd = 8;
int leftMotorBack = 7;

int rightMotorON_OFF = 10;
int rightMotorFwd = 12;
int rightMotorBack = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftMotorON_OFF, OUTPUT); 
  pinMode(leftMotorFwd, OUTPUT);
  pinMode(leftMotorBack, OUTPUT);
  
  pinMode(rightMotorON_OFF, OUTPUT);
  pinMode(rightMotorFwd, OUTPUT);
  pinMode(rightMotorBack, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  //Serial.print(fsonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  //Serial.print(dsonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
}

void loop() {
  
  // demos:

  // silver rover
  criticalEscapeV2();
  pauseTime(5000);
  for (int i=0; i<6;i++) {
    turn90clock();
  }
  pauseTime(5000);

  while (true) {followBeaconAvoidCliffsAndObstacles();}
  
  // small rover
  //while (true) {sEight();}
}

void LeftMotorISR(){
  leftcounter++;
}

void RightMotorISR(){
  rightcounter++;
}
