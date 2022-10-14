const int PIN_12 = 12;  
const int TITIK = 300;
const int PANJANG = 900;
const int JEDA = 400;
const int MATI = 100;

void setup() {
  // Tugas kelompok minggu kedua dari.
  // 1. Farhan Aziz [2113191097]
  // 2. Isep Lutpi Nur [2113191079]
  // 3. Muhammad Bayu Ramadhani [2113191081]
  // 4. Muhammad Taufik Ali [2113191067]
  
  // put your setup code here, to run once:
  pinMode(PIN_12,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  // Kirim satu titik
  digitalWrite(PIN_12,HIGH);
  delay(TITIK);
  digitalWrite(PIN_12,LOW);
  delay(MATI);
  digitalWrite(PIN_12,HIGH);
  delay(TITIK);
  digitalWrite(PIN_12,LOW);
  delay(MATI);
  delay (JEDA);

  digitalWrite(PIN_12,HIGH);
  delay(PANJANG);
  digitalWrite(PIN_12,LOW);
  delay(MATI);
  digitalWrite(PIN_12,HIGH);
  delay(PANJANG);
  digitalWrite(PIN_12,LOW);
  delay(MATI);
  digitalWrite(PIN_12,HIGH);
  delay(PANJANG);
  digitalWrite(PIN_12,LOW);
  delay(MATI);
  delay (JEDA);
}