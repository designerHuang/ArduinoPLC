/*BUZ*/
void BUZ(int i) {
  if (i == 1) {
    //标准
    tone(buzPin, 3000);
    delay(1000);
  } else if (i == 2) {
    //快速双响
    tone(buzPin, 3000);
    delay(100);
    noTone(buzPin);
    delay(100);
    tone(buzPin, 3000);
    delay(100);
  } else if (i == 3) {
    //长响
    tone(buzPin, 3000);
    delay(2000);
  } else if (i == 4) {
    /*连续长响*/
    tone(buzPin, 3000);
    delay(1000);
    noTone(buzPin);
    delay(1000);
    tone(buzPin, 3000);
    delay(1000);
    noTone(buzPin);
    delay(1000);
    tone(buzPin, 3000);
    delay(1000);
  } else if (i == 5) {
    while (1) {
      tone(buzPin, 3000);
      delay(1000);
      noTone(buzPin);
      delay(1000);
    }
  }
  noTone(buzPin);
}

/*Homing*/
void homing() {
  Serial.println("***HOMING***");
  displayBasic();
  while (digitalRead(B01) == LOW);
  delay(50);

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
  average = 1031 / average - 1;
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
