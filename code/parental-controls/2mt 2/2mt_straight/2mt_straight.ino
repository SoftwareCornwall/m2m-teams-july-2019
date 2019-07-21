const int feedbackL = 2;
const int feedbackR = 3; //Here we define most of the varriables we use

#include <NewPing.h>
#define TRIGGER_DOWN 13
#define TRIGGER_PIN  4 
#define ECHO_PIN     5 
#define ECHO_DOWN    17  
#define MAX_DISTANCE 200 
NewPing sonar(TRIGGER_DOWN, ECHO_DOWN, MAX_DISTANCE); 
NewPing sonar2(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int motorLfwd = 8;  
int motorLbck = 7;  //Some of these variables are the pin numbers for specific functions such as motor controll
int motorLenb = 9;
int motorLspd = 200;

int motorRfwd = 12;
int motorRbck = 11;
int motorRenb = 10;
int motorRspd = 200;

int rightL = 2;
int leftL = 0;
int forwardL = 1;
volatile int counterL = 0;
volatile int counterR = 0;

void setup() //initialises the code
{
  Serial.begin(115200); 
  // Open serial monitor at 115200 baud to see ping results.
  pinMode(motorLfwd, OUTPUT);                 
  pinMode(motorLbck, OUTPUT); 
  pinMode(motorLenb, OUTPUT); 
  pinMode(motorRfwd, OUTPUT);  //Here we set variables for input/output modes
  pinMode(motorRbck, OUTPUT);
  pinMode(motorRenb, OUTPUT);
  
  pinMode(rightL, INPUT);
  pinMode(leftL, INPUT);
  pinMode(forwardL, INPUT); 
  sonar.ping_cm(); //sets motion detector to cm
}

bool booli = true; //DEMO

void loop() {
  delay(50);
  int distance = sonar2.ping_cm();
  if (distance >= 20 or distance == 0){
    forward();
  } 
  else{
    stop();
    turnleft();
    booli = false;
  }
  
  
  while (booli == false){
    delay(50); 
    int distance = sonar.ping_cm();
    Serial.println(distance);
    if (distance >= 15){ //checks for drop over 6
      stop();
      back10(); //if so, reverses for 10 secs
      booli = true;
      forwardf8();
      turnright();
      turnright();
      turnright();
      turnright();
      off();
    
    }  
    else {
      forward(); //else it continues to go forward
    }
  }
}

/*void loop(){
  int rightLnum = analogRead(rightL);
  int leftLnum = analogRead(leftL); //sets light values to variables
  int forwardLnum = analogRead(forwardL);
  
  Serial.print("Right : ");
  Serial.println(rightLnum);
  Serial.print("Left : ");
  Serial.println(leftLnum); //prints values for testing purposes
  Serial.print("Middle :");
  Serial.println(forwardLnum);
  delay(250);
   
   if (rightLnum < leftLnum and rightLnum < forwardLnum){
    stop();
    digitalWrite (motorRbck, HIGH); //if right is brightest, turn right
    digitalWrite (motorLfwd, HIGH);
    Serial.print ("A");
  }
  
  else if (leftLnum < rightLnum and leftLnum < forwardLnum){
    stop();
    digitalWrite (motorLbck, HIGH); //if left is brightest, turn left
    digitalWrite (motorRfwd, HIGH);
    Serial.print ("B");
  }
  
  else if (forwardLnum < rightLnum and forwardLnum < leftLnum){
    stop();
    digitalWrite (motorRfwd, HIGH); //if forward is brightest, go forward
    digitalWrite (motorLfwd, HIGH);
    Serial.print ("C");
  }
}
*/


  

void stop(){ 
  //Only turns off the directional motor commands
  //still enabled
  digitalWrite(motorLfwd, LOW);
  digitalWrite(motorRfwd, LOW);
  digitalWrite(motorLbck, LOW);
  digitalWrite(motorRbck, LOW);
}
  
void forwardf8(){ 
    
  fwd3();  
  turnright();
  fwd3();
  turnright();
  fwd3();
  turnright();  
  fwd3();
  turnleft();
  fwd3();
  turnright();
  fwd3();
  turnright();
  fwd3();
  turnright();
  fwd3();
  turnleft();
}

void off(){ //turns off enable for 1 minute
  // completely turns off everything
  digitalWrite(motorLenb, LOW);
  digitalWrite(motorRenb, LOW);
  stop();
  delay (60000);
}

void turnright() { //initialises a right turn when called
  digitalWrite(motorLenb, HIGH);
  digitalWrite(motorLfwd, HIGH); //left goes forward
  digitalWrite(motorRenb, HIGH);
  digitalWrite(motorRbck, HIGH); //right goes back
  delay(883); //changes angle of turn
  stop(); 
  counterL = 0;
  counterR = 0; //resets distance counter
}

void turnleft() { //initialises a left turn when called
  digitalWrite(motorRenb, HIGH);
  digitalWrite(motorRfwd, HIGH); //right goes forward
  digitalWrite(motorLenb, HIGH);
  digitalWrite(motorLbck, HIGH); //left goes back
  delay(883); //changes angle of turn
  stop();
  counterL = 0;
  counterR = 0; //resests distance counter
}

void LeftMotorISR(){
  counterL++; //adds to left counter for every rotation
}

void RightMotorISR(){
  counterR++; //adds to right counter for every rotation
}

void back(){ //initialises reverse
  digitalWrite(motorLenb, HIGH);
  digitalWrite(motorRenb, HIGH);

  digitalWrite(motorLbck, HIGH); 
  digitalWrite(motorRbck, HIGH);
  delay(1000); //for 2 seconds
  stop(); //stops all movement
}

void forward(){ //starts forward motors
  
  digitalWrite(motorLenb, HIGH);
  digitalWrite(motorRenb, HIGH);
  digitalWrite(motorLfwd, HIGH);
  digitalWrite(motorRfwd, HIGH);
}




















































void back10(){ //initialises reverse for 10 seconds
  counterR = 0;
  counterL = 0;
  digitalWrite(motorLenb, HIGH);
  digitalWrite(motorRenb, HIGH);

  digitalWrite(motorLbck, HIGH); 
  digitalWrite(motorRbck, HIGH);
  delay(5000);
  stop();
}



