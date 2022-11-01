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
  for(address = 0; address < devices; address++){
    // IC MAX72XX berada dalam mode sleep saat startup
    lc.shutdown(address, false);
    // Atur kecerahan ke tingkat menengah
    lc.setIntensity(address, 2);
    // Kosongkan data di dotmatrix (clear display)
    lc.clearDisplay(address);
  }
}

void loop() {
  // baca jumlah perangkat
  devices = lc.getDeviceCount();

  // perulangan pertama untuk menghidupkan data satu persatu
  for(row=0; row<8; row++){
    for(col=0; col<8; col++){
      for(address = 0; address < devices; address++){
        lc.setLed(address, row, col, true);
        delay(waktutunggu);
      }
    }
  }

  // perulangan pertama untuk mematikan data satu persatu
  for(row=0; row<8; row++){
    for(col=0; col<8; col++){
      for(address = 0; address < devices; address++){
        lc.setLed(address, row, col, false);
        delay(waktutunggu);
      }
    }
  }

}
