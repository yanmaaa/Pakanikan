//RTC
#include <RTClib.h>
#include <Wire.h>

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Ahad", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};
int jam, menit, detik;
int tanggal, bulan, tahun;
String hari;

//Servo
#include <Servo.h>

Servo myservo;
const int servoPin = D8;

//Ultrasonic
#include <Ultrasonic.h>

const int triggerPin = D5;
const int echoPin = D6;
const int buzzerPin = D7;  
Ultrasonic ultrasonic(triggerPin, echoPin);

void setup() {
  //RTC
  Serial.begin(115200);
  Wire.begin(5, 4);   //Setting wire (5 untuk SDA dan 4 untuk SCL)
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));

//  rtc.adjust(DateTime(2024, 1, 29, 2, 0, 0));

  //Servo
  myservo.attach(servoPin);

  //Ultrasonic
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
}

void loop(){
  DateTime now = rtc.now();
  jam     = now.hour();
  menit   = now.minute();
  detik   = now.second();
  tanggal = now.day();
  bulan   = now.month();
  tahun   = now.year();
  hari    = daysOfTheWeek[now.dayOfTheWeek()];
  Serial.println(String() + hari + ", " + tanggal + "-" + bulan + "-" + tahun);
  Serial.println(String() + jam+ ":" +menit+ ":" +detik);
  Serial.println();

  //Condition
  if (jam == 02 & menit == 14 & detik ==1){
    pakan(2);
  }
  if (jam == 02 & menit == 15 & detik ==1){
    pakan(4);
  }
  

  int distance = ultrasonic.read();

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 30) {
    tone(buzzerPin, 2000);
  } else {
    noTone(buzzerPin);
  }


}

void pakan(int jumlah){
  for (int i=1; i <= jumlah; i++){
    myservo.write(180);
    delay(100);
    myservo.write(0);
    delay(100);
  }

}

void ultra() {
  int distance = ultrasonic.read();

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 30) {
    tone(buzzerPin, 2000);
  } else {
    noTone(buzzerPin);
  }

  delay(2000);
}
