#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

int row, column, address;

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
  // put your main code here, to run repeatedly:
  int devices = lc.getDeviceCount();
  for(row = 0; row<8; row++){
    for(column = 0; column<8; column++){
      for(address = 0; address<devices; address++){
        lc.setLed(address, row, column, true);
        delay(50);
      }
    }
  }
  for(row = 0; row<8; row++){
    for(column = 0; column<8; column++){
      for(address = 0; address<devices; address++){
        lc.setLed(address, row, column, false);
        delay(50);
      }
    }
  }
}
