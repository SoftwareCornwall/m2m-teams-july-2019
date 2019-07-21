#include <NewPing.h>

/**
   Move forwards or backwards.
   Basic function: no adjustments are applied. The rover may not move completely straight.

   Parameter forward:
    true = forward
    false = backward
*/
void moveFB (int ms, bool forward) {
  if (forward) {
    digitalWrite(LEFT_MOTOR_FWD, HIGH);
    digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  } else {
    digitalWrite(LEFT_MOTOR_REV, HIGH);
    digitalWrite(RIGHT_MOTOR_REV, HIGH);
  }

  // Move for the specified time.
  delay(ms);

  // Stop the rover after moving.
  stopRover();
}

void followLight() {
  int middle = analogRead(LS_MIDDLE);
  int left = analogRead(LS_LEFT);
  int right = analogRead(LS_RIGHT);

  if (middle > left && middle > right) {
    // Middle is brightest. Continue forward.
    moveFB(2000, true);
  } else if (left > middle && left > right) {
    // Left is brightest. Turn left.
    turn(LEFT, 200);
  } else if (right > middle && right > left) {
    // Right is brightest. Turn right.
    turn(RIGHT, 200);
  }
}

/**
   Turn in the specified direction and stops rover.

   Parameter d:
    0 = LEFT
    1 = RIGHT
*/
void turn(int d, int t) {
  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);
  // Decide the direction and power motors appropriately.
  if (d == LEFT) {
    digitalWrite(LEFT_MOTOR_REV, HIGH);
    digitalWrite(RIGHT_MOTOR_FWD, HIGH);
    delay(t);
  } else if (d == RIGHT) {
    digitalWrite(LEFT_MOTOR_FWD, HIGH);
    digitalWrite(RIGHT_MOTOR_REV, HIGH);
    delay(t);
  }

  // Turn off all pins after turning.
  stopRover();
}

/**
   Draw a square by moving forwards.

   Parameter turnAddition: added offset to each turn for adjustments.
*/
void squareForwards(int turnAddition) {
  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);
  moveFB(1500, true);
  turn(RIGHT, 1150 + turnAddition);
  adjust();
  moveFB(1500, true);
  turn(RIGHT, 1175 + turnAddition);
  adjust();
  moveFB(1575, true);
  turn(RIGHT, 1200 + turnAddition);
  adjust();
  moveFB(1800, true);
}

/**
   Draw a square by moving backwards.

   Parameter turnAddition: added offset to each turn for adjustments.
*/
void squareBackwards(int turnAddition) {
  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);
  moveFB(1500, false);
  turn(RIGHT, 1150 + turnAddition);
  adjust();
  moveFB(1500, false);
  turn(RIGHT, 1175 + turnAddition);
  adjust();
  moveFB(1575, false);
  turn(RIGHT, 1200 + turnAddition);
  adjust();
  moveFB(1800, false);
}

/**
   Draw a figure of eight by drawing two squares and turning to the original direction.
*/
void eight() {
  squareForwards(-25);
  squareForwards(60);
  turn(RIGHT, 1200);
  turn(RIGHT, 1100);
}

/**
   Move in a staight line for the specified number of pulses.
   Adjustments are applied to ensure the rover moves completely straight.
   This function must be called every loop to ensure that adjustments can be applied.

   Returns: true when complete, false when needs to continue.
*/
bool straightLine(int pulses) {
  if (leftCounter > pulses) {
    // The rover has completed movement for the pulses; stop it and reset the counters.
    leftCounter = 0;
    rightCounter = 0;
    stopRover();

    return true;
  }
  // Set the forward pins to HIGH, to move the rover forward.
  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  digitalWrite(LEFT_MOTOR_FWD, HIGH);

  // Write the correct power values to the ENABLE pins.
  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);

  // Run adjustments.
  adjust();

  // Delay for 500ms to prevent over-adjustments.
  delay(500);

  // Not done yet, return false.
  return false;
}

/**
   Move in a straight line, avoiding obstacles in front of the rover.

   Returns: true if the rover has turned, otherwise false.
*/
bool straightLineAvoid(int turnDirection) {
  int distance = sonarFwd.ping_cm(); // Distance in cm. Caps at 200.
  if (distance > 0 && distance < 24) {
    // Receiving signal which is less than 24, but not 0.
    // Stop rover, pause, and turn.
    stopRover();
    delay(1000);
    turn(turnDirection, 1050);
    return true; // Done. Return true.
  }

  // Set the rover to go forwards.
  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  digitalWrite(LEFT_MOTOR_FWD, HIGH);

  // Write the correct power values.
  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);

  return false; // Rover has not yet encountered anything.
}

/**
   Move forwards only where there is more than 5cm of distance from the floor.
   The distance between the sensors and ground is initially 10cm, so we need to add 5 for 15.
*/
bool straightLineNoFall() {
  int distance = sonarDwn.ping_cm(); // Distance in cm. Caps at 200.
  Serial.println(distance);
  if (distance > 0 && distance > 15) {
    // Receiving signal which is more than 18
    hardStop();
    delay(1000);
    // Ensure all pins are turned off.
    stopRover();
    // Write the correct power values to move back.
    analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
    analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);
    // Move backwards for 2.5 seconds.
    moveFB(5000, false);
    delay(50000);
    return true;
  }

  // By defuault, keep moving forward.
  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  digitalWrite(LEFT_MOTOR_FWD, HIGH);

  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);

  return false;
}

/**
   Adjust motor power based on the pulses for each motor.
*/
void adjust() {
  int diff = rightCounter - leftCounter;
  int change = abs(diff) > 20 ? 12 : 6;
  if (abs(diff) > 1) { // Abs calculates the difference from zero
    if (diff > 0) {
      // Left is more powerful
      rightMotorPower += change; // Give more power to right motor.
      rightMotorPower = min(255, rightMotorPower); // Cap at 255.
    } else if (diff > 0) {
      // Right is more powerful
      leftMotorPower += change; // Give more power to left motor.
      leftMotorPower = min(255, leftMotorPower); // Cap at 255.
    }
  }

  analogWrite(LEFT_MOTOR_ENABLE, leftMotorPower);
  analogWrite(RIGHT_MOTOR_ENABLE, rightMotorPower);
  // debugMotors();
}

/**
   Fight fire with fire.
   (Stops the rover quickly.)
*/
void hardStop() {
  Serial.println("Hard stopping.");
  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  digitalWrite(RIGHT_MOTOR_REV, HIGH);
  digitalWrite(LEFT_MOTOR_FWD, HIGH);
  digitalWrite(LEFT_MOTOR_REV, HIGH);
}

/**
   Stop the rover by turning off all pins.
*/
void stopRover() {
  analogWrite(RIGHT_MOTOR_ENABLE, 0);
  analogWrite(LEFT_MOTOR_ENABLE, 0);
  digitalWrite(RIGHT_MOTOR_FWD, LOW);
  digitalWrite(RIGHT_MOTOR_REV, LOW);
  digitalWrite(LEFT_MOTOR_FWD, LOW);
  digitalWrite(LEFT_MOTOR_REV, LOW);
  Serial.println("Rover stopped.");
}

/**
   Debug counters.
   May slow down execution of other instructions. :(
*/
/*
void debugMotors() {
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
*/
