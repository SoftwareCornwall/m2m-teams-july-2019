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

int leftMotorPower = 192;
int rightMotorPower = 192;

int loops = 0;
int currentInstr = 0;
int instructions[] = {FORWARDS, RIGHT, FORWARDS, RIGHT, FORWARDS, RIGHT, FORWARDS, RIGHT}; // Square
int params[] = {1000, 985, 1000, 1075, 1000, 1100, 1000, 1075};

void setup() {
  // Put your setup code here, to run once:
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);
  pinMode(LEFT_MOTOR_REV, OUTPUT);
  pinMode(LEFT_MOTOR_FWD, OUTPUT);

  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
  pinMode(RIGHT_MOTOR_REV, OUTPUT);
  pinMode(RIGHT_MOTOR_FWD, OUTPUT);

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
  if (currentInstr == sizeof(instructions) / sizeof(int)) return; // Stop at end of instructions
  int dir = instructions[currentInstr];
  int param = params[currentInstr];
  Serial.println(dir);
  switch (dir) {
    case LEFT:
      turn(LEFT, param);
      break;
    case RIGHT:
      turn(RIGHT, param);
      break;
    case FORWARDS:
      moveFB(param, true);
      break;
  }
  currentInstr++;
}
