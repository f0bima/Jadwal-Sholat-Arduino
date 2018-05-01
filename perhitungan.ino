void JD(int y, int m, int d){
  if (m<3) {
    m=m+12;
    y=y-1;
  }
  float a= round(y/100);
  float b = 2+round(round(a/4))-a;
  float th  = round(365.25*y);  
  float bl = round(30.6001*(m + 1));
  /*float a= (y/100);
  float b = 2+((a/4))-a;
  float th  = (365.25*y);  
  float bl = (30.6001*(m + 1)); */
  jd = (1720994.5 + th + bl + b + d)-(7/24);         
}    
void T(){        
  t = 2*3.14159265359*(jd-2451545)/365.25;                
}
void Delta(){        
  delta = 0.37877 + 23.264*sin(toRadian(57.297*t-79.547)) + 0.3812*sin(toRadian(2*57.297*t-82.682)) + 0.17132*sin(toRadian(3*57.297*t-59.722));        
}
void ET(){
  double U = (jd-2451545)/36525;
  double L0 = fmod((280.46607 + 36000.7698*U), 360);
  et = (-(1789 + 237*U)*sin(toRadian(L0))-(7146-62*U)*cos(toRadian(L0)) + (9934-14*U)*sin(toRadian(2*L0))-(29 + 5*U)*cos(toRadian(2*L0)) + (74 + 10*U)*sin(toRadian(3*L0)) + (320-4*U)*cos(toRadian(3*L0)) - 212*sin(toRadian(4*L0)))/1000;
}

double HA(double altitude){        
  double cosHA = (sin(toRadian(altitude)) - sin(toRadian(lintang))*sin(toRadian(delta))) / (cos(toRadian(lintang))*cos(toRadian(delta)));
  //ha = Math.toDegrees(Math.acos(cosHA));
  ha = toDegre((acos(cosHA)));
  return ha;        
}
String hasil(double input,int i){  
  long detik = round(3600*input);
  //long detik = (3600*input);
  long jam = round(detik/3600);
  long menit = round(((detik%3600)/60));
  sjp[i]= jam/10;
  sjs[i]= jam % 10;
  smp[i]= menit/10;
  sms[i]= menit % 10;
  //long menit = (((detik%3600)/60));  
  return String(jam)+":"+String(menit);
}
void jadwal(){
  //Serial.print(z+"  ");
  /*Serial.print("SHUBUH  : "+j_shubuh+"   ");
  Serial.print("TERBIT  : "+j_terbit+"   ");
  Serial.print("ZHUHUR  : "+j_zhuhur+"   ");
  Serial.print("ASHAR   : "+j_ashar+"   ");
  Serial.print("MAGHRIB : "+j_maghrib+"   ");
  Serial.println("ISYA    : "+j_isya);         */
  Serial.print(j_shubuh+"   ");
  Serial.print(j_terbit+"   ");
  Serial.print(j_zhuhur+"   ");
  Serial.print(j_ashar+"   ");
  Serial.print(j_maghrib+"   ");
  Serial.println(j_isya);         
}
void jadwal_sholat(int yyyy, int mm, int dd){
  Serial.print(dd);
  Serial.print("  ");
  JD(yyyy,mm,dd);
  T();
  Delta();
  ET();        
  Zhuhur(zona, B);
  Maghrib();                
  Isya();
  Shubuh();
  Ashar();
  jadwal();
}

double toRadian(double x){
  return x*(3.142857142857143/180);
}
double toDegre(double x){
  return (x*180)/3.142857142857143;
}
