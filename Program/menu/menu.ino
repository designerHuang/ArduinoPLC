#include <U8g2lib.h>
#include <SPI.h>
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, 52, 51, A14, A13);

#include "pins.h"
#include "menu.h"

void setup() {
  Serial.begin(115200);
  u8g2.begin();
  u8g2.enableUTF8Print();

  pinMode(B01, INPUT_PULLUP);
  pinMode(B02, OUTPUT);
  pinMode(B03, INPUT_PULLUP);
  pinMode(B04, OUTPUT);
  pinMode(B05, INPUT_PULLUP);
  pinMode(B06, OUTPUT);
  pinMode(B07, INPUT_PULLUP);
  pinMode(B08, OUTPUT);
}

void loop() {
  menu();
}
