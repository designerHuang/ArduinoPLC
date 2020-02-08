void running() {
  //这是一个示例，三个小的循环完成后触发
  Serial.println("开始运行的循环");
  if (locationNum == 0) {
    moveto(coordC);
    locationNum++;
    if ((num + 1) == runNum) {
      Serial.print("压烫\n");
    }
  } else if (locationNum == 1) {
    moveto(coordD);
    locationNum++;
    if ((num + 1) == runNum) {
      Serial.print("压烫\n");
    }
  } else if (locationNum == 2) {
    moveto(coordE);
    locationNum = 0;
    Serial.print("压烫\n");
  }
}

//设置主程序循环次数
void setRun() {
  Serial.print("\n");
  Serial.println("***READY***");
  runNum = 0;
  locationNum = 0;
  displayNum();
  while (digitalRead(B07) == LOW);
  delay(20);
  //Serial.print("运行模板:");
  //Serial.println(templateNum);
  Serial.print("加工数量:");
  while (1) {
    keyboard();
    if (num == 11) {
      Serial.print("\n");
      return;
    } else if (num == 66) {
      Serial.print("\n");
      break;
    } else if (num == 22 or num == 33 or num == 44 or num == 55) {

    } else {
      Serial.print(num);
      runNum = runNum * 10 + num;
      displayNum();
    }
    while (digitalRead(B01) == LOW);
    while (digitalRead(B03) == LOW);
    while (digitalRead(B05) == LOW);
    while (digitalRead(B07) == LOW);
    delay(20);
  }
  Serial.println("2S后启动");
  BUZ(2);
  delay(2000);
  homing();
  for (num = 0; num < runNum; num++) {
    Serial.print("正在加工:");
    Serial.print(num + 1);
    Serial.print("/");
    Serial.println(runNum);
    displayRun();
    running();
  }
  Serial.println("***COMPLETE***\n");
}

//启动后自动运行一次
void startUser() {
  EEPROM.get(65, A);
  EEPROM.get(69, B);
  EEPROM.get(73, C);
  EEPROM.get(77, D);
  EEPROM.get(81, E);
  EEPROM.get(85, F);
  //EEPROM.get(89,C1);
  digitalWrite(X_ENABLE_PIN, HIGH);
  digitalWrite(Y_ENABLE_PIN, HIGH);
  digitalWrite(Z_ENABLE_PIN, HIGH);

  StepperX.setMaxSpeed(SMOVE);
  StepperY.setMaxSpeed(SMOVE);
  steppers.addStepper(StepperX);
  steppers.addStepper(StepperY);

}
