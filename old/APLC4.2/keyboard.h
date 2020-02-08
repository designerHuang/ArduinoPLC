// Keyboard input
byte rows[] = {A10, A12, A14, 22};
// Keyboard outputs
byte cols[] = {A11, A13, A15, 23};

void keyboard() {
  //Serial.println("打开键盘");
  int key;
  digitalWrite(A11, LOW);
  digitalWrite(A13, LOW);
  digitalWrite(A15, LOW);
  digitalWrite(23, LOW);
  while (1) {
    if (digitalRead(A10) == LOW) {
      digitalWrite(A11, HIGH);
      if (digitalRead(A10) == HIGH) {
        key = 1;
        break;
      }
      digitalWrite(A13, HIGH);
      if (digitalRead(A10) == HIGH) {
        key = 2;
        break;
      }
      digitalWrite(A15, HIGH);
      if (digitalRead(A10) == HIGH) {
        key = 3;
        break;
      }
      digitalWrite(23, HIGH);
      if (digitalRead(A10) == HIGH) {
        key = 11;
        break;
      }
    }
    if (digitalRead(A12) == LOW) {
      digitalWrite(A11, HIGH);
      if (digitalRead(A12) == HIGH) {
        key = 4;
        break;
      }
      digitalWrite(A13, HIGH);
      if (digitalRead(A12) == HIGH) {
        key = 5;
        break;
      }
      digitalWrite(A15, HIGH);
      if (digitalRead(A12) == HIGH) {
        key = 6;
        break;
      }
      digitalWrite(23, HIGH);
      if (digitalRead(A12) == HIGH) {
        key = 22;
        break;
      }
    }
    if (digitalRead(A14) == LOW) {
      digitalWrite(A11, HIGH);
      if (digitalRead(A14) == HIGH) {
        key = 7;
        break;
      }
      digitalWrite(A13, HIGH);
      if (digitalRead(A14) == HIGH) {
        key = 8;
        break;
      }
      digitalWrite(A15, HIGH);
      if (digitalRead(A14) == HIGH) {
        key = 9;
        break;
      }
      digitalWrite(23, HIGH);
      if (digitalRead(A14) == HIGH) {
        key = 33;
        break;
      }
    }
    if (digitalRead(22) == LOW) {
      digitalWrite(A11, HIGH);
      if (digitalRead(22) == HIGH) {
        key = 55;
        break;
      }
      digitalWrite(A13, HIGH);
      if (digitalRead(22) == HIGH) {
        key = 0;
        break;
      }
      digitalWrite(A15, HIGH);
      if (digitalRead(22) == HIGH) {
        key = 66;
        break;
      }
      digitalWrite(23, HIGH);
      if (digitalRead(22) == HIGH) {
        key = 44;
        break;
      }
    }
  }
  digitalWrite(A11, LOW);
  digitalWrite(A13, LOW);
  digitalWrite(A15, LOW);
  digitalWrite(23, LOW);
  //Serial.println(key);
  num = key;
}
