// Motor pins
const int LEFT_MOTOR_FBK = 2;
const int RIGHT_MOTOR_FBK = 3;
const int LEFT_MOTOR_REV = 7;
const int LEFT_MOTOR_FWD = 8;
const int LEFT_MOTOR_ENABLE = 9;
const int RIGHT_MOTOR_ENABLE = 10;
const int RIGHT_MOTOR_REV = 11;
const int RIGHT_MOTOR_FWD = 12;
bool rightEnable = false;
bool leftEnable = false;

volatile int leftCounter = 0;
volatile int rightCounter = 0;

int leftMotorPower = 192;
int rightMotorPower = 192;

int loops = 0;

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
  if(loops > 20) {
    stopRover();
    return;
  }
  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  digitalWrite(LEFT_MOTOR_FWD, HIGH);

  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);

  adjust();

  delay(500);
  loops++;
}

