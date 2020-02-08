#include <EEPROM.h>
#include <SPI.h>
#include "define.h"
#include "data.h"
#include "stepper.h"
#include "keyboard.h"
#include "configuration.h"
#include "logo.h"
#include "display.h"
#include "basic.h"
#include "control.h"
#include "set.h"
#include "run.h"
#include "initialize.h"

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);
  
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

  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 1000;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= ((1 << CS11) | (1 << CS10));
  interrupts();

  steppers[3].dirFunc = xDir;
  steppers[3].stepFunc = xStep;
  steppers[3].acceleration = 1000;
  steppers[3].minStepInterval = 50;

  steppers[4].dirFunc = yDir;
  steppers[4].stepFunc = yStep;
  steppers[4].acceleration = 1000;
  steppers[4].minStepInterval = 50;

  steppers[5].dirFunc = zDir;
  steppers[5].stepFunc = zStep;
  steppers[5].acceleration = 1000;
  steppers[5].minStepInterval = 50;

  pinMode(IN01, INPUT);
  pinMode(IN02, INPUT);
  pinMode(IN03, INPUT);
  pinMode(IN04, INPUT);
  pinMode(IN05, INPUT);
  pinMode(IN06, INPUT);
  
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
  
  pinMode(buzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(37, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(40, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);

  //Program
  digitalWrite(X_ENABLE_PIN, LOW);//Motor EN
  digitalWrite(ledPin, HIGH);
  BUZ(1);
  displayLogo();
  initialize();
  displayMenu();
}

void loop() {
  for (int i = 0; i < NUM_STEPPERS; i++) {
    prepareMovement( i, 800 );
    runAndWait();
  }
  prepareMovement( 0, 8000 );
  prepareMovement( 1,  800 );
  prepareMovement( 2, 2400 );
  runAndWait();
  delay(1000);
  prepareMovement( 0, -8000 );
  prepareMovement( 1,  1600 );
  prepareMovement( 2, -2400 );
  runAndWait();
  while (true);
  
  //Keyboard
  digitalWrite(B07, HIGH);
  digitalWrite(B05, HIGH);
  digitalWrite(B03, HIGH);
  digitalWrite(B01, LOW);
  //返回
  if (digitalRead(B08) == LOW) {
    if (menuv == 0) {
    } else if (menuv < 5) {
      menucount = menuv;
      menuv = 0;
      displayMenu();
    } else if (menuv == 5) {
      //setCoord
    }
    while (digitalRead(40) == LOW);
    delay(20);
  }
  //上
  if (digitalRead(B06) == LOW) {
    if (menucount > 0) {
      menucount--;
      displayMenu();
    }
    while (digitalRead(36) == LOW);
    delay(50);
  }
  //下
  if (digitalRead(B04) == LOW) {
    if (menutxt[menuv][menucount + 1] != 0) {
      menucount++;
      displayMenu();
    }
    while (digitalRead(34) == LOW);
    delay(50);
  }
  //确认
  if (digitalRead(B02) == LOW) {
    if (menuv == 0) {
      if (menucount == 0)run();
      if (menucount != 0) {
        menuv = menucount;
        menucount = 0;
      }
      displayMenu();
      while (digitalRead(32) == LOW);
      delay(20);
    } else if (menuv == 1) {
      Matera();
      displayMenu();
      while (digitalRead(40) == LOW);
      delay(20);
    } else if (menuv == 2) {
      Control();
      displayMenu();
      while (digitalRead(40) == LOW);
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
      while (digitalRead(40) == LOW);
      delay(20);
    }
  }
}
