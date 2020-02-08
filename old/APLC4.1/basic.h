/*Homing*/
void Homing(){
  Serial3.print("\r\n\r\n");
}

/**/

/*BUZ*/
void BUZA(){  /*基础*/
  tone(BUZ, 3000);
  delay(1000);
  noTone(BUZ);
}
void BUZB(){  /*快速双响*/
  tone(BUZ, 3000);
  delay(200);
  noTone(BUZ);
  delay(200);
  tone(BUZ, 3000);
  delay(200);
  noTone(BUZ);
}
void BUZC(){  /*长响*/
  tone(BUZ, 3000);
  delay(800);
  noTone(BUZ);
}
void BUZD(){  /*连续长响*/
  tone(BUZ, 3000);
  delay(1000);
  noTone(BUZ);
  delay(1000);
  tone(BUZ, 3000);
  delay(1000);
  noTone(BUZ);
  delay(1000);
  tone(BUZ, 3000);
  delay(1000);
  noTone(BUZ);
}
void BUZE(){  /*故障*/
  while(1){
    tone(BUZ, 3000);
    delay(1000);
    noTone(BUZ);
    delay(1000);
  }
}
