// Kelompok 
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]

const int PIN_8 = 8;
const int PIN_9 = 9;
const int PIN_10 = 10;
const int PIN_11 = 11;

void setup(){
  pinMode(PIN_8, OUTPUT);
  pinMode(PIN_9, OUTPUT);
  pinMode(PIN_10, OUTPUT);
  pinMode(PIN_11, OUTPUT);
}

void loop(){
  analogWrite(PIN_9, random(50)+100);
  analogWrite(PIN_10, random(156)+100);
  analogWrite(PIN_11, random(156)+100);
  delay(20);
}
