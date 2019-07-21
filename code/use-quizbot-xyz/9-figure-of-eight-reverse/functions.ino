// ----> Use quizbot.xyz

void moveFB (int ms, bool forward) {
  // Move forwards or backwards for the specified time in ms.
  // Both motors are ran at full power, and no adjustments are applied.
  digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
  digitalWrite(LEFT_MOTOR_ENABLE, HIGH);

  Serial.print("Moving ");
  if (forward) {
    Serial.println("forward");
    digitalWrite(LEFT_MOTOR_FWD, HIGH);
    digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  } else {
    Serial.println("backward");
    digitalWrite(LEFT_MOTOR_REV, HIGH);
    digitalWrite(RIGHT_MOTOR_REV, HIGH);
  }

  delay(ms);

  // Stop the rover after moving.
  stopRover();
}

void squareForwards(int turnAddition) {
  // Draw a square by moving forwards.
  moveFB(1500, true);
  turn(RIGHT, 1150 + turnAddition);
  adjust();
  delay(250);
  moveFB(1500, true);
  turn(RIGHT, 1175 + turnAddition);
  adjust();
  delay(250);
  moveFB(1625, true);
  turn(RIGHT, 1250 + turnAddition);
  adjust();
  delay(250);
  moveFB(1800, true);
}

void squareBackwards(int turnAddition) {
  // Draw a square by moving backwards
  moveFB(1500, false);
  turn(RIGHT, 1200 + turnAddition);
  adjust();
  delay(250);
  moveFB(1625, false);
  turn(RIGHT, 1225 + turnAddition);
  adjust();
  delay(250);
  moveFB(1575, false);
  turn(RIGHT, 1250 + turnAddition);
  adjust();
  delay(250);
  moveFB(1800, false);
}

void eight() {
  // Draw a figure of eight by drawing two squares and turning to the original direction.
  squareForwards(0);
  delay(250);
  squareForwards(75);
}

void eightReverse() {
  // Draw a figure of eight by drawing two squares.
  squareBackwards(15);
  delay(250);
  squareBackwards(150);
}

void turn(int d, int t) {
  // Turn in the specified direction for the specified time.
  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);
  if (d == LEFT) {
    digitalWrite(LEFT_MOTOR_REV, HIGH);
    digitalWrite(RIGHT_MOTOR_FWD, HIGH);
    delay(t);
  } else if (d == RIGHT) {
    digitalWrite(LEFT_MOTOR_FWD, HIGH);
    digitalWrite(RIGHT_MOTOR_REV, HIGH);
    delay(t);
  }
  // Stop the rover after turning.
  stopRover();
}

void straightLine(int pulses) {
  // Move in a straight line, with adjustments applied, for the specified number of pulses.
  if (leftCounter > pulses) {
    // The rover has completed movement, turn it off and reset counter.
    leftCounter = 0;
    stopRover();
    return;
  }
  // Enable both motor's forward pins.
  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  digitalWrite(LEFT_MOTOR_FWD, HIGH);

  // Write the motor-specific powers.
  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);

  adjust();

  // Delay to prevent too much adjustment.
  delay(500);
  loops++;
}

void adjust() {
  // Adjust motor power
  int diff = rightCounter - leftCounter;
  int change = abs(diff) > 20 ? 12 : 6;
  if (abs(diff) > 1) { // Abs calculates the difference from zero
    if (diff > 0) {
      // Left is more powerful
      rightMotorPower += change; // Give more power to right motor.
      if (rightMotorPower > 255) rightMotorPower = 255; // Cap at 255.
    } else if (diff > 0) {
      // Right is more powerful
      leftMotorPower += change; // Give more power to left motor.
      if (leftMotorPower > 255) leftMotorPower = 255; // Cap at 255.
    }
  }

  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);
  // debugMotors();
}

void stopRover() {
  // Stop the rover by turning off the "ENABLE" and "FWD"/"REV" pins.
  analogWrite(RIGHT_MOTOR_ENABLE, 0);
  analogWrite(LEFT_MOTOR_ENABLE, 0);
  digitalWrite(RIGHT_MOTOR_FWD, LOW);
  digitalWrite(LEFT_MOTOR_FWD, LOW);
  digitalWrite(LEFT_MOTOR_REV, LOW);
  digitalWrite(RIGHT_MOTOR_REV, LOW);
  Serial.println("Rover stopped.");
}

void debugMotors() {
  // Debug counters
  Serial.print("Left: ");
  Serial.println(leftCounter);
  Serial.print("Right: ");
  Serial.println(rightCounter);
  Serial.print("L motor @ ");
  Serial.println(leftMotorPower);
  Serial.print("R motor @ ");
  Serial.println(rightMotorPower);
  Serial.flush();
}

