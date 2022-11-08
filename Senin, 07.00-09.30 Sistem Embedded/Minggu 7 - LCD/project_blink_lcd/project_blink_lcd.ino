// Kelompok:
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Blinking text");
}

void loop() {
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
}
