#include <AccelStepper.h>
#include <MultiStepper.h>
AccelStepper StepperX(1, STEPX, DIRX);
AccelStepper StepperY(1, STEPY, DIRY);
MultiStepper steppers;

/*Homing*/
void Homing(){ 
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
  delay(800);
  //步进电机
  StepperX.setCurrentPosition(0); 
  /*
  while (digitalRead(LIMITX) == LOW) {
    StepperX.setSpeed(SHOME);
    StepperX.runSpeed();
    StepperX.setCurrentPosition(0); 
  }
  while (StepperX.currentPosition() != 400) {
    StepperX.setSpeed(200);
    StepperX.run();
  }
  */
}

/*Fold*/
void Fold(){
  digitalWrite(AIR2, HIGH);//抬起模具
  delay(500);
  digitalWrite(AIR2, LOW);//下压模具
  digitalWrite(AIR1, HIGH);//下压中心板
  delay(500);
  digitalWrite(AIR4, HIGH);//左右插进
  delay(500);
  digitalWrite(AIR3, LOW);//模具抽出
  delay(500);
  analogWrite(HEAT1, 255);//左右加热
  digitalWrite(AIR2, LOW);//上抬模具
  delay(5000);  //加热5秒钟
  analogWrite(HEAT1, 0);//关闭加热
  digitalWrite(AIR3, HIGH);//伸出模具
  delay(500);
  digitalWrite(AIR2, HIGH);//下压模具
  delay(200);
  digitalWrite(AIR4, LOW);//左右抽出
  delay(500);
  digitalWrite(AIR5, HIGH);//伸出前模具
  delay(500);
  digitalWrite(AIR3, LOW);//抽出模具
  delay(300);
  digitalWrite(AIR2, LOW);//上抬模具
  analogWrite(HEAT2, 255);//前加热
  delay(5000);  //加热5秒钟
  analogWrite(HEAT2, 0);//关闭加热
  digitalWrite(AIR3, HIGH);//伸出模具
  delay(500);
  digitalWrite(AIR2, HIGH);//下压模具
  delay(200);
  //模具吸气
  digitalWrite(AIR5, LOW);//前抽出
  delay(500);
  digitalWrite(NP2, LOW);//关闭桌面吸气
  delay(200);
  digitalWrite(AIR1, LOW);//抬起中心板
  delay(300);
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
  tone(BUZ, 3000);
}
