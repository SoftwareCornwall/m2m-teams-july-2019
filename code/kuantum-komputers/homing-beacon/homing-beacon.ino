int sensor_left = 0;
int sensor_right = 1;
int sensor_middle = 2;
int ambient_light = 230;
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

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(left_motor_reverse, OUTPUT);
  pinMode(left_motor_forwards, OUTPUT);
  pinMode(left_motor_enabler, OUTPUT);
  pinMode(right_motor_enabler, OUTPUT);
  pinMode(right_motor_reverse, OUTPUT);
  pinMode(right_motor_forwards, OUTPUT);
  pinMode(sensor_left, INPUT);
  pinMode(sensor_right, INPUT);
  pinMode(sensor_middle, INPUT);
  countersLR();
  
}

void loop() {
  int Light_level_left = analogRead(sensor_left);
  int Light_level_right = analogRead(sensor_right);
  int Light_level_middle = analogRead(sensor_middle);

  if (Light_level_left < ambient_light or Light_level_right < ambient_light or Light_level_middle < ambient_light){
    if (Light_level_left < Light_level_right and Light_level_left < Light_level_middle){
      leftturn(5);
      stoprover();    
    }
    if (Light_level_right < Light_level_left and Light_level_right < Light_level_middle){
      rightturn(5);
      stoprover();
    }
    if (Light_level_middle < Light_level_right and Light_level_middle < Light_level_left) {
     forwardsquare(700);
     stoprover();
  }
  }
}
  



