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

int loops  = 0;
int currentInstr = 0;
int instructions[] = {FORWARDS, RIGHT, FORWARDS, RIGHT, FORWARDS, RIGHT, FORWARDS, FORWARDS, LEFT, FORWARDS, LEFT, FORWARDS, LEFT, FORWARDS}; // eight
int params[] = {1500, 985, 1500, 1075, 1500, 1100, 1500, 1000, 2000, 1500, 1075, 1500, 980, 1500, 975, 1500, 1000, 1500, 1000, 1500};

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
  // Called when the right motor emits a pulse.
  rightCounter++;
}

void leftMotorISR() {
  // Serial.println("leftMotorISR");
  leftCounter++;
}

void loop() {
  eight();
  delay(1000);
  leftCounter = 0;
  rightCounter = 0;
  leftMotorPower = 192;
  rightMotorPower = 192;
  eightReverse();
  delay(5000);
}
