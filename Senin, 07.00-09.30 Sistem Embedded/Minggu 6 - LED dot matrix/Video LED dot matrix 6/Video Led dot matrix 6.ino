// Kelompok 
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]
#include "LedControl.h"

int DIN = 12;
int CLK = 11;
int CS = 10;
int NRDEV = 4;
LedControl lc=LedControl(DIN, CLK, CS, NRDEV);

void setup() {
  for(int i=0; i<NRDEV; i++){
    lc.shutdown(i, false);
    lc.setIntensity(i, 1);
    lc.clearDisplay(i);
  }
}

void setLed(int dev, String huruf){
  for(int i = 0; i < 8; i++){
    lc.setRow(dev, i, getHuruf(huruf, i));
  };
}

byte getHuruf(String huruf, int i){
  huruf.toLowerCase();
  
  if(huruf == "k" || huruf == "K")
  {
    byte listHuruf[] = {0x00, 0x44, 0x48, 0x50, 0x70, 0x48, 0x44, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "e" || huruf == "E")
  {
    byte listHuruf[] = {0x00, 0x7c, 0x40, 0x40, 0x78, 0x40, 0x7c, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "l" || huruf == "L")
  {
    byte listHuruf[] = {0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x78, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "o" || huruf == "O")
  {
    byte listHuruf[] = {0x00, 0x7c, 0x44, 0x44, 0x44, 0x44, 0x7c, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "o" || huruf == "O")
  {
    byte listHuruf[] = {0x00, 0x7c, 0x44, 0x44, 0x44, 0x44, 0x7c, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "m" || huruf == "M")
  {
    byte listHuruf[] = {0x00, 0x36, 0x4a, 0x4a, 0x4a, 0x4a, 0x4a, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "p" || huruf == "P")
  {
    byte listHuruf[] = {0x00, 0x78, 0x48, 0x70, 0x40, 0x40, 0x40, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "i" || huruf == "I")
  {
    byte listHuruf[] = {0x00, 0x70, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "s" || huruf == "S")
  {
    byte listHuruf[] = {0x00, 0x38, 0x40, 0x40, 0x30, 0x08, 0x30, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "f" || huruf == "F")
  {
    byte listHuruf[] = {0x00, 0x38, 0x40, 0x78, 0x40, 0x40, 0x40, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "a" || huruf == "A")
  {
    byte listHuruf[] = {0x00, 0x38, 0x44, 0x44, 0x7c, 0x44, 0x44, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "r" || huruf == "R")
  {
    byte listHuruf[] = {0x00, 0x30, 0x48, 0x50, 0x60, 0x50, 0x48, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "h" || huruf == "H")
  {
    byte listHuruf[] = {0x00, 0x48, 0x48, 0x48, 0x78, 0x48, 0x48, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "n" || huruf == "N")
  {
    byte listHuruf[] = {0x00, 0x44, 0x64, 0x54, 0x4c, 0x44, 0x44, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "b" || huruf == "B")
  {
    byte listHuruf[] = {0x00, 0x60, 0x50, 0x48, 0x70, 0x48, 0x78, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "y" || huruf == "Y")
  {
    byte listHuruf[] = {0x00, 0x42, 0x42, 0x3c, 0x18, 0x18, 0x18, 0x00};
    return listHuruf[i];
  }
  else if(huruf == "u" || huruf == "U")
  {
    byte listHuruf[] = {0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00};
    return listHuruf[i];
  }
  else{
    byte listHuruf[] = {0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    return listHuruf[i];
  }
}

void loop() {
  String kelp = "   M Ali";
  int length = kelp.length();
  for(int i = 0; i< length; i++){
    setLed(3, String(kelp[i]));

    String led2 = (i+1>=length) ? "" : String(kelp[i+1]);
    setLed(2, led2);

    String led1 = (i+2>=length) ? "" : String(kelp[i+2]);
    setLed(1, led1);

    String led0 = (i+3>=length) ? "" : String(kelp[i+3]);
    setLed(0, led0);

    delay(300);
  }
}
