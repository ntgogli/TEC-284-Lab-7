#include <SoftwareSerial.h>

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 128;
const int colorG = 0;
const int colorB = 128;

SoftwareSerial mySerial(11, 10); //RX, TX pins

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("Waiting...");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available() > 0) {
    String recievedMessage = mySerial.readString();
    
    lcd.clear();
    lcd.setCursor(0, 0);

    lcd.print(recievedMessage);
    Serial.println(recievedMessage);
  }
}
