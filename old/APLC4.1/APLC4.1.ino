#include "pins.h"
#include "basic.h"
#include "grblserial.h"
#include <SPI.h>
#include <SD.h>

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);

  pinMode(BUZ,OUTPUT);
  pinMode(LED,OUTPUT);
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  pinMode(A4,INPUT_PULLUP);
  pinMode(A5,INPUT_PULLUP);
  pinMode(A6,INPUT_PULLUP);
  pinMode(A7,INPUT_PULLUP);
  pinMode(A8,INPUT_PULLUP);
  pinMode(A9,INPUT_PULLUP);

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(OUT08,OUTPUT);
  pinMode(OUT09,OUTPUT);
  pinMode(OUT10,OUTPUT);
  pinMode(OUT11,OUTPUT);
  pinMode(OUT12,OUTPUT);
  pinMode(OUT13,OUTPUT);
  pinMode(OUT14,OUTPUT);
  pinMode(OUT15,OUTPUT);
  pinMode(OUT16,OUTPUT);
  pinMode(OUT17,OUTPUT);
  pinMode(OUT18,OUTPUT);
  
  BUZA();
  Serial.println("APLC Ready");
  digitalWrite(LED, HIGH);
}

void loop() {
  /*if(Serial3.available()){
    int data=Serial3.read();
    Serial.write(data);
  }
  if(Serial.available()){
    int data=Serial.read();
    Serial3.write(data);
  }*/
  digitalWrite(LED, HIGH);
  digitalWrite(OUT01, HIGH);
  digitalWrite(OUT03, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  digitalWrite(OUT01, LOW);
  digitalWrite(OUT03, LOW);
  delay(1000);
}
