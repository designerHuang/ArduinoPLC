void outTest() {
  Serial.println("***OUT TEST***");
  BUZ(2);
  displayControl();
  while (digitalRead(B01) == LOW);
  delay(20);
  while (digitalRead(B01) == HIGH) {
    digitalWrite(OUT01, HIGH);
    digitalWrite(OUT02, HIGH);
    digitalWrite(OUT03, HIGH);
    digitalWrite(OUT04, HIGH);
    digitalWrite(OUT05, HIGH);
    digitalWrite(OUT06, HIGH);
    digitalWrite(OUT07, HIGH);
    digitalWrite(OUT08, HIGH);
    digitalWrite(OUT09, HIGH);
    digitalWrite(OUT10, HIGH);
    delay(1000);
    digitalWrite(OUT01, LOW);
    digitalWrite(OUT02, LOW);
    digitalWrite(OUT03, LOW);
    digitalWrite(OUT04, LOW);
    digitalWrite(OUT05, LOW);
    digitalWrite(OUT06, LOW);
    digitalWrite(OUT07, LOW);
    digitalWrite(OUT08, LOW);
    digitalWrite(OUT09, LOW);
    digitalWrite(OUT10, LOW);
    delay(1000);
  }
}

void motorTest() {
  int interval=200;
  Serial.println("***MOTOR TEST***");
  BUZ(2);
  displayControl();
  while (digitalRead(B01) == LOW);
  delay(20);
  digitalWrite(X_ENABLE_PIN, LOW);
  while (digitalRead(B01) == HIGH) {
    digitalWrite(X_DIR_PIN, HIGH);
    for (int i = 0; i < 20000; i++) {
      digitalWrite(X_STEP_PIN, HIGH);
      digitalWrite(X_STEP_PIN, LOW);
      delayMicroseconds(100);
    }
    digitalWrite(X_DIR_PIN, LOW);
    for (int i = 0; i < 20000; i++) {
      digitalWrite(X_STEP_PIN, HIGH);
      digitalWrite(X_STEP_PIN, LOW);
      delayMicroseconds(50);
      }
    }
  digitalWrite(X_ENABLE_PIN, HIGH);
}

void serialforward() {
  Serial.println("***SERIAL FORWARD***");
  BUZ(2);
  displayControl();
  while (digitalRead(B01) == LOW);
  delay(20);
  while (digitalRead(B01) == HIGH) {
    if (Serial3.available()) {
      int data = Serial3.read();
      Serial.write(data);
    }
    if (Serial.available()) {
      int data = Serial.read();
      Serial3.write(data);
    }
  }
}

void liserTest() {
  Serial.println("***LISER TEST***");
  BUZ(2);
  displayControl();
  while (digitalRead(B01) == LOW);
  delay(20);
  while (digitalRead(B01) == HIGH) {
  }
}

void Control() {
  switch (menucount) {
    case 0:
      homing();
      break;
    case 1:
      outTest();
      break;
    case 2:
      motorTest();
      break;
    case 3:
      serialforward();
      break;
    case 4:
      liserTest();
      break;
  }
}
