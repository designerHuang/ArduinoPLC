void outTest() {

}

void motorTest() {

}

/*串口转发*/
void serialforward() {
  Serial.println("***SERIAL FORWARD***");
  displayControl();
  while (digitalRead(A10) == LOW);
  delay(20);
  while (digitalRead(A10) == HIGH) {
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
