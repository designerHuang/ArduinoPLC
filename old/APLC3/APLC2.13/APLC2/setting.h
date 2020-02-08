/*移动坐标*/
void MoveCoordinate(){
  while(digitalRead(ECC) == LOW);
  if(HOMEDATA == 0){
    HOMEDATA = 1;
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB12_tr);
    u8g2.drawStr(2,20,"HOMING...");
    u8g2.sendBuffer();
    digitalWrite(ENX, LOW);
    digitalWrite(AIR1, HIGH);
    digitalWrite(AIR2, LOW);
    digitalWrite(AIR3, LOW);
    digitalWrite(AIR4, LOW);
    digitalWrite(AIR5, LOW);
    while (digitalRead(LIMITX) == LOW) {
      StepperX.setSpeed(SHOME);
      StepperX.runSpeed();
      StepperX.setCurrentPosition(0); 
      StepperY.setCurrentPosition(0); 
    }
    while (StepperX.currentPosition() != 400) {
      StepperX.setSpeed(1000);
      StepperX.run();
    }
  }
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"SW1+,SW2-");
  u8g2.sendBuffer();
  while(digitalRead(ECC) == HIGH){
    if(digitalRead(SW1) == LOW) {
      StepperX.setSpeed(2000);
      StepperX.runSpeed();
    }
    if (digitalRead(SW2) == LOW) {
      StepperX.setSpeed(-2000);
      StepperX.runSpeed();
    }
  }
}

/*设置坐标*/
void SetCoordinate(){
  switch(ECP){
  //A
  case 1:
  MoveCoordinate();
  A = StepperX.currentPosition();
  EEPROM.put(65,A);
  BUZB();
  delay(200);
  break;
  //B
  case 2:
  MoveCoordinate();
  B = StepperX.currentPosition();
  EEPROM.put(69,B);
  BUZB();
  delay(200);
  break;
  //C
  case 3:
  MoveCoordinate();
  C = StepperX.currentPosition();
  EEPROM.put(73,C);
  BUZB();
  delay(200);
  break;
  //D
  case 4:
  MoveCoordinate();
  D = StepperX.currentPosition();
  EEPROM.put(77,D);
  BUZB();
  delay(200);
  break;
  //E
  case 5:
  MoveCoordinate();
  E = StepperX.currentPosition();
  EEPROM.put(81,E);
  BUZB();
  delay(200);
  break;
  //F
  case 6:
  MoveCoordinate();
  F = StepperX.currentPosition();
  EEPROM.put(85,F);
  BUZB();
  delay(200);
  break;
  }
}
