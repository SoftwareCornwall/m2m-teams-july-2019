//helps count the number of rotations on the tracks
void LeftMotorISR() {
  leftcounter++;
  Serial.print("leftcounter ");
  Serial.println(leftcounter);
}

void RightMotorISR() {
  rightcounter++;
  Serial.print("rightcounter ");
  Serial.println (rightcounter);
}

//stops the rover
void stoprover ()
{
  digitalWrite (leftMotorIN1, LOW);
  digitalWrite (rightMotorIN3, LOW);
  digitalWrite (leftMotorIN2, LOW);
  digitalWrite (rightMotorIN4, LOW);

}

void turnoffrover ()
{
  digitalWrite (leftMotorIN1, LOW);
  digitalWrite (rightMotorIN3, LOW);
  digitalWrite (leftMotorIN2, LOW);
  digitalWrite (rightMotorIN4, LOW);
  analogWrite (leftMotorENA, 0);
  analogWrite (rightMotorENB, 0);
}
//this is the code used to make the robot turn right
void turnright(int delaytime) {
  analogWrite (leftMotorENA, leftspeed);
  analogWrite (rightMotorENB, rightspeed);
  digitalWrite(leftMotorIN1, HIGH );
  digitalWrite (rightMotorIN4, HIGH);
  delay(delaytime);
  digitalWrite(leftMotorIN1, LOW );
  digitalWrite (rightMotorIN4, LOW);
}

//this is the code used to make the robot go straight forward
void straightboy() {
  analogWrite (leftMotorENA, leftspeed);
  analogWrite (rightMotorENB, rightspeed);
  digitalWrite(leftMotorIN1, HIGH);
  digitalWrite(rightMotorIN3, HIGH);
  delay(1000);
  digitalWrite(leftMotorIN1, LOW);
  digitalWrite(rightMotorIN3, LOW);
//this is the code used to make the robot turn left
}
void turnleft(int delaytime) {
  analogWrite (leftMotorENA, leftspeed);
  analogWrite (rightMotorENB, rightspeed);
  digitalWrite (leftMotorIN2, HIGH);
  digitalWrite (rightMotorIN3, HIGH);
  delay(delaytime);
  digitalWrite(leftMotorIN2, LOW);
  digitalWrite (rightMotorIN3, LOW);
}

void unoreverse() {
  analogWrite (leftMotorENA, leftspeed);
  analogWrite (rightMotorENB, rightspeed);
  digitalWrite (leftMotorIN2, HIGH);
  digitalWrite (rightMotorIN4, HIGH);
  delay(1000);
  digitalWrite (leftMotorIN2, LOW);
  digitalWrite (rightMotorIN4, LOW);
}

