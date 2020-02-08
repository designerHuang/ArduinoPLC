#include <EEPROM.h>
#include <SPI.h>
#include <SD.h>
#include "define.h"
#include "data.h"
#include "keyboard.h"
#include "configuration.h"
#include "displayLogo.h"
#include "display.h"
#include "basic.h"
#include "grblserial.h"
#include "control.h"
#include "set.h"
#include "run.h"
#include "initialize.h"

void setup() {
  Serial.begin(115200);
  u8g2.begin();
  u8g2.enableUTF8Print();
  pinMode(buzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(X_STEP_PIN,   OUTPUT);
  pinMode(X_DIR_PIN,    OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Y_STEP_PIN,   OUTPUT);
  pinMode(Y_DIR_PIN,    OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(Z_STEP_PIN,   OUTPUT);
  pinMode(Z_DIR_PIN,    OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);

  pinMode(IN01, INPUT_PULLUP);
  pinMode(IN02, INPUT_PULLUP);
  pinMode(IN03, INPUT_PULLUP);
  pinMode(IN04, INPUT_PULLUP);
  pinMode(IN05, INPUT_PULLUP);
  pinMode(IN06, INPUT_PULLUP);

  pinMode(OUT01, OUTPUT);
  pinMode(OUT02, OUTPUT);
  pinMode(OUT03, OUTPUT);
  pinMode(OUT04, OUTPUT);
  pinMode(OUT05, OUTPUT);
  pinMode(OUT06, OUTPUT);
  pinMode(OUT07, OUTPUT);
  pinMode(OUT08, OUTPUT);
  pinMode(OUT09, OUTPUT);
  pinMode(OUT10, OUTPUT);

  pinMode(B01, INPUT_PULLUP);
  pinMode(B02, OUTPUT);
  pinMode(B03, INPUT_PULLUP);
  pinMode(B04, OUTPUT);
  pinMode(B05, INPUT_PULLUP);
  pinMode(B06, OUTPUT);
  pinMode(B07, INPUT_PULLUP);
  pinMode(B08, OUTPUT);
  
  digitalWrite(ledPin, HIGH);
  start();
}

void loop() {
  digitalWrite(B02, HIGH);
  digitalWrite(B04, HIGH);
  digitalWrite(B06, HIGH);
  digitalWrite(B08, LOW);

  if (digitalRead(B01) == LOW) {
    if (menuv == 0) {
    } else if (menuv < 5) {
      menucount = menuv;
      menuv = 0;
      displayMenu();
    } else if (menuv == 5) {
      //setCoord
    }
    while (digitalRead(B01) == LOW);
    delay(20);
  }

  if (digitalRead(B03) == LOW) {
    if (menucount > 0) {
      menucount--;
      displayMenu();
    }
    while (digitalRead(B03) == LOW);
    delay(50);
  }

  if (digitalRead(B05) == LOW) {
    if (menutxt[menuv][menucount + 1] != 0) {
      menucount++;
      displayMenu();
    }
    while (digitalRead(B05) == LOW);
    delay(50);
  }

  if (digitalRead(B07) == LOW) {
    if (menuv == 0) {
      if (menucount == 0)run();
      if (menucount != 0) {
        menuv = menucount;
        menucount = 0;
      }
      displayMenu();
      while (digitalRead(B07) == LOW);
      delay(20);
    } else if (menuv == 1) {
      Matera();
      displayMenu();
      while (digitalRead(B01) == LOW);
      delay(20);
    } else if (menuv == 2) {
      Control();
      displayMenu();
      while (digitalRead(B01) == LOW);
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
      while (digitalRead(B01) == LOW);
      delay(20);
    }
  }
}
