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
  address = 0;
  row = 0;
  column = 0;
  lc.setLed(address, row, column, true);
  delay(1000);
  lc.setLed(address, row, column, false);
  row = 7;
  column = 7;
  lc.setLed(address, row, column, true);
  delay(1000);
  lc.setLed(address, row, column, false);
  delay(1000);
}
