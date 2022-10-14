const int PIN_10 = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_10, OUTPUT);
  analogWrite(PIN_10,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<256;i++) {
      analogWrite(PIN_10,i);
      delay(5);
  }
  delay(2000);
  for(int i=256;i<=1;i--) {
      analogWrite(PIN_10,i);
      delay(5);
  }
  delay(2000);
}
