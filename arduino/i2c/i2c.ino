#include "Wire.h"
#include <LiquidCrystal.h>

#define SLAVE_ADDRESS 0x04
// string to store what the RPi sends
String str_recieved_from_RPi;
int light = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  // initialize the library by associating any needed LCD interface pin
  // with the arduino pin number it is connected to

  // setup the LED
  pinMode(LED_BUILTIN, OUTPUT);

  // begin running as an I2C slave on the specified address
  Wire.begin(SLAVE_ADDRESS);

  // create event for receiving data
  Wire.onReceive(receiveData);

  lcd.begin(16, 2);
}

void loop() {
// nothing needed here since we're doing event based code

}

void receiveData(int byteCount) {

  while ( Wire.available()) {
    str_recieved_from_RPi += (char)Wire.read();
  }
  str_recieved_from_RPi=&str_recieved_from_RPi[1];

  //Serial.println(str_recieved_from_RPi);
  lcd.clear();
  lcd.setCursor(light, light);
  lcd.print(str_recieved_from_RPi);
  str_recieved_from_RPi="";

  if (light) {
    digitalWrite(LED_BUILTIN, HIGH);
    light = 0;
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    light = 1;
  }
}