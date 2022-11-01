// Kelompok 
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]
#include "LedControl.h"

LedControl lc=LedControl(12, 11, 10, 4); // urutannya > DIN, CLK, CS NRDEV

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

byte hurufD[] = {0x7E, 0x22, 0x22, 0x32, 0x32, 0x32, 0x7E, 0x00};
byte hurufR[] = {0x3E, 0x22, 0x22, 0x7E, 0x68, 0x68, 0x66, 0x00};
byte hurufU[] = {0x22, 0x22, 0x22, 0x62, 0x62, 0x62, 0x7E, 0x00};
byte hurufY[] = {0x22, 0x22, 0x22, 0x3E, 0x18, 0x18, 0x18, 0x00};

void setup() {
  // led ke 1
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);

  // led ke 2
  lc.shutdown(1, false);
  lc.setIntensity(1, 1);
  lc.clearDisplay(1);
}

void A(int dev){
  for(int i = 0; i < 8; i++){
    lc.setRow(dev, i, hurufA[i]);
  };
}

void B(int dev){
  for(int i = 0; i < 8; i++){
    lc.setRow(dev, i, hurufB[i]);
  };
}

void C(int dev){
  for(int i = 0; i < 8; i++){
    lc.setRow(dev, i, hurufC[i]);
  };
}

void D(int dev){
  for(int i = 0; i < 8; i++){
    lc.setRow(dev, i, hurufD[i]);
  };
}

void R(int dev){
  for(int i = 0; i < 8; i++){
    lc.setRow(dev, i, hurufR[i]);
  };
}

void U(int dev){
  for(int i = 0; i < 8; i++){
    lc.setRow(dev, i, hurufU[i]);
  };
}

void Y(int dev){
  for(int i = 0; i < 8; i++){
    lc.setRow(dev, i, hurufY[i]);
  };
}


void loop() {
  A(0);
  delay(1000);

  A(1);
  B(0);
  delay(1000);

  B(1);
  C(0);
  delay(1000);
}
