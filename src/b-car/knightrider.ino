void knightrider(){
  byte lc = sizeof(front_row);
  uint16_t period = 500;
  float fac;

  if((time%(period*2)) < period){
    for(byte i=0;i<lc;i++){
      fac = max(0.0,pow(sin(PI/2.0-PI/2.0*((time%period)*1.0/period - i/(lc-1.0))),16));
      strip.setPixelColor(front_row[i],(byte)(KRR*fac),(byte)(KRG*fac),(byte)(KRB*fac));
    }
  }else{
    for(byte i=0;i<lc;i++){  
      fac = max(0.0,pow(sin(PI/2.0-PI/2.0*(((time-period)%period)*1.0/period - (1-(i/(lc-1.0))))),16));
      strip.setPixelColor(front_row[i],(byte)(KRR*fac),(byte)(KRG*fac),(byte)(KRB*fac));
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
