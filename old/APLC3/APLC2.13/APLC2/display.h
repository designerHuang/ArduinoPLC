#include <U8g2lib.h>
#include <SPI.h>
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, 52, 51, 30,31/*NO-Reset*/);

int menulvl = 0;
int menua;int menub;int menuc;int menud;int menum;

char *menus[10][10]={
  /*0  目录*/{"Select","Material","Control","Setting","Info"},
  /*1  启动*/{"<<","Template1","Template2","Template3"},
  /*2  上料*/{""},
  /*3  控制*/{"<<","Home",/*CT1*/"OutTest",/*CT2*/"MotorTest",/*CT3*/"HeatTest",/*CT4*/"Fold",/*CT5*/"Laser",/*CT6*/"???"},
  /*4  设置*/{"<<","SetCoordinate","SetSpeed","SetHeat","SetLaser"},
  /*4.1坐标*/{"<<","A","B","C","D","E","F"},};

char *runs[20]={
  /*00*/"Running...",
  /*01*/"Move to A",
  /*02*/"Take A",
  /*03*/"Move to C",
  /*04*/"Place A",
  /*05*/"Move to B",
  /*06*/"Take B",
  /*07*/"Move to C",
  /*08*/"Place B",
  /*09*/"Fold side",
  /*10*/"Heating side",
  /*11*/"Fold front",
  /*12*/"Heating front",
  /*13*/"Move to D",
  /*14*/"Move to E",
  /*15*/"Move to F",
  /*16*/"Place",
  /*17*/"Start Pressing",
  /*18*/"Carry out"};

char *pwmcontrol[10]={/*0*/"Running...",/*1*/"Running...",/*2*/"Running...",/*3*/"Running..."};

void DisplayLOGO(){
  tone(BUZ, 3000);
  u8g2.clearBuffer();
  u8g2.drawXBM( 42, 0, LOGO_width, LOGO_height, LOGO_bits);
  u8g2.sendBuffer();
  delay(1000);
  noTone(BUZ);
  delay(1000);
}

void DisplayMenu(){
  if(ECP < 3){
    menua = 0;
    menub = 1;
    menuc = 2;
    menud = 3;
    menum = ECP;
  }else{
    menua = ECP-3;
    menub = ECP-2;
    menuc = ECP-1;
    menud = ECP;
    menum = 3;
  }
  u8g2.clearBuffer();
  u8g2.setFontMode(1);
  u8g2.setDrawColor(1);
  u8g2.drawBox(0, menum*16, 128, 16);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setDrawColor(2);
  u8g2.setCursor(2, 14);
  u8g2.print(menus[menulvl][menua]);
  u8g2.setCursor(2, 30);
  u8g2.print(menus[menulvl][menub]);
  u8g2.setCursor(2, 46);
  u8g2.print(menus[menulvl][menuc]);
  u8g2.setCursor(2, 62);
  u8g2.print(menus[menulvl][menud]);
  u8g2.sendBuffer(); 
  while(digitalRead(ECC) == LOW);
  delay(5);
}

void DisplayRun(){
  u8g2.clearBuffer();
  u8g2.setFontMode(1);
  u8g2.setDrawColor(2);
  u8g2.setFont(u8g2_font_helvB18_tr);
  u8g2.drawStr(2,21,"Template");
  u8g2.setCursor(114, 21);
  u8g2.print(RunTemplate);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(2, 50);
  u8g2.print(runs[RunNow]);
  u8g2.sendBuffer();
}

void DisplayMaterial(){
  u8g2.clearBuffer();
  u8g2.setDrawColor(1);
  u8g2.drawFrame(5,5,118,20);
  u8g2.drawFrame(5,30,118,20);
  u8g2.drawBox(5,5,MCAPA*118/10000,20);
  u8g2.drawBox(5,5,MCAPB*118/10000,20);
  u8g2.sendBuffer();
}

void DisplayPWM(){
  
}

void DisplayInfo(){
  
  u8g2.clearBuffer();
  u8g2.setFontMode(1);   //透明字体
  u8g2.setDrawColor(1);  //选框
  u8g2.drawBox(53, 52, 22, 12);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setDrawColor(2);//反色显示
  u8g2.setCursor(54, 62);
  u8g2.print("<<");
  u8g2.setCursor(35, 14);
  u8g2.print("c 2019");
  u8g2.setCursor(15, 30);
  u8g2.print("Lishu Huang");
  u8g2.setCursor(18, 46);
  u8g2.print("MMP");
  u8g2.sendBuffer();
  while(digitalRead(ECC) == LOW);
  delay(5);
  while(digitalRead(ECC) == HIGH);  //按键返回
  menulvl = 0;
  ECP = 4;
}
