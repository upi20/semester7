// Kelompok
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]

#include <Wire.h>
#include <BH1750.h>
#include <LiquidCrystal_I2C.h> //memasukan library LCD
BH1750 lightMeter;
LiquidCrystal_I2C lcd(0x27, 20, 4); //alamat didapat dari i2c scanner
void setup(){
  Serial.begin(9600); // Initialize the I2C bus (BH1750 library doesn't do this  automatically) 

  // On esp8266 devices you can select SCL and SDA pins using Wire.begin(D4, D3);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test"));

  //Inisialisasi LCD menyalakan backlight LCD,
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Light Meter"); //pada baris pertama
  lcd.setCursor(0,1);
  lcd.print("BH1750"); //pada baris kedua dituliskan LCD + BH1750
  delay(1000); //Waktu jeda
  lcd.clear();
}

void loop() {
  float lux = lightMeter.readLightLevel();
  Serial.print(lux);
  Serial.println(" lux");
  
  lcd.setCursor(0,0);
  lcd.print("Light Meter");
  lcd.setCursor(0,1);
  lcd.print("Light: ");
  lcd.print(lux);
  lcd.print(" lux");
  delay(500);
} 
