const int PIN_9 = 9;
const int PIN_10 = 10;
const int PIN_11 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_9, OUTPUT);
  pinMode(PIN_10, OUTPUT);
  pinMode(PIN_11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_9, random(150)+100);
  digitalWrite(PIN_10, random(156)+100);
  digitalWrite(PIN_11, random(156)+100);
}
