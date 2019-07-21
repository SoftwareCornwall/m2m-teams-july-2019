void printthings(){
  Serial.println(counterL);
  Serial.print(counterL);

  Serial.println(counterR);
  Serial.print(counterR);  
  //displays the rotation counter of the wheels
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); 
  // Send ping, get distance in cm and print result 
  //(0 = outside set distance range)
  Serial.println("cm");
}

void backf8(){
  back(); // backwards figure of 8 starts here
  // this is for challenge 8
  delay (1000);
  turnright();
  delay (1000);
  back();
  delay (1000);
  turnright();
  delay (1000);
  back();
  delay (1000);
  turnright();
  delay (1000);
  back();
  delay (1000);
  back();
  delay (1000);
  turnleft();
  delay (1000);
  back();
  delay (1000);
  turnleft();
  delay (1000);
  back();
  delay (1000);
  turnleft();
  delay (1000);
  back();
  delay (1000); // 1 sec delay
}

void fwd3(){ //a short forward command
  digitalWrite(motorLenb, HIGH);
  digitalWrite(motorRenb, HIGH);
  digitalWrite(motorLfwd, HIGH);
  digitalWrite(motorRfwd, HIGH);
  delay (1000);              
  // Creates a delay for 2 seconds
  stop();                    
  // Stops the programme 
}

void fwd2(){ 
  //an even shorter forward command
  digitalWrite(motorLenb, HIGH);
  digitalWrite(motorRenb, HIGH);
  digitalWrite(motorLfwd, HIGH);
  digitalWrite(motorRfwd, HIGH);
  delay (1000);              
  // Creates a delay for 1 seconds
  stop();
}

void fwd10(){ 
  //Sends rover straight for 10 seconds
  //uses counter values to keep direction
  if (counterL < counterR) {
    motorLspd = motorLspd + 1;
    motorRspd = motorRspd - 1;
  } else if (counterL > counterR) {
    motorLspd = motorLspd - 1;
    motorRspd = motorRspd + 1;
  }
  
  analogWrite(motorLenb, motorLspd);
  analogWrite(motorRenb, motorRspd);
  
  digitalWrite(motorLfwd, HIGH);
  digitalWrite(motorRfwd,HIGH);
  
  if (millis() > 10000){ 
    //checks for 10 seconds to have passed
    analogWrite(motorLfwd, 0);
    analogWrite(motorRfwd, 0);
  }
}






void fwd2Meter(){ 
  //sends robot forward for 2 meters
  analogWrite(motorLenb, motorLspd); 
  //enables both motors with corrected speeds
  analogWrite(motorRenb, motorRspd);
  
  digitalWrite(motorLfwd, HIGH); 
  //sets forward to high
  digitalWrite(motorRfwd, HIGH);
  if (counterR > 940){ 
    //940 is correct amount of wheel rotations 
    //(Pulses) for 2 meters
    stop(); //turns movement off
  }
}


// Starts the forward figure of 8
// this is for challenge 7 and 8


