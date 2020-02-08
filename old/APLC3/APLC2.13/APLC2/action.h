#include <AccelStepper.h>
#include <MultiStepper.h>
AccelStepper StepperX(1, STEPX, DIRX);
AccelStepper StepperY(1, STEPY, DIRY);
MultiStepper steppers;

/*Homing*/
void Homing(){ 
  HOMEDATA = 1; 
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB18_tr);
  u8g2.drawStr(2,20,"Homing...");
  u8g2.sendBuffer();
  digitalWrite(ENX, LOW);
  //气缸复位
  digitalWrite(AIR1, LOW);
  delay(200);
  digitalWrite(AIR2, LOW);
  digitalWrite(AIR3, LOW);
  digitalWrite(AIR4, LOW);
  delay(300);
  //步进电机复位
  StepperX.setCurrentPosition(0); 
  while (digitalRead(LIMITX) == LOW) {
    StepperX.setSpeed(SHOME);
    StepperX.runSpeed();
    StepperX.setCurrentPosition(0); 
    StepperY.setCurrentPosition(0); 
  }
  Serial.print("X:");
  Serial.print(StepperX.currentPosition());
  Serial.print(" Y:");
  Serial.println(StepperY.currentPosition());
  while (StepperX.currentPosition() != 400) {
    StepperX.setSpeed(200);
    StepperX.run();
  }
}

/*Fold*/
void Fold(){
  delay(500);
  digitalWrite(AIR2, HIGH);
  delay(500);
  digitalWrite(AIR2, LOW);
  delay(300);
  digitalWrite(NP1, LOW);
  digitalWrite(NP2, HIGH);
  delay(1000);
  digitalWrite(AIR4, HIGH);
  delay(1000);
  digitalWrite(AIR3, LOW);
  delay(1000);
  analogWrite(HEAT1, 255);
  digitalWrite(AIR2, HIGH);
  delay(HTA); 
  analogWrite(HEAT1, 0);
  digitalWrite(AIR4, LOW);
  delay(500);
  digitalWrite(AIR3, HIGH);
  delay(500);
  digitalWrite(AIR2, LOW);
  delay(500);
  
  digitalWrite(AIR5, HIGH);
  delay(1000);
  digitalWrite(AIR3, LOW);
  delay(1000);
  digitalWrite(AIR2, HIGH);
  analogWrite(HEAT2, 255);
  delay(HTB);
  analogWrite(HEAT2, 0);
  
  digitalWrite(AIR5, LOW);
  delay(500);
  
  digitalWrite(AIR3, HIGH);
  delay(1000);
  digitalWrite(AIR2, LOW);
  delay(500);
  digitalWrite(NP1, HIGH);
  digitalWrite(NP2, LOW);
  delay(1000);
  digitalWrite(AIR1, LOW);
  delay(200);
}

/*Confirm Press*/
void ShortPress(){
  while(1){
    if(digitalRead(ECC) == LOW)TIME++;
    else TIME = 0;
    delay(10);
    if(TIME > 5)break;
    }
  }
void LongPress(){
  while(1){
    if(digitalRead(ECC) == LOW)TIME++;
    else TIME = 0;
    delay(10);
    if(TIME > 50)break;
    }
  }

/*BUZ*/
void BUZA(){  /*基础*/
  tone(BUZ, 3000);
  delay(800);
  noTone(BUZ);
}
void BUZB(){  /*快速双响*/
  tone(BUZ, 3000);
  delay(300);
  noTone(BUZ);
  delay(200);
  tone(BUZ, 3000);
  delay(300);
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
