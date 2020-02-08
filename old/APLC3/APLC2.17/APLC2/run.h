void Running(){
  RunNow = 1; //移动到A
  SI = 1;
  Serial.print("*01* 移动到A ");
  Serial.println(A);
  DisplayRun();
  positions[0] = A;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  RunNow = 2; //取料A
  Serial.println("*02* 取料A");
  DisplayRun();
  digitalWrite(AIR2, LOW);
  digitalWrite(AIR1, HIGH);
  digitalWrite(AIR3, HIGH);
  delay(200);
  digitalWrite(NP1, HIGH);
  delay(500);
  digitalWrite(AIR1, LOW);
  delay(200);
  
  RunNow = 3; //移动到C
  Serial.print("*03* 移动到C ");
  Serial.println(C);
  DisplayRun();
  positions[0] = C; 
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  RunNow = 4;
  Serial.println("*04* 放料A");
  DisplayRun();
  digitalWrite(AIR1, HIGH);
  delay(200);
  digitalWrite(NP1, LOW);
  digitalWrite(NP2, HIGH);
  delay(300);
  digitalWrite(AIR1, LOW);
  delay(200);
  
  RunNow = 5;
  Serial.print("*05* 移动到B ");
  Serial.println(B);
  DisplayRun();
  positions[0] = B;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  RunNow = 6;
  Serial.println("*06* 取料B");
  digitalWrite(NP1, HIGH);
  digitalWrite(AIR1, HIGH);
  delay(500);
  digitalWrite(AIR1, LOW);
  
  RunNow = 7;
  Serial.print("*07* 移动到C ");
  Serial.println(C);
  DisplayRun();
  positions[0] = C;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  RunNow = 8;
  Serial.println("*08* 放料B");
  DisplayRun();
  digitalWrite(AIR1, HIGH);
  digitalWrite(NP1, LOW);
  delay(300);
  
  RunNow = 9;
  Serial.println("*09* 折叠");
  DisplayRun();
  
  Fold();

  if(Completed == 0){
    RunNow = 13;
    DisplayRun();
    positions[0] = F; //D
    Serial.print("*10* 移动到F ");
    Serial.println(F);
    Completed++;
  } else if (Completed == 1){
    RunNow = 14;
    DisplayRun();
    positions[0] = E; //E
    Serial.print("*10* 移动到E ");
    Serial.println(E);
    Completed++;
  } else {
    RunNow = 15;
    DisplayRun();
    positions[0] = D; //F
    Serial.print("*10* 移动到D ");
    Serial.println(D);
    Completed = 0;
  }
  RunNow = 16;
  DisplayRun();
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  RunNow = 17;
  Serial.println("*11* 放料");
  DisplayRun();
  digitalWrite(NP1, LOW);
  digitalWrite(AIR1, HIGH);
  delay(500);
  digitalWrite(AIR1, LOW);
  delay(200);
  RunNow = 18;
  DisplayRun();
  Serial.print("*12* 移动到C ");
  Serial.println(C);
  positions[0] = C;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
}
void Run(){ 
  /*导入数据*/
  Serial.print("选择模板:");
  Serial.println(ECP);
  HTA = templatedata[ECP-1][0];
  HTB = templatedata[ECP-1][1];
  HTEMP = templatedata[ECP-1][2];
  MTHKA = templatedata[ECP-1][3];
  MTHKB = templatedata[ECP-1][4];
  Serial.print("模板数据:");
  Serial.print("侧加热时间：");
  Serial.print(HTA);
  Serial.print(",");
  Serial.print("前加热时间：");
  Serial.print(HTB);
  Serial.print(",");
  Serial.print("加热温度：");
  Serial.print(HTEMP);
  Serial.print(",");
  Serial.print("料A厚度：");
  Serial.print(MTHKA);
  Serial.print(",");
  Serial.print("料B厚度：");
  Serial.println(MTHKB);
  /*设置数量*/
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  ECP = 0;
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.drawStr(2,20,"SetQuantity");
  u8g2.setCursor(2, 40);
  u8g2.print(ECP);
  u8g2.sendBuffer();
  /*计数器*/
  Serial.print("设置数量:");
  while(digitalRead(ECC) == HIGH){
    if(digitalRead(ECA) == 0){
      while(digitalRead(ECA)==0);
      if (digitalRead(ECB) == 0) {
        while(digitalRead(ECB)==0);
        ECP++;
      } else {
        if(ECP > 0) ECP--;
      }
      u8g2.clearBuffer();
      u8g2.setFont(u8g2_font_helvB12_tr);
      u8g2.drawStr(2,20,"SetQuantity");
      u8g2.setCursor(2, 40);
      u8g2.print(ECP);
      u8g2.sendBuffer();
    }
  }
  Serial.println(ECP);
  /*循环程序*/
  delay(500);
  BUZB();
  Serial.println("Homing...");
  Homing();
  for(int i = 0; i<ECP; i++){
    Serial.println(" ");
    Serial.print("run:");
    Serial.println(i+1);
    MaterialDetection();  //检测料仓
    Running();  //主程序
    /*压烫*/
    if(Completed == 0){
      Serial.println("*13* 打开压烫");
      digitalWrite(AIR6, HIGH);
      delay(2000);
      Serial.println("*14* 关闭压烫");
      digitalWrite(AIR6, LOW);
    }else if((ECP - i) < 2){
      Serial.println("*13* 打开压烫");
      digitalWrite(AIR6, HIGH);
      delay(2000);
      Serial.println("*14* 关闭压烫");
      digitalWrite(AIR6, LOW);
    }
  }
  digitalWrite(AIR3, LOW);
  Serial.println("完成循环");
  Serial.println(" ");
  digitalWrite(ENX, HIGH);
  ECP = 0;
  DisplayMenu();
}
