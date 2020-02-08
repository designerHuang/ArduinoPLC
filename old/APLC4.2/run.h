void running() {
  moveto(coordA);
  moveto(coordB);
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

void run() {
  Serial.print("\n");
  Serial.println("***RUNNING***");
  runNum = 0;
  locationNum = 0;
  displayNum();
  while (digitalRead(22) == LOW);
  delay(20);
  //Serial.print("运行模板:");
  //Serial.println(templateNum);
  Serial.print("加工数量:");
  while (1) {
    keyboard();
    if (num == 11) {
      Serial.print("\n");
      Serial.println("←\n");
      return;
    } else if (num == 44) {
      Serial.print("\n");
      break;
    } else if (num == 22 or num == 33) {

    } else {
      Serial.print(num);
      runNum = runNum * 10 + num;
      displayNum();
    }
    while (digitalRead(A10) == LOW);
    while (digitalRead(A12) == LOW);
    while (digitalRead(A14) == LOW);
    while (digitalRead(22) == LOW);
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
