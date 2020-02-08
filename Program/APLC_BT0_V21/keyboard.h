void keyboard() {
  int key;
  digitalWrite(37, LOW);
  digitalWrite(35, LOW);
  digitalWrite(33, LOW);
  digitalWrite(31, LOW);
  while (1) {
    if (digitalRead(40) == LOW) {
      digitalWrite(37, HIGH);
      if (digitalRead(40) == HIGH) {
        key = 1;
        break;
      }
      digitalWrite(35, HIGH);
      if (digitalRead(40) == HIGH) {
        key = 2;
        break;
      }
      digitalWrite(33, HIGH);
      if (digitalRead(40) == HIGH) {
        key = 3;
        break;
      }
      digitalWrite(31, HIGH);
      if (digitalRead(40) == HIGH) {
        key = 11;
        break;
      }
    }
    if (digitalRead(36) == LOW) {
      digitalWrite(37, HIGH);
      if (digitalRead(36) == HIGH) {
        key = 4;
        break;
      }
      digitalWrite(35, HIGH);
      if (digitalRead(36) == HIGH) {
        key = 5;
        break;
      }
      digitalWrite(33, HIGH);
      if (digitalRead(36) == HIGH) {
        key = 6;
        break;
      }
      digitalWrite(31, HIGH);
      if (digitalRead(36) == HIGH) {
        key = 32;
        break;
      }
    }
    if (digitalRead(34) == LOW) {
      digitalWrite(37, HIGH);
      if (digitalRead(34) == HIGH) {
        key = 7;
        break;
      }
      digitalWrite(35, HIGH);
      if (digitalRead(34) == HIGH) {
        key = 8;
        break;
      }
      digitalWrite(33, HIGH);
      if (digitalRead(34) == HIGH) {
        key = 9;
        break;
      }
      digitalWrite(31, HIGH);
      if (digitalRead(34) == HIGH) {
        key = 33;
        break;
      }
    }
    if (digitalRead(32) == LOW) {
      digitalWrite(37, HIGH);
      if (digitalRead(32) == HIGH) {
        key = 55;
        break;
      }
      digitalWrite(35, HIGH);
      if (digitalRead(32) == HIGH) {
        key = 0;
        break;
      }
      digitalWrite(33, HIGH);
      if (digitalRead(32) == HIGH) {
        key = 66;
        break;
      }
      digitalWrite(31, HIGH);
      if (digitalRead(32) == HIGH) {
        key = 44;
        break;
      }
    }
  }
  digitalWrite(37, LOW);
  digitalWrite(35, LOW);
  digitalWrite(33, LOW);
  digitalWrite(31, LOW);
  //Serial.println(key);
  num = key;
}
