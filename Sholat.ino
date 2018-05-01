void Zhuhur(int Z,double B){        
  zhuhur = 12 + Z - B/15 - et/60;                 
  j_zhuhur = hasil(zhuhur,3);
}            
void Ashar(){                
  altitude = toDegre(atan(1/(KA + tan(toRadian(abs(delta - lintang))))));
  ashar = zhuhur + (HA(altitude))/15;        
  j_ashar = hasil(ashar,4);  
}
void Maghrib(){
  altitude= -0.8333 - 0.0347*sqrt(ketinggian);
  maghrib = zhuhur + (HA(altitude))/15;
  terbit = zhuhur - (HA(altitude))/15;        
  j_maghrib = hasil(maghrib,5);
  j_terbit = hasil(terbit,2);
}
void Isya(){
  altitude= sudut_isya;
  isya = zhuhur + (HA(altitude))/15;        
  j_isya = hasil(isya,6);
}
void Shubuh(){        
  altitude= sudut_subuh;
  shubuh = zhuhur - (HA(altitude))/15;        
  j_shubuh = hasil(shubuh,1);
}
