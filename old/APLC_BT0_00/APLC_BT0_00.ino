//这是最基本的程序，直接写到 void loop() 即可.

#include <EEPROM.h>
#include "pins.h" //针脚定义
#include "data.h" //还是留了个房数据的地方

void setup() {
  Serial.begin(115200);
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
  
  digitalWrite(ledPin, HIGH);
}

void loop() {
  tone(buzPin, 3000);
  delay(1000);
  noTone(buzPin);
}
