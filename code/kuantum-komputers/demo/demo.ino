
//Demonstration code for presentation 
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
int state = 0;
const int straight_line_state = 0;
const int state_get_off_ramp = 1;
const int state_forward_zig_zag = 2;
const int state_backwards_zig_zag = 3;
const int state_figure_of_eight = 4;
const int state_end = 5;
volatile int rightcounter = 0; //counter starts at 0 revolutions per second
volatile int leftcounter = 0;
int timedelay = 0;

#include <NewPing.h>

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 15 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
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
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);                       // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);
  // wait for a second  
  //blue=reverse, red=forward
  //test 
  //roverforward(500);
    
   switch(state) {
    case straight_line_state:
      line();
      break;
    case (state_get_off_ramp):
      digitalWrite(left_motor_enabler, motorspeedL);
      digitalWrite(right_motor_enabler, motorspeedR);
      digitalWrite(left_motor_reverse, HIGH);
      digitalWrite(right_motor_reverse, HIGH);
      delay(6000);
      stoprover();
      state = 2;
      break;
    case (state_forward_zig_zag):
      zigzag();
      break;
    case (state_backwards_zig_zag):
      state = 4;
      break;
    case (state_figure_of_eight):
      rightsquare();
      leftsquare();
      state = 5;
      break;
    case (state_end):
      digitalWrite(left_motor_forwards, HIGH);
      digitalWrite(right_motor_forwards, HIGH);
      delay(5000);
      stoprover();
      leftturn(80);
      stoprover();
      digitalWrite(left_motor_reverse, HIGH);
      digitalWrite(right_motor_reverse, HIGH);
      delay(200);
      digitalWrite(left_motor_reverse, LOW);
      digitalWrite(right_motor_reverse, LOW);
      digitalWrite(left_motor_forwards, HIGH);
      digitalWrite(right_motor_forwards, HIGH);
      delay(200);
      stoprover();
      state = 6;
      break;
    }
}
   
    
    /*digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    delay(1000);
    digitalWrite(left_motor_reverse, HIGH);
    digitalWrite(right_motor_reverse, HIGH);
    delay(1000);*/

  
/*if (millis() > 10000) {
     analogWrite(left_motor_enabler, LOW);
     analogWrite(right_motor_enabler,LOW);
        }*/




