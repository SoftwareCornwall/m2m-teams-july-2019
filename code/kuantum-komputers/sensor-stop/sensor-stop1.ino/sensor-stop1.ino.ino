// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

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




#include <NewPing.h>

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 15 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(left_motor_reverse, OUTPUT);
  pinMode(left_motor_forwards, OUTPUT);
  pinMode(left_motor_enabler, OUTPUT);
  pinMode(right_motor_enabler, OUTPUT);
  pinMode(right_motor_reverse, OUTPUT);
  pinMode(right_motor_forwards, OUTPUT);
  countersLR();
}


void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  //makes the rover move forwards
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    ///delay(500);
    digitalWrite(left_motor_forwards, HIGH);
    digitalWrite(right_motor_forwards, HIGH);
    /*stabalises the rover by checking the revolutions of each 
    motor to see if they are equal, and adjusting them*/
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
        //delay(200);
        //makes the code run for 10 seconds
   /*if (millis() > 10000) {
     analogWrite(left_motor_enabler, LOW);
     analogWrite(right_motor_enabler,LOW);*/

     int floor_distance = sonar.ping_cm();
     Serial.println(floor_distance);

     if (floor_distance >= 15 or floor_distance == 0) {
      digitalWrite(left_motor_forwards, LOW);
      digitalWrite(right_motor_forwards, LOW);
      delay(1000);
      digitalWrite(right_motor_reverse, HIGH);
      digitalWrite(left_motor_reverse, HIGH);
      delay(350);
      stoprover();
      delay(60000);
           
    }
}


