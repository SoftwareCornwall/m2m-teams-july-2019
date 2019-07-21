
#include <NewPing.h>

// Light sensors
#define LS_LEFT A0
#define LS_MIDDLE A1
#define LS_RIGHT A2

// Ultrasonic forward
#define US_FWD_TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define US_FWD_ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
// Ultrasonic down
#define US_DWN_TRIGGER_PIN 13
#define US_DWN_ECHO_PIN A3

#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

// Motor pins
#define LEFT_MOTOR_FBK 2
#define RIGHT_MOTOR_FBK 3
#define LEFT_MOTOR_REV 7
#define LEFT_MOTOR_FWD 8
#define LEFT_MOTOR_ENABLE 9
#define RIGHT_MOTOR_ENABLE 10
#define RIGHT_MOTOR_REV 11
#define RIGHT_MOTOR_FWD 12
#define LEFT 0
#define RIGHT 1

// Demo stage constants
#define STAGE_STRAIGHT_LINE 0
#define STAGE_SQUARE 1
#define STAGE_FIGURE_EIGHT 2
#define STAGE_US_SENSORS_WALL 3
#define STAGE_US_SENSORS_FALL 4
#define STAGE_L_SENSORS_FOLLOW 5

// Pulse counters for each motors.
volatile int leftCounter = 0;
volatile int rightCounter = 0;

// Power of both motors, from 0 to 255.
int leftMotorPower = 192;
int rightMotorPower = 192;

int demoStage = 0;
int stages[] = {STAGE_SQUARE, STAGE_STRAIGHT_LINE, STAGE_US_SENSORS_WALL, STAGE_US_SENSORS_FALL, STAGE_L_SENSORS_FOLLOW, STAGE_FIGURE_EIGHT};

// Sonar objects (ultrasonic sensors).
NewPing sonarFwd(US_FWD_TRIGGER_PIN, US_FWD_ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonarDwn(US_DWN_TRIGGER_PIN, US_DWN_ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Set all pin modes appropriately.
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);
  pinMode(LEFT_MOTOR_REV, OUTPUT);
  pinMode(LEFT_MOTOR_FWD, OUTPUT);
  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
  pinMode(RIGHT_MOTOR_REV, OUTPUT);
  pinMode(RIGHT_MOTOR_FWD, OUTPUT);

  // Immediately ping the sonars for accuracy.
  sonarFwd.ping_cm();
  sonarDwn.ping_cm();

  // Open serial on band 9600 for debugging.
  Serial.begin(9600);

  // Attach interrupt callback functions.
  attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_FBK), leftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_FBK), rightMotorISR, RISING);
}

void rightMotorISR() {
  // Called when the right motor emits a pulse.
  rightCounter++;
}

void leftMotorISR() {
  // Called when the left motor emits a pulse.
  leftCounter++;
}

void loop() {
  // Main loop. Called constantly.
  if (demoStage >= sizeof(stages) / sizeof(int)) return; // Stop at the end of the stages array.
  int stage = stages[demoStage]; // Get the current stage.
  switch (stage) { // Decide what to do.
    case STAGE_STRAIGHT_LINE:
      if (straightLine(537)) demoStage++; // If the straight line is complete, move to next stage.
      break;
    case STAGE_SQUARE:
      squareForwards(0);
      demoStage++;
      break;
    case STAGE_FIGURE_EIGHT:
      eight();
      demoStage++;
      break;
    case STAGE_US_SENSORS_WALL:
      if (straightLineAvoid(LEFT)) demoStage++; // If done, move to next stage.
      delay(50);
      break;
    case STAGE_US_SENSORS_FALL:
      leftMotorPower = 105;
      rightMotorPower = 105;
      if (straightLineNoFall()) {
        demoStage++; // If done, move to next stage.
        leftMotorPower = 192;
        rightMotorPower = 192;
      }
      delay(50);
      break;
    case STAGE_L_SENSORS_FOLLOW:
      // Not implemented. :(
      break;
  }
  delay(750);
}
