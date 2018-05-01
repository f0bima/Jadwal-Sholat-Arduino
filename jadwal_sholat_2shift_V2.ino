#include <DS1307.h>
// Init the DS1307
DS1307  rtc(SDA, SCL);
// Init a Time-data structure
int tgp,tgs,bp,bs,thp,ths,thrb,thrt,jp,js,mp,ms,dp,ds,hr,hari;
/*int latchPin = 8;//ST_CP
int clockPin = 12;//SH_CP 
int dataPin = 11; //DS */
int latchPin = 4;//ST_CP
int clockPin = 6;//SH_CP 
int dataPin = 5; //DS 
int ShowDec [15];
// define latch, clock and datapin
Time waktu;
double jd,t,delta,et;
double shubuh, terbit, zhuhur,ashar, maghrib, isya;
int zona,KA,z,ws;
double B,altitude, lintang, ketinggian,ha,sudut_subuh,sudut_isya;
String j_shubuh, j_terbit, j_zhuhur, j_ashar, j_maghrib, j_isya;
int sjp[10];
int sjs[10];
int smp[10];
int sms[10];
void setup ()
{

  // Initialize the rtc object
  rtc.begin();

  // Set the clock to run-mode
  rtc.halt(false);
  
  // The following lines can be uncommented to set the time
  //rtc.setDOW(MINGGU);        // Set Day-of-Week to SUNDAY
  //rtc.setTime(07, 33, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(16, 7, 2017);   // Set the date to October 3th, 2010
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT); 
//set these three pins to output
KA=1;
  zona=7; //GMT
  lintang =-(7+(42/60));
  ketinggian=113;
  B=110+(36/60);
  sudut_isya=-18;
  sudut_subuh=-20;
}
 
//Display function (display word, display position, display if have 
//decimal point) 
void disNum(int Num_Qua, int Num_Pos, int Num_Dec)
{
int Num_Qua_B = 0;
int Num_Pos_B = 0;
int Num_Pos_C = 0;
int Num_Pos_D = 0;
int Num_Pos_E = 0;
int Num_Pos_F = 0;
switch (Num_Qua)
{
case 0:Num_Qua_B = 192;break;
case 1:Num_Qua_B = 249;break;
case 2:Num_Qua_B = 164;break;
case 3:Num_Qua_B = 176;break;
case 4:Num_Qua_B = 153;break;
case 5:Num_Qua_B = 146;break;
case 6:Num_Qua_B = 130;break;
case 7:Num_Qua_B = 248;break;
case 8:Num_Qua_B = 128;break;
case 9:Num_Qua_B = 144;break;
case 11:Num_Qua_B = 254;break;
case 12:Num_Qua_B = 253;break;
case 13:Num_Qua_B = 251;break;
case 14:Num_Qua_B = 247;break;
case 15:Num_Qua_B = 239;break;
case 16:Num_Qua_B = 223;break;
case 17:Num_Qua_B = 191;break;
default: Num_Qua_B = 255;break;
};
//this value convert to binary, which is adcdefg need to light up
switch (Num_Pos)
{
case 1:Num_Pos_B = 1;break;
case 2:Num_Pos_B = 2;break;
case 3:Num_Pos_B = 4;break;
case 4:Num_Pos_B = 8;break;
case 5:Num_Pos_B = 16;break;
case 6:Num_Pos_B = 32;break;
case 7:Num_Pos_B = 64;break;
case 8:Num_Pos_B = 128;break;
case 9:Num_Pos_C = 1;break;
case 10:Num_Pos_C = 2;break;
case 11:Num_Pos_C = 4;break;
case 12:Num_Pos_C = 8;break;
case 13:Num_Pos_C = 16;break;
case 14:Num_Pos_C = 32;break;
case 15:Num_Pos_C = 64;break;
case 16:Num_Pos_C = 128;break;
case 17:Num_Pos_D = 1;break;
case 18:Num_Pos_D = 2;break;
case 19:Num_Pos_D = 4;break;
case 20:Num_Pos_D = 8;break;
case 21:Num_Pos_D = 16;break;
case 22:Num_Pos_D = 32;break;
case 23:Num_Pos_D = 64;break;
case 24:Num_Pos_D = 128;break;
case 25:Num_Pos_E = 1;break;
case 26:Num_Pos_E = 2;break;
case 27:Num_Pos_E = 4;break;
case 28:Num_Pos_E = 8;break;
case 29:Num_Pos_E = 16;break;
case 30:Num_Pos_E = 32;break;
case 31:Num_Pos_E = 64;break;
case 32:Num_Pos_E = 128;break;
case 33:Num_Pos_F = 1;break;
case 34:Num_Pos_F = 2;break;
case 35:Num_Pos_F = 4;break;
case 36:Num_Pos_F = 8;break;
case 37:Num_Pos_F = 16;break;
case 38:Num_Pos_F = 32;break;
default: Num_Pos_B = 0;break;
};
//this value convert to binary, which is the one light up now.
/*if (Num_Dec == 1)
{
Num_Qua_B = Num_Qua_B + 128;
};*/
//========================================
digitalWrite(latchPin,LOW); 
// set latch to low tolet the display ready to receive data
int L = Num_Qua_B; int R = Num_Pos_B; int C =Num_Pos_C; int D =Num_Pos_D; int E =Num_Pos_E; int F =Num_Pos_F; 
shiftOut(dataPin,clockPin,MSBFIRST,F);
shiftOut(dataPin,clockPin,MSBFIRST,E);
shiftOut(dataPin,clockPin,MSBFIRST,D);
shiftOut(dataPin,clockPin,MSBFIRST,C);
shiftOut(dataPin,clockPin,MSBFIRST,R);
shiftOut(dataPin,clockPin,MSBFIRST,L);
/*shiftOut(dataPin,clockPin,MSBFIRST,L);
shiftOut(dataPin,clockPin,MSBFIRST,R);
shiftOut(dataPin,clockPin,MSBFIRST,C);
shiftOut(dataPin,clockPin,MSBFIRST,D);
shiftOut(dataPin,clockPin,MSBFIRST,E);
shiftOut(dataPin,clockPin,MSBFIRST,F);*/
digitalWrite(latchPin,HIGH); //restore to high TTL back
//========================================
delayMicroseconds(100);
}
 
