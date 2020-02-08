/*Reset*/
void MaterialReset(){
  digitalWrite(DIRZ, LOW);
  digitalWrite(DIRE, LOW);
  while(digitalRead(LIMITA) == LOW && digitalRead(LIMITB) == LOW){
    digitalWrite(STEPZ, HIGH);
    digitalWrite(STEPE, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEPZ, LOW);
    digitalWrite(STEPE, LOW);
    delayMicroseconds(500);
    MCAPA++;
    MCAPB++;
  }
  while(digitalRead(LIMITA) == LOW){
    digitalWrite(STEPZ, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEPZ, LOW);
    delayMicroseconds(500);
    MCAPA++;
  }
  while(digitalRead(LIMITB) == LOW){
    digitalWrite(STEPE, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEPE, LOW);
    delayMicroseconds(500);
    MCAPB++;
  }
  MaterialReset();
    
  digitalWrite(DIRZ, LOW);
  digitalWrite(DIRE, LOW);
  for(int M = 0; M < min(MCAPA,MCAPB); M++){
    digitalWrite(STEPZ, HIGH);
    digitalWrite(STEPE, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEPZ, LOW);
    digitalWrite(STEPE, LOW);
    delayMicroseconds(500);
  }
  for(int M = 0; M < MCAPA; M++){
    digitalWrite(STEPZ, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEPZ, LOW);
    delayMicroseconds(500);
  }
  for(int M = 0; M < MCAPB; M++){
    digitalWrite(STEPE, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEPE, LOW);
    delayMicroseconds(500);
  }
}

/*Change*/
void MaterialChange(){
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"Material...");
  u8g2.sendBuffer();
  delay(500);
  while(digitalRead(ECC) == LOW); //复位按键
  digitalWrite(ENZ, HIGH);
  digitalWrite(ENE, HIGH);
  DisplayMaterial();
  if(MCAPA ==0 && MCAPB ==0)DisplayMaterial();  //复位
  while(digitalRead(ECC) == HIGH){
    if(digitalRead(SW1) == LOW){
      while(digitalRead(SW1) == LOW){
        if(MCAPA < 10000){
          digitalWrite(DIRZ, HIGH);
          digitalWrite(STEPZ, HIGH);
          delayMicroseconds(200);
          digitalWrite(STEPZ, LOW);
          delayMicroseconds(200);
          MCAPA--;
        }
      }
      DisplayMaterial();
    }else if(digitalRead(SW2) == LOW){
      while(digitalRead(SW2) == LOW){
        if(MCAPA > 0){
          digitalWrite(DIRZ, LOW);
        digitalWrite(STEPZ, HIGH);
        delayMicroseconds(200);
        digitalWrite(STEPZ, LOW);
        delayMicroseconds(200);
        MCAPA++;
        }
      }
      DisplayMaterial();
    }
    if(digitalRead(SW3) == LOW){
      while(digitalRead(SW3) == LOW){
        if(MCAPB < 10000){
          digitalWrite(DIRE, HIGH);
          digitalWrite(STEPE, HIGH);
          delayMicroseconds(200);
          digitalWrite(STEPE, LOW);
          delayMicroseconds(200);
          MCAPB--;
        }
      }
      DisplayMaterial();
    }else if(digitalRead(SW4) == LOW){
      while(digitalRead(SW4) == LOW){
        if(MCAPB > 0){
          digitalWrite(DIRE, LOW);
        digitalWrite(STEPE, HIGH);
        delayMicroseconds(200);
        digitalWrite(STEPE, LOW);
        delayMicroseconds(200);
        MCAPB++;
        }
      }
      DisplayMaterial();
    }
  }
}

/*检测*/
void MaterialDetection(){
  if(MCAPA == 0 && MCAPB == 0)DisplayMaterial();  //复位
  if(digitalRead(SW1) == HIGH){
    MJ = 1;
  }else{
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB12_tr);
    u8g2.drawStr(2,14,"No Material");
    u8g2.sendBuffer();
    while(digitalRead(ECC) == HIGH)digitalWrite(BUZ, HIGH); 
    digitalWrite(BUZ, LOW);
    MaterialChange();
    MJ = 0;
  }
}

/*出料*/
void MaterialDischange(){
  for(int M = 0; M < MTHKA; M++){
    digitalWrite(STEPZ, HIGH);
    delayMicroseconds(2000);
    digitalWrite(STEPZ, LOW);
    delayMicroseconds(2000);
  }
  for(int M = 0; M < MTHKB; M++){
    digitalWrite(STEPZ, HIGH);
    delayMicroseconds(2000);
    digitalWrite(STEPZ, LOW);
    delayMicroseconds(2000);
  }
}
