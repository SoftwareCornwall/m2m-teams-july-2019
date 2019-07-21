const int PIN_ONE = 2;
const int PIN_TWO = 3;

void setup() {
  pinMode(PIN_ONE, OUTPUT);
  pinMode(PIN_TWO, OUTPUT);
}

void loop() {
  flash(PIN_ONE);
  flash(PIN_TWO);
}

void flash(int pin) {
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
}