void loop()
{
// Get data from the DS1307
  waktu = rtc.getTime();
  tgp = waktu.date / 10;
  tgs = waktu.date % 10;
  bp  = (waktu.mon) / 10;
  bs  = (waktu.mon) % 10;
  thrb = waktu.year / 1000;
  thrt = ((waktu.year % 1000) / 100);
  thp = ((waktu.year % 100) / 10);
  ths = waktu.year % 10;
  jp  = waktu.hour / 10;
  js  = waktu.hour %10;
  mp  = waktu.min / 10;
  ms  = waktu.min % 10;
  dp  = waktu.sec / 10;
  ds  = waktu.sec % 10;
  hari  = waktu.dow;
  jadwal_sholat(waktu.year,waktu.mon,waktu.date);
  switch (hari)
  {
    case 1:hr=17;break;
    case 2:hr=12;break;
    case 3:hr=13;break;
    case 4:hr=14;break;
    case 5:hr=15;break;
    case 6:hr=16;break;
    case 7:hr=11;break;
  }
disNum(jp,1,ShowDec[1]);
disNum(js,2,ShowDec[2]);
disNum(mp,3,ShowDec[3]);
disNum(ms,4,ShowDec[4]);
disNum(dp,5,ShowDec[5]);
disNum(ds,6,ShowDec[6]);
disNum(tgp,7,ShowDec[7]);
disNum(tgs,8,ShowDec[8]);
disNum(bp,9,ShowDec[9]);
disNum(bs,10,ShowDec[10]);
disNum(thrb,11,ShowDec[11]);
disNum(thrt,12,ShowDec[12]);
disNum(thp,13,ShowDec[13]);
disNum(ths,14,ShowDec[14]);
ws=1;
z=15;
while (z<39) {
     disNum(sjp[ws],z,ShowDec[z]);  z++;
     disNum(sjs[ws],z,ShowDec[z]);  z++;
     disNum(smp[ws],z,ShowDec[z]);  z++;
     disNum(sms[ws],z,ShowDec[z]);  z++;
     ws++;
}
/*ws=6;
z=15;
while (z<39) {
  disNum(sms[ws],z,ShowDec[z]);  z++;
  disNum(smp[ws],z,ShowDec[z]);  z++;
  disNum(sjs[ws],z,ShowDec[z]);  z++;
  disNum(sjp[ws],z,ShowDec[z]);  z++;      
     ws--;
}
disNum(ths,14,ShowDec[14]);
disNum(thp,13,ShowDec[13]);
disNum(thrt,12,ShowDec[12]);
disNum(thrb,11,ShowDec[11]);
disNum(bs,10,ShowDec[10]);
disNum(bp,9,ShowDec[9]);
disNum(tgs,8,ShowDec[8]);
disNum(tgp,7,ShowDec[7]);
disNum(ds,6,ShowDec[6]);
disNum(dp,5,ShowDec[5]);
disNum(ms,4,ShowDec[4]);
disNum(mp,3,ShowDec[3]);
disNum(js,2,ShowDec[2]);
disNum(jp,1,ShowDec[1]);*/
}
