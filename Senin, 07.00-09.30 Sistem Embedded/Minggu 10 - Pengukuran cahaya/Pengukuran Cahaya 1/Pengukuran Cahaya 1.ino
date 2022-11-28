// Kelompok
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]

#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test"));
}
void loop() {
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lux");
  delay(1000);
}