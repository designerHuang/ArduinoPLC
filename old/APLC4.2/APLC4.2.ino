#include <EEPROM.h>
#include <SPI.h>
#include <SD.h>
#include "pins.h"
#include "data.h"
#include "keyboard.h"
#include "configuration.h"
#include "logo.h"
#include "display.h"
#include "basic.h"
#include "grblserial.h"
#include "control.h"
#include "set.h"
#include "run.h"
#include "initialize.h"

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  u8g2.begin();
  u8g2.enableUTF8Print();
  //IN
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pinMode(A7, INPUT_PULLUP);
  pinMode(A8, INPUT_PULLUP);
  pinMode(A9, INPUT_PULLUP);
  //OUT
  pinMode(BUZ, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(35, OUTPUT);
  /*Board*/
  pinMode(32, OUTPUT);  //BUZ
  /*Keyboard*/
  pinMode(A10, INPUT_PULLUP);
  pinMode(A12, INPUT_PULLUP);
  pinMode(A14, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(A11, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A15, OUTPUT);
  pinMode(23, OUTPUT);

  digitalWrite(LED, HIGH);
  BUZ(1);
  displayLogo();
  initialize();
  displayMenu();
}

void loop() {
  digitalWrite(A11, HIGH);
  digitalWrite(A13, HIGH);
  digitalWrite(A15, HIGH);
  digitalWrite(23, LOW);
  //返回按钮
  if (digitalRead(A10) == LOW) {
    //Serial.println("←");
    if (menuv == 0) {
    } else if (menuv < 5) {
      menucount = menuv;
      menuv = 0;
      displayMenu();
    } else if (menuv == 5) {
      //setCoord

    }
    while (digitalRead(A10) == LOW);
    delay(20);
  }
  if (digitalRead(A12) == LOW) {
    //Serial.println("↑");
    if (menucount > 0) {
      menucount--;
      displayMenu();
    }
    while (digitalRead(A12) == LOW);
    delay(50);
  }
  if (digitalRead(A14) == LOW) {
    //Serial.println("↓");
    if (menutxt[menuv][menucount + 1] != 0) {
      menucount++;
      displayMenu();
    }
    while (digitalRead(A14) == LOW);
    delay(50);
  }
  if (digitalRead(22) == LOW) {
    //Serial.println("→");
    if (menuv == 0) {
      if (menucount == 0)run();
      if (menucount != 0) {
        menuv = menucount;
        menucount = 0;
      }
      displayMenu();
      while (digitalRead(22) == LOW);
      delay(20);
    } else if (menuv == 1) {
      Matera();
      displayMenu();
      while (digitalRead(A10) == LOW);
      delay(20);
    } else if (menuv == 2) {
      Control();
      displayMenu();
      while (digitalRead(A10) == LOW);
      delay(20);
    } else if (menuv == 3) {
      if (menucount == 0) {
        menucount = 0;
        setCoord();
      } else if (menucount == 1) {
        menucount = 0;
        setSpeed();
      } else if (menucount == 2) {
        menucount = 0;
        setLaser();
      }
      while (digitalRead(A10) == LOW);
      delay(20);
    }
  }
}
