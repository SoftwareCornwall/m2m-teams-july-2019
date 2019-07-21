// ----> Use quizbot.xyz

#include <NewPing.h>

void moveFB (int ms, bool forward) {
  if (forward) {
    digitalWrite(LEFT_MOTOR_FWD, HIGH);
    digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  } else {
    digitalWrite(LEFT_MOTOR_REV, HIGH);
    digitalWrite(RIGHT_MOTOR_REV, HIGH);
  }

  delay(ms);

  stopRover();
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
  if (leftCounter > pulses) {
    leftCounter = 0;
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

void straightLineAvoid(int turnDirection) {
  // Continuously goes forward until encountering object

  int distance = sonar.ping_cm();
  Serial.println(distance);
  if (distance > 12 && distance < 24) {
    // Receiving signal which is less than 24
    Serial.println("Stopping :(");
    stopRover();
    turn(turnDirection, 950);
    delay(50000);
    return;
  }

  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  digitalWrite(LEFT_MOTOR_FWD, HIGH);

  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);

}

void straightLineNoFall() {
  
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
  // Stop the rover by turning off the "ENABLE" pins.
  analogWrite(RIGHT_MOTOR_ENABLE, 0);
  analogWrite(LEFT_MOTOR_ENABLE, 0);
  digitalWrite(RIGHT_MOTOR_FWD, LOW);
  digitalWrite(LEFT_MOTOR_FWD, LOW);
  digitalWrite(LEFT_MOTOR_REV, LOW);
  digitalWrite(RIGHT_MOTOR_FWD, LOW);
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

