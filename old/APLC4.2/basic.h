/*Homing*/
void homing() {
  Serial.println("***HOMING***");
  displayBasic();
  while (digitalRead(22) == LOW);
  delay(50);
  Serial3.print("\r\n\r\n");
  Serial3.println("$H");
  xPos=5;
  yPos=5;
  zPos=5;
}

/*Temp*/
void temp(int i) {
  float average = 0;
  if (i == 0) {
    for (int j = 0; j < 3; j++) {
      average += analogRead(A0);
      delay(10);
    }
  } else if (i == 1) {
    for (int j = 0; j < 3; j++) {
      average += analogRead(A1);
      delay(10);
    }
  }
  average = average / 3;
  average = 1023 / average - 1;
  average = 4700 / average;
  average = average / 100000;
  average = log(average);
  average /= 3950;
  average += 1.0 / (25 + 273.15);
  average = 1.0 / average;
  average -= 273.15;
  return (average);
}

void Matera() {
  switch (menucount) {
    case 1:

      break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    case 5:

      break;
  }
}

/*BUZ*/
void BUZ(int i) {
  if (i == 1) {
    //标准
    tone(32, 3000);
    delay(1000);
  } else if (i == 2) {
    //快速双响
    tone(32, 3000);
    delay(100);
    noTone(32);
    delay(100);
    tone(32, 3000);
    delay(100);
  } else if (i == 3) {
    //短响
    tone(32, 4000);
    delay(50);
  } else if (i == 4) {
    /*连续长响*/
    tone(32, 3000);
    delay(1000);
    noTone(32);
    delay(1000);
    tone(32, 3000);
    delay(1000);
    noTone(32);
    delay(1000);
    tone(32, 3000);
    delay(1000);
  } else if (i == 5) {
    while (1) {
      tone(32, 3000);
      delay(1000);
      noTone(32);
      delay(1000);
    }
  }
  noTone(32);
}
