#include <Ultrasonic.h>

// Definisikan pin trigger dan echo
const int triggerPin = D5;
const int echoPin = D6;
const int buzzerPin = D7;  // Pin untuk menghubungkan buzzer

Ultrasonic ultrasonic(triggerPin, echoPin);  // Objek Ultrasonic

void setup() {
  Serial.begin(115200);  // Inisialisasi komunikasi serial
  pinMode(buzzerPin, OUTPUT);  // Set pin buzzer sebagai output
}

void loop() {
  // Baca jarak dari sensor ultrasonik dalam satuan cm
  int distance = ultrasonic.read();

  // Tampilkan hasil di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Aktifkan buzzer jika jarak kurang dari 30 cm
  if (distance > 30) {
    tone(buzzerPin, 2000);  // Aktifkan buzzer dengan frekuensi 1000 Hz
  } else {
    noTone(buzzerPin);  // Matikan buzzer jika jarak lebih dari atau sama dengan 30 cm
  }

  delay(1000);  // Tunggu selama 1 detik sebelum membaca kembali
}
