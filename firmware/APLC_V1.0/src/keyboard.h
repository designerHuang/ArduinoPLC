void keyboard() {
  //Serial.println("kb");
  int key;
  digitalWrite(B02, LOW);
  digitalWrite(B04, LOW);
  digitalWrite(B06, LOW);
  digitalWrite(B08, LOW);
  while (1) {
    if (digitalRead(B01) == LOW) {
      digitalWrite(B02, HIGH);
      if (digitalRead(B01) == HIGH) {
        key = 1;
        break;
      }
      digitalWrite(B04, HIGH);
      if (digitalRead(B01) == HIGH) {
        key = 2;
        break;
      }
      digitalWrite(B06, HIGH);
      if (digitalRead(B01) == HIGH) {
        key = 3;
        break;
      }
      digitalWrite(B08, HIGH);
      if (digitalRead(B01) == HIGH) {
        key = 11;
        break;
      }
    }
    if (digitalRead(B03) == LOW) {
      digitalWrite(B02, HIGH);
      if (digitalRead(B03) == HIGH) {
        key = 4;
        break;
      }
      digitalWrite(B04, HIGH);
      if (digitalRead(B03) == HIGH) {
        key = 5;
        break;
      }
      digitalWrite(B06, HIGH);
      if (digitalRead(B03) == HIGH) {
        key = 6;
        break;
      }
      digitalWrite(B08, HIGH);
      if (digitalRead(B03) == HIGH) {
        key = 22;
        break;
      }
    }
    if (digitalRead(B05) == LOW) {
      digitalWrite(B02, HIGH);
      if (digitalRead(B05) == HIGH) {
        key = 7;
        break;
      }
      digitalWrite(B04, HIGH);
      if (digitalRead(B05) == HIGH) {
        key = 8;
        break;
      }
      digitalWrite(B06, HIGH);
      if (digitalRead(B05) == HIGH) {
        key = 9;
        break;
      }
      digitalWrite(B08, HIGH);
      if (digitalRead(B05) == HIGH) {
        key = 33;
        break;
      }
    }
    if (digitalRead(B07) == LOW) {
      digitalWrite(B02, HIGH);
      if (digitalRead(B07) == HIGH) {
        key = 44;
        break;
      }
      digitalWrite(B04, HIGH);
      if (digitalRead(B07) == HIGH) {
        key = 0;
        break;
      }
      digitalWrite(B06, HIGH);
      if (digitalRead(B07) == HIGH) {
        key = 55;
        break;
      }
      digitalWrite(B08, HIGH);
      if (digitalRead(B07) == HIGH) {
        key = 66;
        break;
      }
    }
  }
  digitalWrite(B02, LOW);
  digitalWrite(B04, LOW);
  digitalWrite(B06, LOW);
  digitalWrite(B08, LOW);
  //Serial.println(key);
  num = key;
}
