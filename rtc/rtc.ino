#include <RTClib.h>
#include <Wire.h>
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Ahad", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};
int jam, menit, detik;
int tanggal, bulan, tahun;
String hari;

void setup () {
  Serial.begin(115200);
  Wire.begin(5, 4);   //Setting wire (5 untuk SDA dan 4 untuk SCL)
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

void loop () {
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
  delay(1000);
}
