//---------------------------------buz-------------------------------------------
void Buz(int buz){
  switch (buz)
  {
    //convention
    case 0:
    tone(BUZ,3000);
    delay(1000);
    noTone(BUZ);
    break;
    // quick double
    case 1:
    tone(BUZ,3000);
    delay(100);
    noTone(BUZ);
    tone(BUZ,3000);
    delay(100);
    noTone(BUZ);
    break;
    // breakdowm
    case 2:
    tone(BUZ,3000);
    break;
    // default
    default :
    Serial.println("buz default");
    break;
  }
}