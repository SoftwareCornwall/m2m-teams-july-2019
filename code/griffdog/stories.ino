void story6(){
  forward(0);

  if (millis() >= 5000){
    hardstop(0);
    stopped = true;
  }
}

// Rover moves in a square formation
void story7(){
    forward(1000);
    hardstop(500);
    turnright(970);
    hardstop(500);
    forward(1000);
    hardstop(500);
    turnright(980);
    hardstop(500);
    forward(1000);
    hardstop(500);
    turnright(930);
    hardstop(500);
    forward(1000);
    hardstop(500);
    turnright(925);

//    // Do three times
//    for (int i = 0; i < 3; i++){
//      hardstop(500);
//
//      turnright(970 + (i * 2));
//
//      hardstop(500);
//      
//      forward(2000 + (i * 50));
//    }
//
//    hardstop(500);
//
//    turnright(985);
    
    // Stop rover completely permanently
    demo++;
    hardstop(0);
    if (!demoMode) stopped = true;
}

// Makes the rover move in a fowards figure of 8
void story8(){
    forward(1000);
    hardstop(500);
    
    turnright(880);
    hardstop(500);
    
    forward(1000);
    hardstop(500);
    
    turnright(994);
    hardstop(500);
    
    forward(2000);
    hardstop(500);
    
    turnleft(830);
    hardstop(500);
    
    forward(1000);
    hardstop(500);
    
    turnleft(890);
    hardstop(500);
    
    forward(1050);
    hardstop(500);
    
    turnleft(865);
    hardstop(500);
    
    forward(2300);
    
    // Stop rover completely permanently
    hardstop(0);
    if (!demoMode) stopped = true;

    demo += 2;
}

// Fowards and backwards figure of 8

void story9(){
    // Forwards
    forward(1000);
    hardstop(500);
    
    turnright(880);
    hardstop(500);
    
    forward(1000);
    hardstop(500);
    
    turnright(994);
    hardstop(500);
    
    forward(2000);
    hardstop(500);
    
    turnleft(800);
    hardstop(500);
    
    forward(1000);
    hardstop(500);
    
    turnleft(860);
    hardstop(500);
    
    forward(1050);
    hardstop(500);
    
    turnleft(780);
    hardstop(500);
    
    forward(2300);
    hardstop(1000);
     
    //Individual speed for each motor so it goes in a straight line
    
    leftSpeed = 255;
    rightSpeed = 240;
    
    //REVERSE

    // Go backward 2s 
    backward(2000);   
    
    // Stop 1s
    hardstop(1000);
    
    
    // Turn right 0.805s
    turnright(900);
    
    // stop 0.5s
    hardstop(500);

    backward(1000);
    hardstop(500);
    
    turnright(980);
    hardstop(500);
    
    backward(1000);
    hardstop(500);
    
    turnright(940);
    hardstop(500);
    
    backward(2000);
    hardstop(500);
    
    turnleft(865);
    hardstop(500);

    backward(880);
    hardstop(500);

    turnleft(840);
    hardstop(500);

    backward(870);
    hardstop(500);

    
    hardstop(0);
    stopped = true;
}

// Go forward until there is something 20cm in front of the rover,
// then it stops and turns left
void story10(){
    forward(0);

    if (fwd.ping_cm() < 20){
      hardstop(800);
      if (!demoMode) turnleft(800);
      else {
        turnleft(1840);
        forward(1800);
      }

      // Stop rover completely permanently
      hardstop(0);
      if (!demoMode) stopped = true;
      demo++;
    }
  delay(50);
}

// Go forward until there is a drop 5cm in front of the rover,
// then it stops and reverses 10cm
void story11(){
    forward(0);

    if (dwn.ping_cm() > 17){
      hardstop(800);
      if (!demoMode) backward(500);
      else {
        backward(600);
        turnleft(1880);
      }

      // Stop rover completely permanently
      hardstop(0);
      if (!demoMode) stopped = true;
      demo += 1;
    }
  delay(50);
}

// Rover follows light
void story12(){
    forward(0);

    // Light sensor readings
    int right = analogRead(2);
    int middle = analogRead(6);
    int left = analogRead(7);

    // If the light is brightest on the right
    if (right < middle && right < left){
      turnright(50);
      forward(0);
    } 
    /* If the light is brightest on the right */
    else if (left < middle && left < right){
      turnleft(50);
      forward(0);
    } else {
      forward(0);
    }
  delay(50);
}

// Rover follows light then stops if there is a drop infront of it
// then reverses
void story13(){
    forward(0);

    // If there is a drop of 17 or more centimetres in front of the rover
    if (dwn.ping_cm() > 17){
      hardstop(0);
      backward(1000);
      softstop(0);
    }

    // Light sensor readings
    int right = analogRead(2);
    int middle = analogRead(6);
    int left = analogRead(7);

    // If the light is brightest on the right
    if (right < middle && right < left){
      turnright(50);
      forward(0);
    } 
    /* If the light is brightest on the right */
    else if (left < middle && left < right){
      turnleft(50);
      forward(0);
    } else {
      forward(0);
    }
  delay(50);
}

// Like story 13, but if there is an object in front
// of the rover then it stops, reverses and turns left
void story14(){
    forward(0);

    // If there is an object 20cm in front of the rover
    if (fwd.ping_cm() < 20 && fwd.ping_cm() > 0){
      hardstop(0);
      backward(200);
      turnleft(800);
      softstop(0);
    }

    // If there is a drop of 17 or more centimetres in front of the rover
    if (dwn.ping_cm() > 17){
      hardstop(0);
      backward(1000);
      softstop(0);
    }

    // Light sensor readings
    int right = analogRead(2);
    int middle = analogRead(6);
    int left = analogRead(7);

    // If the light is brightest on the right
    if (right < middle && right < left){
      turnright(50);
      forward(0);
    }
    /* If the light is brightest on the right */
    else if (left < middle && left < right){
      turnleft(50);
      forward(0);
    } else {
      forward(0);
    }
  delay(50);
}

// A demonstration of all that our rover can do
void story16(){

  demoMode = true;
  
  if (demo == 7){
  
    // Square
    story7();
    
    if (demo == 8) delay(1000);

  } else if (demo == 8){

    // Forwards Fig8
    story8();
    
    if (demo == 10) delay(1000);

  } else if (demo == 10){

    // Stop before hitting obstacle
    story10();
    
    if (demo == 11) delay(2000);

  } else if (demo == 11){

    // Stop before dropping
    story11();
    
    if (demo == 12) delay(1000);

  } else if (demo == 12){

    // Follow light
    story12();

  }

  
}

void followHand(){

  // Light sensor readings
    int right = analogRead(2);
    int middle = analogRead(6);
    int left = analogRead(7);

    if (right > middle && right > left){
      turnright(50);
      forward(0);
    }
    /* If the light is brightest on the right */
    else if (left > middle && left > right){
      turnleft(50);
      forward(0);
    } else {
      forward(0);
    }
  delay(50);
}


