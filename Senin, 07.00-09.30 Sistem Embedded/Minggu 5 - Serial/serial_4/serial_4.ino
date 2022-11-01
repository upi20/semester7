// Kelompok 
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]

// serial komunikasi komputer - arduino
int const LED_HIJAU = 5;
int const LED_KUNING = 6;
int const LED_MERAH = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);

  // set kecepatan transmisi port serial (bit per seccond)
  Serial.begin(9600);
}

void loop() {
  boolean perintahFlag = true;
  String perintah = "";

  // baca dari serial port
  while(Serial.available() != 0){
    perintah = perintah + char (Serial.read());
    delay(20);
  }

  perintah.trim();
  if(perintah.length() == 0){
    return;
  }

  if(perintah == "HIJAU-ON"){
    digitalWrite(LED_HIJAU, HIGH);
  }

  if(perintah == "KUNING-ON"){
    digitalWrite(LED_KUNING, HIGH);
  }

  if(perintah == "MERAH-ON"){
    digitalWrite(LED_MERAH, HIGH);
  }

  if(perintah == "HIJAU-OFF"){
    digitalWrite(LED_HIJAU, LOW);
  }

  if(perintah == "KUNING-OFF"){
    digitalWrite(LED_KUNING, LOW);
  }

  if(perintah == "MERAH-OFF"){
    digitalWrite(LED_MERAH, LOW);
  }
}
