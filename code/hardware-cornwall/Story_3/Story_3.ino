int LeftBack = 2,    RightBack = 5,
    LeftNeutral = 3, RightNeutral = 6,
    LeftForward = 4, RightForward = 7;

void setup() {
  for (int i = 2; i < 7; i++ ) pinMode(i, OUTPUT);
}

void loop() {
  digitalWrite(LeftForward, HIGH);
  digitalWrite(RightForward, HIGH);
  delay(10000);
  digitalWrite(LeftForward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftNeutral, HIGH);
  digitalWrite(RightNeutral, HIGH);
  delay(375);
  digitalWrite(LeftNeutral, LOW);
  digitalWrite(RightNeutral, LOW);
  digitalWrite(LeftBack, HIGH);
  digitalWrite(RightBack, HIGH);
  delay(1000);
  digitalWrite(LeftBack, LOW);
  digitalWrite(RightBack, LOW);
  delay(2000);
}
