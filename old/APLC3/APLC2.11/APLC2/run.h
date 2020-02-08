void Running(){
  if(FirstRun == 0){
    FirstRun = 1;
    delay(500);
    Homing();
  }
  RunNow = 1; //移动到A
  SI = 1;
  DisplayRun();
  positions[0] = A;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  RunNow = 2; //取料A
  SI = 10;
  DisplayRun();
  digitalWrite(AIR1, HIGH);//下压核心
  delay(200);
  digitalWrite(NP1, HIGH);//吸气
  delay(500);
  digitalWrite(AIR1, LOW);//抬起核心
  delay(200);
    
  RunNow = 3; //移动到C
  SI = 15;
  DisplayRun();
  positions[0] = C; 
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  RunNow = 4;//放料A
  SI = 25;
  DisplayRun();
  digitalWrite(AIR1, HIGH);//下压核心
  delay(200);
  digitalWrite(NP1, LOW);//关闭模具吸气
  digitalWrite(NP2, HIGH); //打开桌面吸气
  delay(300);
  digitalWrite(AIR1, LOW);//抬起核心
  delay(200);
  digitalWrite(NP2, HIGH); 
  delay(200);
  
  RunNow = 5;//移动到B
  SI = 30;
  DisplayRun();
  positions[0] = B;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  RunNow = 6;//取料B
  SI = 40;
  digitalWrite(NP1, HIGH);//打开模具吸气
  digitalWrite(AIR1, HIGH);//下压核心
  delay(500);
  digitalWrite(AIR1, LOW);//抬起核心
  
  RunNow = 7;//移动到C
  SI = 45;
  DisplayRun();
  positions[0] = C;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  RunNow = 8;//放料B
  SI = 50;
  DisplayRun();
  digitalWrite(AIR1, HIGH);//下压核心
  digitalWrite(NP1, LOW);//关闭模具吸气
  delay(300);
  
  RunNow = 9;
  SI = 55;
  DisplayRun();
  Fold();//折叠

  if(Completed == 0){
    RunNow = 13;
    SI = 85;
    DisplayRun();
    positions[0] = D; //D
    Completed++;
  } else if (Completed == 1){
    RunNow = 14;
    SI = 85;
    DisplayRun();
    positions[0] = E; //E
    Completed++;
  } else {
    RunNow = 15;
    SI = 85;
    DisplayRun();
    positions[0] = F; //F
    Completed = 0;
  }
  RunNow = 16;
  SI = 90;
  DisplayRun();
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  RunNow = 17;
  SI = 95;
  DisplayRun();
  /*压烫*/
  
  /*显示完成*/
  RunNow = 18;
  SI = 100;
  DisplayRun();
  positions[0] = A;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
}

/*设置数量，导入数据*/
void Run(){ 
  /*设置加工数量*/
  u8g2.clearBuffer();
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  delay(200);
  ECP = 0;
  while(digitalRead(ECC) == HIGH){
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB12_tr);
    u8g2.drawStr(2,20,"SetQuantity");
    u8g2.setCursor(2, 40);
    u8g2.print(ECP);
    u8g2.sendBuffer();
  }
  if(RunTemplate == 0){
    RunTemplate = 1;
    HTA = templatedata[ECP-1][0];
    HTB = templatedata[ECP-1][1];
    HTEMP = templatedata[ECP-1][2];
    MTHKA = templatedata[ECP-1][3];
    MTHKB = templatedata[ECP-1][4];
  }
  /*循环程序*/
  for(int i; i<ECP; i++){
    while(MJ == 0){
      MaterialDetection();  //检测料仓
    }
    Running();
  }
}
