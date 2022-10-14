const int pin = 12;

void setup()
{
   pinMode(pin, OUTPUT);
}

void loop()
{
  hurufA();
}

void hurufA() {
  pendek();
  jeda();
  panjang();
  jeda();
  
}

void jedaHuruf() {
  digitalWrite(pin, LOW);
  delay(1000);
}

void jeda() {
  digitalWrite(pin, LOW);
  delay(100);
}

void panjang() {
  digitalWrite(pin, HIGH);
  delay(500);
}

void pendek() {
  digitalWrite(pin, HIGH);
  delay(200);
}
