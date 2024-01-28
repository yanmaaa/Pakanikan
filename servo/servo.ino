#include <Servo.h>

Servo myservo;

const int servoPin = D3;

void setup() {
  myservo.attach(servoPin);
}

void loop() {
  delay(20000);
  myservo.write(150);
  delay(100);
  myservo.write(0);
  delay(100);
  myservo.write(150);
  delay(100);
  myservo.write(0);
}
