File myFile;
boolean restart = true;

void moveto(int coard) {
  Serial3.print("G1F");
  Serial3.print("1000");
  Serial3.print("X");
  Serial3.println(coard);
  xPos = coard;
  Serial.print("xPos: ");
  Serial.println(xPos);
}

void setPos() {
  Serial3.println("setPos");
  Serial3.print("F");
  Serial3.println(sSet);
  while (1) {
    if (digitalRead(A12) == LOW) {
      xPos += 1;
      Serial3.print("G1X");
      Serial3.println(xPos);
    }
    if(digitalRead(A10) == LOW)break;
    if(digitalRead(22) == LOW)break;
  }
}

void setGrbl() {
  Serial.println("$22=1");
  Serial.print("$100="); Serial.println(wheelX);
  Serial.print("$101="); Serial.println(wheelY);
  Serial.print("$102="); Serial.println(wheelZ);
  Serial.println("$110=30000");//最大速度mm/min
  Serial.println("$111=30000");
  Serial.println("$112=30000");
}

void emptySerialBuf(int serialNum) {
  //清空串行缓冲
  if (serialNum == 0) {
    while (Serial.available())
      Serial.read();
  } else if (serialNum == 1) {
    while (Serial3.available())
      Serial3.read();
  }
}

String readLine(File f) {
  //return line from file reading
  //从文件读取返回行
  char inChar;
  String line = "";
  do {
    inChar = (char)f.read();
    line += inChar;
  } while (inChar != '\n');
  return line;
}

void waitSerial(int serialNum) {
  //等待串口数据
  //Argument serialNum for Serial number
  boolean serialAv = false;
  if (serialNum == 0) {
    while (!serialAv) {
      if (Serial.available())
        serialAv = true;
    }
  }
  else if (serialNum == 1) {
    while (!serialAv) {
      if (Serial3.available())
        serialAv = true;
    }
  }
}

String getSerial(int serialNum) {
  //从串行线读取返回字符串
  //serialNum 是串口编号
  String inLine = "";
  waitSerial(serialNum);
  if (serialNum == 0) {
    while (Serial.available()) {
      inLine += (char)Serial.read();
      delay(2);
    }
    return inLine;
  }
  else if (serialNum == 1) {
    while (Serial3.available()) {
      inLine += (char)Serial3.read();
      delay(2);
    }
    return inLine;
  }
}

void sendGcode() {

  String line = "";
  Serial3.print("\r\n\r\n");      //唤醒GRBL
  delay(2);
  emptySerialBuf(1);
  if (myFile) {
    while (myFile.available()) {  //直到文件结束
      line = readLine(myFile);  //读取GCODE的行
      Serial.print(line);   //发送至SERIAL
      Serial3.print(line);
      Serial.print(getSerial(1)); //打印GRBL返回信息
    }
  }
  else {
    Serial.println("\n");
    Serial.println("File Error !");
  }
}
