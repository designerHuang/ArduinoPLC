/*
  grblserial.h
*/

void checkSD(){
  //检查SD卡
  while(!SD.begin(53)){
    Serial.println("Please insert SD card...\n");
    delay(1000);
  }
  Serial.println("SD card OK...\n");
  delay(1000);
}
