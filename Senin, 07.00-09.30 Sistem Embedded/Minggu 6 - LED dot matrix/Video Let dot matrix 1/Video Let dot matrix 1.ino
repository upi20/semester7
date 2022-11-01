// Kelompok 
// Isep Lutpi Nur [2113191079]
// Farhan Aziz [2113191097]
// Muhammad Bayu Ramdhani [2113191081]
// Muhammad Taufik Ali [2113191067]
#include "LedControl.h"

LedControl lc=LedControl(12, 11, 10, 2); // urutannya > DIN, CLK, CS NRDEV

// waktu tunggu yang dideklarasikan variable global
unsigned long waktutunggu = 50;

int col;
int row;
int address;
int devices;
void setup() {
  // jumlah perangkat yang telah dirangkai antara arduino dengan dot matrix
  devices=lc.getDeviceCount();

  // inisialisasi semua perangkat (didalam void loop)
  address = 0; // jika sudah pasti hanya 1 buah device
  // IC MAX72XX berada dalam mode sleep saat startup
  lc.shutdown(address, false);
  // Atur kecerahan ke tingkat menengah
  lc.setIntensity(address, 2);
  // Kosongkan data di dotmatrix (clear display)
  lc.clearDisplay(address);
}

void loop() {
  devices = lc.getDeviceCount();
  address = 0; // jika sudah pasti hanya 1 buah device
  row = 0;
  col = 0;
  lc.setLed(address, row, col, true);
  delay(1000);
  lc.setLed(address, row, col, false);
  
  row = 7;
  col = 7;
  lc.setLed(address, row, col, true);
  delay(1000);
  lc.setLed(address, row, col, false);
}
