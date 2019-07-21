
volatile int LeftBack = 7,    RightBack = 11,
    LeftEnable = 9,  RightEnable = 10,
    LeftForward = 8, RightForward = 12,
    LeftFeedback =2, RightFeedback = 3,
    LeftCount = 0,   RightCount = 0,
    LeftPower = 128, RightPower = 128;

void setup() {
  //for (int i = 2; i < 7; i++ ) pinMode(i, OUTPUT);
  Serial.begin(9600);
  
  analogWrite(LeftEnable, 255);
  analogWrite(RightEnable, 255);
  attachInterrupt(digitalPinToInterrupt(LeftFeedback), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RightFeedback), RightMotorISR, RISING);
} 

void loop() {
 Move();
}

void Move() {
  while(millis() <= 10000){
    if (LeftCount <= RightCount){
      //LeftPower += 64;
      //RightPower -= 64;
      analogWrite(LeftForward, 128);
    }
    if (RightCount <= LeftCount){
      //LeftPower -= 64;
      //RightPower += 64;
      analogWrite(RightForward, 128);
    }
    //analogWrite(RightForward, RightPower);
    //analogWrite(LeftForward, LeftPower);
    //delay(250);
  }
  //LeftCount = RightCount = 0;
  analogWrite(RightForward, 0);
  analogWrite(LeftForward, 0);
}

void LeftMotorISR() {
  LeftCount++;
}

void RightMotorISR() {
  RightCount++;
}

