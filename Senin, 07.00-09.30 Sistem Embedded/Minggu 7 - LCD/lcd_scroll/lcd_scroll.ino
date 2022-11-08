// Kelompok:
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

// 1 lcd clear dengan fungsi clear() pada object LiquidCrystal_I2C
// 2 Scroll
  // 2.1 Scroll Right
  // 2.2 Scroll Left

void setup() {
  lcd.init();
  lcd.backlight();
  // Scroll =========================================================
  lcd.print("Kumaha Daramang!");
  lcd.setCursor(0, 1);
  lcd.print("Muter Kamana?");
  lcd.setCursor(0, 2);
  lcd.print("Baris no 2");
  // Scroll =========================================================
}

void loop() {
  // lcd clear ======================================================
  // lcd.clear();
  // lcd.print("Senin");
  // delay(2000);
  // lcd.setCursor(0, 0);
  // lcd.print("Baris Ke 0 ");
  // lcd.print("13:45");
  // lcd.setCursor(0, 1);
  // lcd.print("Baris Ke 1 ");
  // delay(2000);
  // lcd clear ======================================================

  // Scroll =========================================================
  lcd.scrollDisplayLeft();
  // lcd.scrollDisplayRight();
  delay(500);
  // Scroll =========================================================
}
