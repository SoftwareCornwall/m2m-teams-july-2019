/* Not currently used
const int LEFT_MOTOR_F = 2;
const int RIGHT_MOTOR_F = 3;
*/
const int LEFT_MOTOR_IN_R = 7;
const int LEFT_MOTOR_IN_F = 8;
const int LEFT_MOTOR_ENABLE = 9;
const int RIGHT_MOTOR_ENABLE = 10;
const int RIGHT_MOTOR_IN_R = 11;
const int RIGHT_MOTOR_IN_F = 12; 

void setup() {
  pinMode(LEFT_MOTOR_IN_R, OUTPUT);
  pinMode(LEFT_MOTOR_IN_F, OUTPUT);
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);
  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
  pinMode(RIGHT_MOTOR_IN_R, OUTPUT);
  pinMode(RIGHT_MOTOR_IN_F, OUTPUT);
}

void loop() {
  digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
  digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
  
  digitalWrite(RIGHT_MOTOR_IN_F, HIGH);
  digitalWrite(LEFT_MOTOR_IN_F, HIGH);

  delay(10 * 1000); // 10 seconds
  
  digitalWrite(RIGHT_MOTOR_IN_F, LOW);
  digitalWrite(LEFT_MOTOR_IN_F, LOW);

  digitalWrite(LEFT_MOTOR_IN_R, HIGH);
  digitalWrite(RIGHT_MOTOR_IN_R, HIGH);

  delay(1000); // 1 second

  // Turn off motors and disable reverse
  digitalWrite(LEFT_MOTOR_ENABLE, LOW);
  digitalWrite(RIGHT_MOTOR_ENABLE, LOW);
  
  digitalWrite(LEFT_MOTOR_IN_R, LOW);
  digitalWrite(RIGHT_MOTOR_IN_R, LOW);

  delay(2000); // 2 Seconds
  
}

