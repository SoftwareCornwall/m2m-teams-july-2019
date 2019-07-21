int LeftBack = 7,    RightBack = 11,
    LeftEnable = 9, RightEnable = 10,
    LeftForward = 8, RightForward = 12;

void setup() {
  for (int i = 2; i < 7; i++ ) pinMode(i, OUTPUT);
  digitalWrite(LeftEnable, HIGH);
  digitalWrite(RightEnable, HIGH);
}

void loop() {
  digitalWrite(LeftForward, HIGH);
  digitalWrite(RightForward, HIGH);
  delay(1000);
  digitalWrite(LeftForward, LOW);
  digitalWrite(RightForward, LOW);
  delay(1000);
  digitalWrite(LeftBack, HIGH);
  digitalWrite(RightBack, HIGH);
  delay(1000);
  digitalWrite(LeftBack, LOW);
  digitalWrite(RightBack, LOW);
  delay(2000);
}
