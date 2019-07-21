//list of variables
int right_motor_feedback = 3;
int left_motor_feedback = 2;
int ultrasonic_fwd_trigger = 4;
int ultrasonic_fwd_echo = 5;
int reserved_for_servo = 6;
int left_motor_reverse = 7;
int left_motor_forwards = 8;
int left_motor_enabler = 9;
int right_motor_enabler = 10;
int right_motor_reverse = 11;
int right_motor_forwards = 12;
int motorspeedR = 175;
int motorspeedL = 175;
int thresholdL = 5;
int thresholdR = 10;
int count = 0;
volatile int rightcounter = 0; //counter starts at 0 revolutions per second
volatile int leftcounter = 0;
int timedelay = 0;
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(left_motor_reverse, OUTPUT);
  pinMode(left_motor_forwards, OUTPUT);
  pinMode(left_motor_enabler, OUTPUT);
  pinMode(right_motor_enabler, OUTPUT);
  pinMode(right_motor_reverse, OUTPUT);
  pinMode(right_motor_forwards, OUTPUT);
  countersLR();
  
}

// the loop function runs over and over again forever
void loop() {
  //first edge and turn
  forwardsquare(1500);
  stoprover();
  
  rightturn(82);
  stoprover();

  //second edge and right turn
  forwardsquare(1500);
  stoprover();
 
  rightturn(79);
  stoprover();
  //third edge and right turn
  forwardsquare(1500);
  stoprover();
  
  rightturn(77);
  stoprover();
  //fourth edge and right turn
  forwardsquare(1500);
  stoprover();
  
  rightturn(79);
  stoprover();
  digitalWrite(left_motor_enabler, LOW);
  digitalWrite(right_motor_enabler,LOW);
  delay(60000);
  
    
  }
  
  /*
    //makes the rover move forwards
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    delay(500);
    digitalWrite(left_motor_forwards, HIGH);
    digitalWrite(right_motor_forwards, HIGH);
    square();
    stabalises the rover by checking the revolutions of each 
    motor to see if they are equal, and adjusting them
    while (timedelay < 100) {
        if (leftcounter > rightcounter + thresholdL) {
          motorspeedR = motorspeedR + 5;
          motorspeedL = motorspeedL - 5;
          analogWrite(left_motor_enabler, motorspeedL);
          analogWrite(right_motor_enabler,motorspeedR);
          //delay(25);
          }
        else if (rightcounter > leftcounter + thresholdR) {
          motorspeedL = motorspeedL + 5;
          motorspeedR = motorspeedR - 5;
          analogWrite(left_motor_enabler, motorspeedL);
          analogWrite(right_motor_enabler,motorspeedR);
          //delay(25);        
          }
        delay(200);
        timedelay = timedelay + 1;
        //makes the code run for 10 seconds
   if (millis() > 10000) {
     analogWrite(left_motor_enabler, LOW);
     analogWrite(right_motor_enabler,LOW);
        }
      }
    //makes the rover reverse for one second
    digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    delay(1000);
    digitalWrite(left_motor_reverse, HIGH);
    digitalWrite(right_motor_reverse, HIGH);
    delay(1000);
    */


//----------------------------------------------------------------------------

void rightturn(int turncounter) {
  leftcounter = 0;
  while (leftcounter <= turncounter) {
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    digitalWrite(left_motor_forwards, HIGH);
    digitalWrite(right_motor_forwards, LOW);
    digitalWrite(left_motor_reverse, LOW);
    digitalWrite(right_motor_reverse, HIGH);
  }
}


void stoprover() {
  digitalWrite(left_motor_forwards, LOW);
  digitalWrite(right_motor_forwards, LOW);
  digitalWrite(left_motor_forwards, LOW);
  digitalWrite(right_motor_forwards, LOW);
  digitalWrite(left_motor_reverse, LOW);
  digitalWrite(right_motor_reverse, LOW);
  delay(500);
  
}


void forwardsquare(int delaytime) {
  analogWrite(left_motor_enabler, motorspeedL);
  analogWrite(right_motor_enabler,motorspeedR);
  digitalWrite(left_motor_forwards, HIGH);
  digitalWrite(right_motor_forwards, HIGH);
  digitalWrite(left_motor_reverse, LOW);
  digitalWrite(right_motor_reverse, LOW);
  delay(delaytime);
  }

//adds the attachInteruppt to the rovers motor feedback so that we can count the revolutions  
void countersLR()
{
    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(right_motor_feedback),right_motor_isr, RISING);
    attachInterrupt(digitalPinToInterrupt(left_motor_feedback),left_motor_isr, RISING);
}
//adds one to the counter per revolution of the motors
void left_motor_isr() {
    leftcounter++;
  }

void right_motor_isr() {
    rightcounter++;
  }

//HIGH=255
//makes the rover move at a set speed in the variable
void roverforward(int delaytime)
{ 
    digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    delay(delaytime);
}

/*makes the rover move in a square formation by disabling the 
left enabler so that the rover rotates 90degrees to the right*/
void square() {
  while (count < 4) {
    digitalWrite(left_motor_reverse, LOW);
    digitalWrite(left_motor_forwards, HIGH);
    digitalWrite(right_motor_forwards, HIGH);
    delay(2500);
    digitalWrite(left_motor_forwards, LOW);
    rightcounter = 0;
    while (rightcounter != 90) {
      digitalWrite(right_motor_forwards, HIGH);
      digitalWrite(left_motor_reverse, HIGH);
      
    }
    count = count + 1;
  }
}

