#define KRR 0x7f
#define KRG 0x00
#define KRB 0x00
#define KRPERIOD 500
#define KRDTZ 200

void knightrider(){
  uint16_t lc = sizeof(front_row);
  uint16_t s = KRPERIOD / lc;
  uint16_t pit,distance,pos;
  uint8_t f;
  pit = time % KRPERIOD;
  
  if((time % (KRPERIOD * 2)) < KRPERIOD){
    
    for(uint16_t i=0;i<lc;i++){
      pos = i * s;
      if (pos>pit)
      {
        distance = pos - pit;
      }
      else
      {
        distance = pit - pos;
      }  
      f = fade8(distance, KRDTZ);
      strip.setPixelColor(front_row[i], percent8(KRR,f), percent8(KRG,f), percent8(KRB,f));
    }
  }else{
    for(uint16_t i=0;i<lc;i++){  
      pos = (lc-1-i)*s;
      if (pos>pit)
      {
        distance = pos - pit;
      }
      else
      {
        distance = pit - pos;
      }  
      f = fade8(distance, KRDTZ);
      strip.setPixelColor(front_row[i], percent8(KRR,f), percent8(KRG,f), percent8(KRB,f));
      //strip.setPixelColor(front_row[i], fallingcos8(((time-KRPERIOD)%KRPERIOD)/(lc-1+i)),0,0);
      //fac = max(0.0,pow(sin(PI/2.0-PI/2.0*(((time-KRPERIOD)%KRPERIOD)*1.0/KRPERIOD - (1-(i/(lc-1.0))))),16));
      //strip.setPixelColor(front_row[i],(byte)(KRR*fac),(byte)(KRG*fac),(byte)(KRB*fac));
    } 
  }
  
  modified = true;
}

void noknightrider(){
  byte lc = sizeof(front_row);
  for(byte i=0;i<lc;i++){
    strip.setPixelColor(front_row[i],0x0);
  }
  modified = true;
}


