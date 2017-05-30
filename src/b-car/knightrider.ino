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
}


