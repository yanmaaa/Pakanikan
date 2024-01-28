#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_ServoMotor *myServo = AFMS.getServo(1);

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  AFMS.begin();
}

void loop() {
  DateTime now = rtc.now();
  if (now.hour() == 12 && now.minute() == 0 && now.second() == 0) {
    myServo->write(180);
    delay(1000); // Wait for 1 second
    myServo->write(0); // Reset servo position
  }
  // Other code for different conditions
  delay(1000); // Check the time every 1 second
}
