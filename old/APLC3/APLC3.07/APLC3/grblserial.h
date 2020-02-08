/*
  grblserial.h
*/
void startGRBL(){
  Serial3.print("\r\n\r\n");
  delay(2);
}


void checkSD(){
  //检查SD卡
  while(!SD.begin(53)){
    Serial.println("Please insert SD card...\n");
    delay(1000);
  }
  Serial.println("SD card OK...\n");
  delay(1000);
}

void sendGcode(){
  String line = "";
  
}
