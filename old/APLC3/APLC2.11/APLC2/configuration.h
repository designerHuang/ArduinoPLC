/*删除    ↓↓    即为选择设备，仅能选择一台设备烧录*/
/*衣领*/    #define YILING
/*圆领*/  //#define YUANLING
/*下摆*/  //#define XIABAI
/*门襟*/  //#define MENJIN

/*曲线运动*/

/*运动速度*/
int SHOME = -2000;  //复位速度
int SMOVE = 3000;   //移动速度

/*模板数据*/
char *templatedata[5][6]={
  /*      侧加热时间  前加热时间 最大加热温度 料A厚度 料B厚度*/ 
  /*模板1*/{"2000"  , "2000"  , "200" , "100" , "100"},
  /*模板2*/{"2000"  , "2000"  , "200" , "100" , "100"},
  /*模板3*/{"2000"  , "2000"  , "200" , "100" , "100"},};
