#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();
}
void loop() {
  lcd.autoscroll();
  lcd.setCursor(20, 0);
    for (int x = 0; x < 14; x++) {
    lcd.print(x);
    delay(500);
  }
  lcd.clear();
}
