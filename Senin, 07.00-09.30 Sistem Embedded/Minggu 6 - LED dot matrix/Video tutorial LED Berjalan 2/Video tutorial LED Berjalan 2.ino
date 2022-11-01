// Kelompok 
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]

void setup() {
  // set pin mode
  for(int i = 4; i <= 13; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // nyalakan LED satu per satu0
  for(int i = 4; i <= 13; i++){
    digitalWrite(i, HIGH);
    delay(15);
    digitalWrite(i, LOW);
  }

  for(int i = 13; i >= 4; i--){
    digitalWrite(i, HIGH);
    delay(15);
    digitalWrite(i, LOW);
  }
}
