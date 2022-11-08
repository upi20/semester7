#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Kumaha Daramang!");
  lcd.setCursor(0, 1);
  lcd.print("Muter Kamana?");
  lcd.setCursor(0, 2);
  lcd.print("Baris no 2");
}
void loop() {
//  lcd.scrollDisplayLeft(); // Geser ke kiri
  lcd.scrollDisplayRight(); // Geser ke kanan
  delay(500);
}
