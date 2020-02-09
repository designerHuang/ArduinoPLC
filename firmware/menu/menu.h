/*
  ================================================================================
  char *M0 ("char *0" 为第一级菜单)
  ┌──────┐
  ╎MENU1 ╎▶char *M1 (点击"MENU1"进入1菜单)
  ╎MENU2 ╎ ┌────────┐
  ╎MENU3 ╎ ╎MENU1-1 ╎▶char *M11 (点击"MENU1-1"进入11菜单)
  ╎MENU4 ╎ ╎MENU1-2 ╎ ┌──────────┐
  ╎MENU5 ╎ ╎MENU1-3 ╎ ╎MENU1-1-1 ╎▶"void M111();" (如果没有下一集菜单，则进入同名程序)
  ╎MENU6 ╎ └────────┘ ╎MENU1-1-2 ╎▶"void M112();"
  ╎MENU7 ╎▶char *M7   ╎MENU1-1-3 ╎▶"void M113();"
  └──────┘ ┌────────┐ └──────────┘
           ╎MENU7-1 ╎
           ╎MENU7-2 ╎
           ╎MENU7-3 ╎
           └────────┘
  --------------------------------------------------------------------------------
  char *0[7] ={"MENU1", "MENU2", "MENU3", "MENU4","MENU5"};
   ▲      ▲      ▲
  菜单级数 列表数量 菜单内容
  ================================================================================
*/

char *M0[7] = {"MENU1", "MENU2", "MENU3", "MENU4", "MENU5", "MENU6", "MENU7"};
char *M1[3] = {"MENU1-1", "MENU1-2", "MENU1-3"};
char *M11[3] = {"MENU1-1-1", "MENU1-1-2", "MENU1-1-3"};
char *M7[4] = {"MENU7-1", "MENU7-2", "MENU7-3"};


//===========================================================================
//============================= Menu Program ================================
//===========================================================================
String M[] = "M0";        //初始菜单
int menudata[10] = {0};   //路径历史
int menuv = 0;            //选框位置
int menua = 0;            //第一行显示
int menub = 1;            //第二行显示
int menuc = 2;            //第三行显示
int menud = 3;            //第四行显示
int menum = 0;            //选框位置
int menus = 0;            //选定菜单

void menudisplay() {
  M[2] = menuv;
  u8g2.clearBuffer();
  u8g2.setFontMode(1);
  u8g2.setDrawColor(1);
  u8g2.drawBox(0, menum * 16, 128, 16);   //选框位置
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setDrawColor(2);
  u8g2.setCursor(2, 14);                  //第一行菜单
  u8g2.print(M[menua]);
  u8g2.setCursor(2, 30);                  //第二行菜单
  u8g2.print(M[menub]);
  u8g2.setCursor(2, 46);                  //第三行菜单
  u8g2.print(M[menuc]);
  u8g2.setCursor(2, 62);                  //第四行菜单
  u8g2.print(M[menud]);
  u8g2.sendBuffer();

  Serial.print("menuv:");
  Serial.print(menuv);
  Serial.print(" menucount:");
  Serial.println(menus);

}

void menu() {
  digitalWrite(B02, HIGH);
  digitalWrite(B04, HIGH);
  digitalWrite(B06, HIGH);
  digitalWrite(B08, LOW);

  if (digitalRead(B01) == LOW) {  //按下"返回"
    if (menuv > 10) {             //不在一级菜单
      menuv = (menuv - 5) / 10;
      menudisplay();
    }
  }
  if (digitalRead(B03) == LOW) {  //按下"上"
    if (menum > 0) {
      menum--;
      menus--;
      menudisplay();
    } else if (menua > 0) {
      menus--;
      menua--;
      menub--;
      menuc--;
      menud--;
      menudisplay();
    }
  }
  if (digitalRead(B05) == LOW) {  //按下"下"
    if (M[menus + 1] != 0) {      //确定未显示完
      if (menum = 3 ) {              //选框在最下
        menus++;
        menua++;
        menub++;
        menuc++;
        menud++;
        menudisplay();
      } else if (menum < 3) {       //选框不在最下

      }
    }
    if (digitalRead(B07) == LOW) {  //按下"确认"
      M[2] = menuv * 10 + menus;
      if ((M)[] != 0) {      //进入下一级
        menuv = menuv * 10 + menus;
      } else {              //
        M[2] = menuv;
        
      }
    }
  }
}
