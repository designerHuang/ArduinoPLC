#include <Arduino.h>
#include <EEPROM.h>
#include <SPI.h>
#include "pins.h"
#include "board.h"      // 板载
#include "stepper.h"    // 步进电机
#include "display.h"    // 显示
// test
#include "test.h"

void setup() {
  Serial.begin(115200);

  pinMode(LED,OUTPUT);
  
  displayBegin();
  stepperBegin();

  digitalWrite(LED,HIGH);
  Test();
}

void loop() {
}