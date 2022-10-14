#include "LedControl.h"

LedControl lc = LedControl(11, 13, 3, 4);

byte hurufA[] = {0x3C,0x24,0x24,0x7E,0x62,0x62,0x62,0x00};
byte hurufB[] = {0x7C,0x24,0x24,0x3E,0x32,0x32,0x7E,0x00};
byte hurufC[] =
{
  B00111110, // First frame of invader #1
  B00100010,
  B00100000,
  B01100000,
  B01100000,
  B01100010,
  B01111110,
  B00000000
};

void setup() {
  // put your setup code here, to run once:
  int devices = lc.getDeviceCount();
  for(int address = 0; address<devices; address++){
    lc.shutdown(address, false);
    lc.setIntensity(address, 2);
    lc.clearDisplay(address);
  }
}

void loop() {
  for (int i=0;i<4;i++) {
      B(i);
      A(i-1);
      C(i-2);
      A(i-3);
      delay(1000);
    }
  delay(2000);
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
  delay(2000);
}

void A(int dev){
  for (int i = 0; i < 8; i++){
    lc.setRow(dev,i,hurufA[i]);
  }
}

void B(int dev){
  for (int i = 0; i < 8; i++){
    lc.setRow(dev,i,hurufB[i]);
  }
}

void C(int dev){
  for (int i = 0; i < 8; i++){
    lc.setRow(dev,i,hurufC[i]);
  }
}
