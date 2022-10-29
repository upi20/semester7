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
    Serial.print("Karakter: ");
    serial.println(data);
    delay(20);
  }
}
