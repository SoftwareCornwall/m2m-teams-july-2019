// all the sequenced functions for the stories.

void runFromLight() {
  if (midlight() < 150) {
    turn90clock();
    turn90clock();
    fwd(100);
  }
  else {
    ifwd();
  }
}

void criticalEscape() {
  getPings();
  if (15 < dpng and dpng < 25) { // if there is a small cliff
    getDownCliff();
  }
  else if (dpng <= 15) { // if there is no cliff
    ifwd();
  }
  else { // if there is a cliff, reverses and gets it's fat ass outta dat cliff
    getAroundCliff();
  }
}

void criticalEscapeV2() {
   bool complete = false;
   while (!complete) {   
    getPings();
    if (not obstacle()) {
      if (15 < dpng and dpng < 25) { // if there is a small cliff
        getDownCliff();
      }
      else if (dpng <= 15) { // if there is no cliff
        ifwd();
      }
      else { // if there is a cliff, reverses and gets it's fat ass outta dat cliff
        getAroundCliff();
      }
    }
    else {
      pauseTime(500);
      back(250);
      turn90clock();
      fwd(1000);
      complete = true;
    }
  }
}

void followBeaconAvoidCliffsAndObstacles() {
  getPings();
  if (not obstacle()) { // as long as there isn't an obstacle within 20 cm ahead of it
    followBeaconAvoidCliffs();
  }
  else { // there is an obstacle:
    pauseTime(1000);
    back(500); // reverses to give room for the turn
    turn90anti_clock(); // turns away from the obstacle
  }
}

void followBeaconAvoidCliffs() {
  getPings();    
  if (clearLightSource()) {  // if there is a clear light source:
    if (dpng < 15) {mtl();} // as long as it's less than 15 cm from the ground (no cliff)
      // it moves towards the light
    else {getAroundCliff();} // if there is a cliff, reverses and gets it's fat ass outta dat cliff
  }
  else { // if there isn't a clear light source, it turns 90 to try to find it
    turn90clock();
  }
}

void followBeacon() {
  if (clearLightSource()){  // if there is a clear light source:
    if (leftlight() < midlight()) {
      superAntiClock();
      delay(100);
    }
    else if (rightlight() < midlight()) {
      superClock();
      delay(100);
    }
    else {
      fwd(100); 
    }
  }
  else{ // if there isn't a clear light source, it turns 90 to try to find it
    turn90clock();
  }
}

void followBeaconPwrSave() { // follows a light beacon using only 2 of the 3 sensors, has a slight blind spot but it does find it's way
  if (leftlight()<500 or rightlight()<500) { // clear light source
    if (((leftlight() - rightlight()) > 50) or ((rightlight() - leftlight()) > 50)) { // difference between the two sensors to check if the light is coming from the front
      if (leftlight() > rightlight()) { // if light is coming from the right
        superClock(); // turn right really fast
        delay(100); // for .1 seconds
      }
      else { // light must be coming from the left
        superAntiClock(); // turn left really fast
        delay(100); // for .1 seconds
      }
    }
    else { // not a big enough difference between the sensors, light must be coming from the front:
      fwd(100); // move forward
    }
  }
  else { // no clear light source
    turn90clock(); // turn to try to find the clear light source 
  }
}

void moveTillObstacle() {
  getPings();
  ifwd();
  if (obstacle()) {
    pauseTime(2000);
    turn90anti_clock();
    finish(); 
  } 
}

void moveTillCliff() {
  getPings();
  ifwd();
  if (dpng > 15 and dpng > 0) {
    pauseTime(2000);
    back(500);
    finish(); 
  } 
}

void sEight() { // smooth eight
  turn(8000, 255, 80);
  turn(8000, 80, 255);
}

void fEight() { // makes a figure of eight forward
  fCsquare();
  fACsquare();
}

void bEight() { // makes a figure of eight backwards
  bACsquare();
  bCsquare(); 
}
