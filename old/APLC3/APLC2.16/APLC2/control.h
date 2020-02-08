/*OutTest*/
void Control1(){
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"OutTest");
  u8g2.sendBuffer();
  BUZA();
  while(digitalRead(ECC) == HIGH){
    digitalWrite(AIR1, HIGH);
    digitalWrite(AIR2, HIGH);
    digitalWrite(AIR3, HIGH);
    digitalWrite(AIR4, HIGH);
    digitalWrite(AIR5, HIGH);
    digitalWrite(AIR6, HIGH);
    digitalWrite(NP1, HIGH);
    digitalWrite(NP2, HIGH);
    delay(1000);
    digitalWrite(AIR1, LOW);
    digitalWrite(AIR2, LOW);
    digitalWrite(AIR3, LOW);
    digitalWrite(AIR4, LOW);
    digitalWrite(AIR5, LOW);
    digitalWrite(AIR6, LOW);
    digitalWrite(NP1, LOW);
    digitalWrite(NP2, LOW);
    delay(1000);
  }
}

/*MotorTest*/
void Control2(){
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"MotorTest");
  u8g2.sendBuffer();
  BUZA();
  digitalWrite(ENX, LOW);
  digitalWrite(ENY, LOW);
  digitalWrite(ENZ, LOW);
  digitalWrite(ENE, LOW);
  while(digitalRead(ECC) == HIGH){
    digitalWrite(DIRX, LOW);
    digitalWrite(DIRY, LOW);
    digitalWrite(DIRZ, LOW);
    digitalWrite(DIRE, LOW);
    for(int i=0; i<5000; i++){
      if(digitalRead(ECC) == LOW)break;
      digitalWrite(STEPX, HIGH);
      digitalWrite(STEPY, HIGH);
      digitalWrite(STEPZ, HIGH);
      digitalWrite(STEPE, HIGH);
      delayMicroseconds(100);
      digitalWrite(STEPX, LOW);
      digitalWrite(STEPY, LOW);
      digitalWrite(STEPZ, LOW);
      digitalWrite(STEPE, LOW);
      delayMicroseconds(100);
    }
    digitalWrite(DIRX, HIGH);
    digitalWrite(DIRY, HIGH);
    digitalWrite(DIRZ, HIGH);
    digitalWrite(DIRE, HIGH);
    for(int i=0; i<5000; i++){
      if(digitalRead(ECC) == LOW)break;
      digitalWrite(STEPX, HIGH);
      digitalWrite(STEPY, HIGH);
      digitalWrite(STEPZ, HIGH);
      digitalWrite(STEPE, HIGH);
      delayMicroseconds(100);
      digitalWrite(STEPX, LOW);
      digitalWrite(STEPY, LOW);
      digitalWrite(STEPZ, LOW);
      digitalWrite(STEPE, LOW);
      delayMicroseconds(100);
    }
  }
  digitalWrite(ENX, HIGH);
  digitalWrite(ENY, HIGH);
  digitalWrite(ENZ, HIGH);
  digitalWrite(ENE, HIGH);
  DisplayMenu();
}

/*HeatTest*/
void Control3(){
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"TempTest");
  u8g2.sendBuffer();
  BUZA();
  
  while(digitalRead(ECC) == HIGH){
    float average = 0;
    for (int i=0; i< 3; i++) {
      average += analogRead(T1);
      delay(10);
    }
    average = average / 3;
    average = 1023 / average - 1;
    average = 4700 / average;
    TEMP1 = average / 100000;
    TEMP1 = log(TEMP1);
    TEMP1 /= 3950;
    TEMP1 += 1.0 / (25 + 273.15);
    TEMP1 = 1.0 / TEMP1;
    TEMP1 -= 273.15;
    
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB12_tr);
    u8g2.drawStr(2,20,"TEMP");
    u8g2.setFont(u8g2_font_helvB18_tr);
    u8g2.setCursor(2, 45);
    u8g2.print(TEMP1);
    u8g2.sendBuffer();
    if(TEMP1<50){
      analogWrite(HEAT1, 100);
      analogWrite(HEAT2, 100);
    }else{
      analogWrite(HEAT1, 0);
      analogWrite(HEAT2, 0);
    }
  }
  analogWrite(HEAT1, 0);
  analogWrite(HEAT2, 0);
  delay(500);
}

/*Fold*/
void Control4(){
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"Ready fold");
  u8g2.sendBuffer();
  BUZA();
  //准备状态
  digitalWrite(AIR1, LOW);
  digitalWrite(AIR2, HIGH);
  digitalWrite(AIR3, HIGH);
  digitalWrite(AIR4, LOW);
  digitalWrite(AIR5, LOW);
  digitalWrite(AIR6, LOW);
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"Please confirm");
  u8g2.sendBuffer();
  ShortPress();//请确认
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"Fold");
  u8g2.sendBuffer();
  delay(500);
  BUZB();
  Fold();
}

/*Laser*/
void Control5(){
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"LaserTest");
  u8g2.sendBuffer();
  BUZA();
  SETPWM = 0;
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(2, 20);
  u8g2.print(SETPWM);
  
  while(digitalRead(ECC) == HIGH){
    if(digitalRead(ECA) == 0){
      while(digitalRead(ECA)==0);
      if (digitalRead(ECB) == 0) {
        while(digitalRead(ECB)==0);
        if(SETPWM < 100) SETPWM += 10;
      } else {
        if(SETPWM > 0) SETPWM -= 10;
      }
    analogWrite(LASER, SETPWM*255/100);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB12_tr);
    u8g2.setCursor(2, 20);
    u8g2.print(SETPWM);
    u8g2.sendBuffer();
    }
  }
  SETPWM = 0;
  analogWrite(LASER, 0);
  DisplayMenu();
}

/*???*/
void Control6(){
  
}

/*ChooseRun*/
void Control(){
  switch(ECP){
  case 1:
  Homing();
  break;
  case 2:
  Control1();
  break;
  case 3:
  Control2();
  break;
  case 4:
  Control3();
  break;
  case 5:
  Control4();
  break;
  case 6:
  Control5();
  break;
  }
}
