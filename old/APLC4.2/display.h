#include <U8g2lib.h>
#include <SPI.h>
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, 52, 51, 30, 28/*NO-Reset*/);

int menuv; int menucount;
int menua; int menub; int menuc; int menud; int menum;

char *menutxt[10][10] = {
  /*0  目录*/{"Select", "Material", "Control", "Setting"},
  /*1  上料*/{"11", "22", "33", "HeatTest", "Fold", "Laser", "???"},
  /*2  控制*/{"Home", "OutTest", "MotorTest", "Serial Forward", "Laser Test"},
  /*3  设置*/{ "SetCoord", "SetSpeed", "SetLaser"},
  /*4  坐标*/{"A", "B", "C", "D", "E", "F"},
};
char *basictxt[5] = {"Homing", "OutTest", "MotorTest", "Serial Forward", "Laser Test"};
char *controltxt[5] = {"Homing", "OutTest", "MotorTest", "Serial Forward", "Laser Test"};
char *settxt[5] = {"c1", "c2", "c3", "c4", "c5"};

void displayNum() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(2, 20);
  u8g2.print("runNum:");
  u8g2.setCursor(2, 40);
  u8g2.print(runNum);
  u8g2.sendBuffer();
}

void displayRun() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(2, 20);
  u8g2.print("Now:");
  u8g2.setCursor(2, 40);
  u8g2.print(num+1);
  u8g2.sendBuffer();
}

void displayBasic() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(2, 20);
  u8g2.print(basictxt[menucount]);
  u8g2.sendBuffer();
}

void displayControl() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(2, 20);
  u8g2.print(controltxt[menucount]);
  u8g2.sendBuffer();
}

void displaySet() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(2, 20);
  u8g2.print(settxt[menucount]);
  u8g2.sendBuffer();
}

void displayMenu() {
  if (menucount < 3) {
    menua = 0;
    menub = 1;
    menuc = 2;
    menud = 3;
    menum = menucount;
  } else {
    menua = menucount - 3;
    menub = menucount - 2;
    menuc = menucount - 1;
    menud = menucount;
    menum = 3;
  }
  u8g2.clearBuffer();
  u8g2.setFontMode(1);
  u8g2.setDrawColor(1);
  u8g2.drawBox(0, menum * 16, 128, 16);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setDrawColor(2);
  u8g2.setCursor(2, 14);
  u8g2.print(menutxt[menuv][menua]);
  u8g2.setCursor(2, 30);
  u8g2.print(menutxt[menuv][menub]);
  u8g2.setCursor(2, 46);
  u8g2.print(menutxt[menuv][menuc]);
  u8g2.setCursor(2, 62);
  u8g2.print(menutxt[menuv][menud]);
  u8g2.sendBuffer();

  Serial.print("menuv:");
  Serial.print(menuv);
  Serial.print(" menucount:");
  Serial.println(menucount);
}

void displayLogo() {
  u8g2.clearBuffer();
  u8g2.drawXBM( 42, 0, LOGO_width, LOGO_height, LOGO_bits);
  u8g2.sendBuffer();
  delay(500);
}
