int RunTemplate = 0;    //正在运行的模板
int RunNow;             //运行到步骤
int SI;                 //百分比进度
int Completed = 0;      //烫压放置计数
int FirstRun = 0;       //判断首次启动
int ACOFF = 0;          //完成后关机
int MJ = 0;             //是否有料，0=没有
int SETQ = 0;           //设置数量
int COMPL = 0;          //完成的数量
unsigned long MCAPA = 0;//料仓A容量
unsigned long MCAPB = 0;//料仓B容量
unsigned long TIME;     //临时计时器30sMax
float TEMP1;            //温度1
float TEMP2;            //温度1
int SETPWM;             //激光功率
int SETTEMP;            //设定温度
int HOMEDATA = 0;       //是否复位 

/*模板数据*/
int HTA;    //侧加热时间
int HTB;    //前加热时间
int HTEMP;    //最大加热温度
int MTHKA;  //材料1厚度
int MTHKB;  //材料2厚度

/*Encoder*/
int ECP = 0;  //计数器

/*坐标*/
long positions[2];
long A;
long B;
long C;
long D;
long E;
long F;
