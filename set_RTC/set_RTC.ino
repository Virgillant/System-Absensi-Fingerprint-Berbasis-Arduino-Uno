#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DS3231  rtc(SDA, SCL);

void setup(){
  rtc.begin();
  lcd.init();
  lcd.backlight();
  
  rtc.setDate(18, 06, 2021);   //07 januari 2019
  rtc.setTime(11, 27, 8);    //08:00:00
  rtc.setDOW(5);              //Senin
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDOWStr(1)); //hari
  lcd.setCursor(3, 0);
  lcd.print(",");

  lcd.setCursor(4, 0);
  lcd.print(rtc.getDateStr()); //tanggal

  lcd.setCursor(00, 1);
  lcd.print(rtc.getTimeStr()); //jam

  lcd.setCursor(12, 1);
  lcd.print(rtc.getTemp()); //suhu

  delay (1000);
}
