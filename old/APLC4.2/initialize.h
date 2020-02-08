/*检查，读取上次设定*/
void initialize() {
  Serial.println("***RESET***");
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB10_tf);
  u8g2.drawStr(2, 12, "APLC V4.0");
  u8g2.sendBuffer();
  delay(50);
  //检查电压
  Serial.print("Voltage: ");
  Serial.println("???");
  u8g2.setFont(u8g2_font_helvB08_tf);
  u8g2.drawStr(2, 22, "Voltage:");
  u8g2.sendBuffer();
  delay(50);
  u8g2.drawStr(65, 22, "24V");
  u8g2.sendBuffer();
  delay(100);
  //检查grbl
  u8g2.drawStr(2, 32, "GRBL:");
  u8g2.sendBuffer();

  Serial.print("GRBL: ");
  timer = millis();
  num = 0;
  //GRBL
  while (1) {
    Serial3.print("\n");
    if (Serial3.available() != 0) {
      Serial.println("OK");
      u8g2.drawStr(65, 32, "OK");
      u8g2.sendBuffer();
      break;
    } else {
      num++;
      if (num == 20) {
        Serial.println("NO");
        u8g2.drawStr(65, 32, "NO");
        u8g2.sendBuffer();
        while (1);
      }
    }
    delay(100);
  }
  delay(100);
  //检查SD卡
  u8g2.drawStr(2, 42, "SD card:");
  u8g2.sendBuffer();
  Serial.println("SD card: Disable");
  delay(100);
  u8g2.drawStr(65, 42, "Disable");
  u8g2.sendBuffer();
  /*
    if (!SD.begin(53)) {
    Serial.println("NO");
    u8g2.drawStr(65, 42, "NO");
    u8g2.sendBuffer();
    } else {
    Serial.println("OK");
    u8g2.drawStr(65, 42, "OK");
    u8g2.sendBuffer();
    }
  */
  //读取参数
  u8g2.drawStr(2, 52, "Read data...");
  u8g2.sendBuffer();
  EEPROM.get(20, templateNum);
  EEPROM.get(65, coordA);
  EEPROM.get(69, coordB);
  EEPROM.get(73, coordC);
  EEPROM.get(77, coordD);
  EEPROM.get(81, coordE);
  EEPROM.get(85, coordF);
  Serial.println("Read data: OK\n");
  u8g2.drawStr(65, 52, "OK");
  u8g2.sendBuffer();
  delay(1000);
}
