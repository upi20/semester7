// Kelompok 
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]
#include "LedControl.h"

LedControl lc=LedControl(12, 11, 10, 2); // urutannya > DIN, CLK, CS NRDEV

// waktu tunggu yang dideklarasikan variable global
unsigned long delayTime = 50;

byte hurufA[] = {0x3C, 0x24, 0x24, 0x7E, 0x62, 0x62, 0x62, 0x00};
byte hurufB[] = {0x7C, 0x24, 0x24, 0x3E, 0x32, 0x32, 0x7E, 0x00};
byte hurufC[] = 
{
  B00111110,
  B00100000,
  B00100000,
  B01100000,
  B01100000,
  B01100010,
  B01111110,
  B00000000
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 2);
  lc.clearDisplay(0);
}

void A(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, hurufA[i]);
  };
}

void B(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, hurufB[i]);
  };
}
void C(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, hurufC[i]);
  };
}

void loop() {
  A();
  delay(1000);
  B();
  delay(1000);
  C();
  delay(1000);
}
