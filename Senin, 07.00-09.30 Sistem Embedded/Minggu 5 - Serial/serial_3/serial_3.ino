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
  while(Serial.available() != 0){ // terima data dari port serial
    // int data = Serial.parseInt(); // bilangan bulat
    float data = Serial.parseFloat(); // bilangan desimal
    if(data != 0 ){
      Serial.print("Bilangan: ");
      Serial.println(data);
      delay(20);
    }
  }
}
