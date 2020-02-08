/*
  aplc.h - main APLC include file
  Part of APLC

  Copyright (c) 2019 Lishu Huang
*/

#include <EEPROM.h>
#include <SD.h>
File myFile;
boolean restart = true;

#include "configuration.h"

#ifdef YILING
#include "pins_yiling.h"
#endif 

#include "data.h"
#include "logo.h"
#include "display.h"
#include "action.h"
#include "grblserial.h"
#include "setting.h"
#include "material.h"
#include "control.h"
#include "run.h"

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  u8g2.begin();
  u8g2.enableUTF8Print(); 

  pinMode(T1,INPUT);
  pinMode(T2,INPUT);
  pinMode(ECA,INPUT);
  pinMode(ECB,INPUT);
  pinMode(ECC,INPUT);
  pinMode(BUZ,OUTPUT);
  
  pinMode(SW1,INPUT_PULLUP);
  pinMode(SW2,INPUT_PULLUP);
  pinMode(SW3,INPUT_PULLUP);
  pinMode(SW4,INPUT_PULLUP);
  pinMode(LIMITX,INPUT_PULLUP);
  pinMode(LIMITA,INPUT_PULLUP);
  pinMode(LIMITB,INPUT_PULLUP);

  pinMode(DIRX,OUTPUT);
  pinMode(STEPX,OUTPUT);
  pinMode(ENX,OUTPUT);
  pinMode(DIRY,OUTPUT);
  pinMode(STEPY,OUTPUT);
  pinMode(ENY,OUTPUT);
  pinMode(DIRZ,OUTPUT);
  pinMode(STEPZ,OUTPUT);
  pinMode(ENZ,OUTPUT);
  pinMode(DIRE,OUTPUT);
  pinMode(STEPE,OUTPUT);
  pinMode(ENE,OUTPUT);
  
  pinMode(HEAT1,OUTPUT);
  pinMode(HEAT2,OUTPUT);
  pinMode(LASER,OUTPUT);
  pinMode(OUT02,OUTPUT);
  pinMode(OUT03,OUTPUT);
  pinMode(OUT04,OUTPUT);
  pinMode(OUT05,OUTPUT);
  pinMode(OUT06,OUTPUT);
  pinMode(OUT07,OUTPUT);
  pinMode(OUT08,OUTPUT);

  pinMode(AIR1,OUTPUT);
  pinMode(AIR2,OUTPUT);
  pinMode(AIR3,OUTPUT);
  pinMode(AIR4,OUTPUT);
  pinMode(AIR5,OUTPUT);
  pinMode(AIR6,OUTPUT);
  pinMode(NP1,OUTPUT);
  pinMode(NP2,OUTPUT);

  EEPROM.get(65,A);
  EEPROM.get(69,B);
  EEPROM.get(73,C);
  EEPROM.get(77,D);
  EEPROM.get(81,E);
  EEPROM.get(85,F);
  digitalWrite(ENX, HIGH);
  digitalWrite(ENY, HIGH);
  digitalWrite(ENZ, HIGH);
  digitalWrite(ENE, HIGH);
  
  StepperX.setMaxSpeed(5000);
  StepperY.setMaxSpeed(3000);
  steppers.addStepper(StepperX);
  steppers.addStepper(StepperY);

  Serial.println("APLC Ready");
  DisplayLOGO();
  DisplayMenu();
}

void loop() {
  if(digitalRead(ECA) == 0){
    while(digitalRead(ECA)==0);
    if (digitalRead(ECB) == 0) {
      while(digitalRead(ECB)==0);
      if(menus[menulvl][ECP+1] != 0) ECP++;
    } else {
      if(ECP > 0) ECP--;
    }
    DisplayMenu();
  }

  if(digitalRead(ECC) == LOW) {
    if(menulvl == 0 && ECP != 1 && ECP != 4){
      menulvl = ECP+1;
      ECP = 0;
      DisplayMenu();
    } /*返回一级*/else if (ECP == 0 && menulvl<5){
      ECP = menulvl-1;
      menulvl = 0;
      DisplayMenu();
    } /*换料*/else if (menulvl == 0 && ECP == 1){
      MaterialChange();
      DisplayMenu();
    } /*Info*/else if (menulvl == 0 && ECP == 4){
      DisplayInfo();
      DisplayMenu();
    }
    /*二级-选择模板*/else if (ECP != 0 && menulvl == 1){
      Run();
      DisplayMenu();
    //换料
    } else if (ECP != 0 && menulvl == 3){
      Control();
      DisplayMenu();
    //设置
    } else if (ECP != 0 && menulvl == 4){
      /*设置坐标*/
      if (ECP = 1){
        menulvl = 5;
        ECP = 0;
      /*设置速度*/
      }else if(ECP = 2){
        menulvl = 6;
        ECP = 0;
      }
      DisplayMenu();
    }else if (ECP == 0 && menulvl > 4){
      ECP = menulvl-4;
      menulvl = 4;
      DisplayMenu();
    //设置坐标
    } else if (ECP != 0 && menulvl == 5){
      SetCoordinate();
      DisplayMenu();
    }
  }
}
