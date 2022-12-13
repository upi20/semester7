// Kelompok
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]
const int PIN_MERAH = 13; // reverse
const int PIN_HIJAU = 12; // reverse
const int PIN_BIRU = 11; // reverse
const int PIN_BUZZER = 10; // reverse
const int PIN_INDIKATOR_BUZZER = 8; // reverse

const int AIR_TENGAH = 35;
const int AIR_PENUH = 5;

const int PIN_PULLUP = 9;

bool hitung = true;

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
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_INDIKATOR_BUZZER, OUTPUT);
  pinMode(PIN_PULLUP, INPUT_PULLUP);

  digitalWrite(PIN_MERAH, HIGH);
  digitalWrite(PIN_BIRU, HIGH);
  digitalWrite(PIN_HIJAU, HIGH);
  digitalWrite(PIN_BUZZER, HIGH);

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

  // setting sensor jarak 
  pinMode (triger, OUTPUT); //trigger sebagai output
  pinMode (echo, INPUT); //echo sebagai input
}

void loop() {
  int sensorVal = digitalRead(PIN_PULLUP);
  //print out the value of the pushbutton
  if(sensorVal==0){
    lcd.clear();
    lcd.setCursor(0,0);
    if(hitung){
      digitalWrite(PIN_INDIKATOR_BUZZER, HIGH);
      lcd.print("Mematikan.."); 
      hitung = false;
      digitalWrite(PIN_BUZZER, HIGH);
    }else{
      digitalWrite(PIN_INDIKATOR_BUZZER, LOW);
      lcd.print("Menghidupkan.."); 
      hitung = true;
    }
    lcd.setCursor(0,1);
    lcd.print("Buzzer");
    delay(500);

    for(int i =0; i<10; i++){
      if(i%2==0){
        digitalWrite(PIN_INDIKATOR_BUZZER, HIGH);
      }else{
        digitalWrite(PIN_INDIKATOR_BUZZER, LOW);
      }
      delay(100);
    }
  }

  digitalWrite (triger, HIGH); //mengirim suara
  delayMicroseconds(10); //selama 10 mikro detik
  digitalWrite (triger, LOW); //berhenti mengirim suara
  float jarak = pulseIn(echo, HIGH); //membaca data dan di masukkan ke variabel jarak
  jarak=jarak/1000000; //konversi mikro detik ke detik
  jarak=jarak*330/2; //data mentah di ubah ke dalam meter
  jarak=jarak*100; //mengubah data ke dalam centi meter
  Serial.println(jarak); //menampilkan nilai jarak pada serial

  // print lcd
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hitung Jarak "); 
  // status hitung jarak
  if(hitung){
    lcd.print("ON"); 
    digitalWrite(PIN_INDIKATOR_BUZZER, LOW);
  }else{
    lcd.print("OFF"); 
    digitalWrite(PIN_INDIKATOR_BUZZER, HIGH);
  }

  lcd.setCursor(0,1);
  lcd.print(jarak);
  lcd.print(" CM"); 
  
  if(jarak>AIR_TENGAH){
    // air dasar
    digitalWrite(PIN_BUZZER, HIGH);
    digitalWrite(PIN_MERAH, HIGH);
    digitalWrite(PIN_HIJAU, HIGH);
    digitalWrite(PIN_BIRU, LOW);
  }else if (jarak>AIR_PENUH && jarak<=AIR_TENGAH){    
    // air tengah
    digitalWrite(PIN_BUZZER, HIGH);
    digitalWrite(PIN_MERAH, HIGH);
    digitalWrite(PIN_HIJAU, LOW);
    digitalWrite(PIN_BIRU, HIGH);
  }else{
    // air penuh
    digitalWrite(PIN_MERAH, LOW);
    digitalWrite(PIN_HIJAU, HIGH);
    digitalWrite(PIN_BIRU, HIGH);
    if(hitung){
      digitalWrite(PIN_BUZZER, LOW);
    }
  }

  delay(500); //delay 500ms
} 
