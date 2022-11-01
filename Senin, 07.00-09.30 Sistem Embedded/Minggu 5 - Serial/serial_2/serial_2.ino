// Kelompok 
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]

// serial komunikasi komputer - arduino
void setup() {
  // put your setup code here, to run once:
  // set kecepatan transmisi port serial (bit per seccond)
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() != 0){
    char data = Serial.read(); // terima data dari port serial
    // kirim kembali data ke port
    // Karakter
    Serial.print("Karakter: ");
    Serial.print(data);

    // ascii
    Serial.print(", ASCII: ");
    Serial.print(data, DEC);

    // biner
    Serial.print(", Biner: ");
    Serial.print(data, BIN);

    // hexadesimal
    Serial.print(", Hexadesimal: ");
    Serial.println(data, HEX);
    delay(20);
  }
}
