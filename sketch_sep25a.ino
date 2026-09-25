#include <SoftwareSerial.h>


// PIN BLUETOOTH HC-05

const int BT_RX = 2;  // Arduino menerima data dari TXD HC-05
const int BT_TX = 3;  // Arduino mengirim data ke RXD HC-05

SoftwareSerial bluetooth(BT_RX, BT_TX);

char command;

void setup() {
  // Komunikasi dengan Serial Monitor
  Serial.begin(9600);

  // Komunikasi dengan HC-05
  bluetooth.begin(9600);

  Serial.println("================================");
  Serial.println("   ROBOT BLUETOOTH - TEST");
  Serial.println("================================");
  Serial.println("Menunggu perintah dari HP...");
}

void loop() {

  // Mengecek apakah ada data dari Bluetooth
  if (bluetooth.available()) {

    // Membaca satu karakter
    command = bluetooth.read();

    // Menampilkan karakter yang diterima
    Serial.print("Perintah diterima: ");
    Serial.println(command);

    // Memberikan keterangan berdasarkan perintah
    if (command == 'F') {
      Serial.println("Robot: MAJU");
    }
    else if (command == 'B') {
      Serial.println("Robot: MUNDUR");
    }
    else if (command == 'L') {
      Serial.println("Robot: BELOK KIRI");
    }
    else if (command == 'R') {
      Serial.println("Robot: BELOK KANAN");
    }
    else if (command == 'S') {
      Serial.println("Robot: BERHENTI");
    }
    else if (command == 'U') {
      Serial.println("FORKLIFT: NAIK");
    }
    else if (command == 'D') {
      Serial.println("FORKLIFT: TURUN");
    }
    else {
      Serial.println("Perintah tidak dikenal.");
    }
  }
}