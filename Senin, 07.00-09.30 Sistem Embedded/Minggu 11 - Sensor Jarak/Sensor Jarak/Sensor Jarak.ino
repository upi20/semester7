// Kelompok
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]
const int PIN_MERAH = 13;
const int PIN_HIJAU = 12;
const int PIN_BIRU = 11;

const int AIR_TENGAH = 30;
const int AIR_PENUH = 10;

#include <Wire.h>
#include <LiquidCrystal_I2C.h> //memasukan library LCD

#define triger 4 //mendefinisikan trigger pada pin 4
#define echo 2 //mendeklarasikan echo pada pin 2

LiquidCrystal_I2C lcd(0x27, 16, 2); //alamat didapat dari i2c scanner
void setup(){
  // setting lampu
  pinMode(PIN_MERAH, OUTPUT);
  pinMode(PIN_BIRU, OUTPUT);
  pinMode(PIN_HIJAU, OUTPUT);

  digitalWrite(PIN_MERAH, HIGH);
  digitalWrite(PIN_BIRU, HIGH);
  digitalWrite(PIN_HIJAU, HIGH);


  Serial.begin(9600);

  //Inisialisasi LCD menyalakan backlight LCD,
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hitung Jarak"); 
  lcd.setCursor(0,1);
  lcd.print("0 CM"); 
  delay(1000); //Waktu jeda
  lcd.clear();

  digitalWrite (8, LOW);

  // setting sensor jarak 
  pinMode (triger, OUTPUT); //trigger sebagai output
  pinMode (echo, INPUT); //echo sebagai input
}

void loop() {
  digitalWrite (triger, HIGH); //mengirim suara
  delayMicroseconds(10); //selama 10 mikro detik
  digitalWrite (triger, LOW); //berhenti mengirim suara
  float jarak = pulseIn(echo, HIGH); //membaca data dan di masukkan ke variabel jarak
  jarak=jarak/1000000; //konversi mikro detik ke detik
  jarak=jarak*330/2; //data mentah di ubah ke dalam meter
  jarak=jarak*100; //mengubah data ke dalam centi meter
  Serial.println(jarak); //menampilkan nilai jarak pada serial

  // print lcd
  lcd.setCursor(0,0);
  lcd.print("Hitung Jarak"); 
  lcd.setCursor(0,1);
  lcd.print(jarak);
  lcd.print(" CM"); 
  
  if(jarak>AIR_TENGAH){
    // air dasar
    digitalWrite(PIN_MERAH, HIGH);
    digitalWrite(PIN_HIJAU, HIGH);
    digitalWrite(PIN_BIRU, LOW);
  }else if (jarak>AIR_PENUH && jarak<=AIR_TENGAH){    
    // air tengah
    digitalWrite(PIN_MERAH, HIGH);
    digitalWrite(PIN_HIJAU, LOW);
    digitalWrite(PIN_BIRU, HIGH);

  }else{
    // air penuh
    digitalWrite(PIN_MERAH, LOW);
    digitalWrite(PIN_HIJAU, HIGH);
    digitalWrite(PIN_BIRU, HIGH);
  }

  delay(600); //delay 500ms
} 
