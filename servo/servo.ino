#include <Servo.h>

Servo myservo;  // Objek servo

const int servoPin = D3;  // Pin yang terhubung ke servo

void setup() {
  myservo.attach(servoPin);  // Menyambungkan servo ke pin yang ditentukan
}

void loop() {
  rotateServo(0);  // Putar servo ke posisi 0 derajat
  delay(1000);      // Tunggu selama 1 detik
//  rotateServo(90);  // Putar servo ke posisi 90 derajat
//  delay(1000);      // Tunggu selama 1 detik
  rotateServo(180); // Putar servo ke posisi 180 derajat
  delay(1000);      // Tunggu selama 1 detik
}

void rotateServo(int angle) {
  // Membatasi sudut servo antara 0 dan 180 derajat
  angle = constrain(angle, 0, 180);
  // Menggerakkan servo ke posisi yang diinginkan
  myservo.write(angle);
  delay(15);  // Memberikan waktu servo untuk mencapai posisi
}
