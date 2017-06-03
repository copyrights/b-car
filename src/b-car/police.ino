/**
 * @file police.ino 
 * @author copyrights
 * @brief Police beacon light and front flash.
 * @ingroup police
 * @todo May add more flasher.
 * @todo Extract beacon light as seperate function.
 */
 
/**
 * @ingroup police
 * @{
 */
 

void police(){
  byte so;
  uint8_t f;
  so=sizeof(down_left_row)-1;
  
  uint16_t lc = sizeof(down_left_row) + sizeof(down_right_row);
  uint16_t s = PPERIOD / lc;
  
  uint16_t pit,distance,pos;
  pit = time % PPERIOD;
  
  for (byte i=0;i<sizeof(down_left_row);i++)
  {
    pos = i * s;
    if (pos>pit)
    {
      distance = pos - pit;
    }
    else
    {
      distance = pit - pos;
    }
    if (distance > ((lc/2)*s))
      distance = ((lc/2)*s)-(distance-s*(lc/2)); 
    f = fade8(distance, PDTZ);
    strip.setPixelColor(down_left_row[i], percent8(PR,f), percent8(PG,f), percent8(PB,f));
  }
  so=sizeof(down_right_row)-1;
  for (byte i=0;i<sizeof(down_right_row);i++)
  {
   pos = (i+sizeof(down_left_row)) * s;
    if (pos>pit)
    {
      distance = pos - pit;
    }
    else
    {
      distance = pit - pos;
    }  
    f = fade8(distance, PDTZ);
    strip.setPixelColor(down_right_row[so-i], percent8(PR,f), percent8(PG,f), percent8(PB,f));
  }
  
  if(pit<PPERIOD/8)
  {
     p_front(true,false,true);
  }else if (pit<(PPERIOD/8)*2){
    p_front(false,false,true);
  }else if (pit<(PPERIOD/8)*3){
    p_front(true,false,true);
  }else if (pit<(PPERIOD/8)*4){
    p_front(false,false,true);
  }else if (pit<(PPERIOD/8)*5){
    p_front(false,true,false);
  }else if (pit<(PPERIOD/8)*6){
    p_front(false,false,false);
  }else if (pit<(PPERIOD/8)*7){
    p_front(false,true,false);
  }else{
    p_front(false,false,false);
  }
}

void p_front(boolean ls, boolean rs, boolean left)
{
  uint8_t so = sizeof(front_row);
  uint8_t lso,rso,i;
  if(ls){
    rso = so/2;
    lso = so -rso;
    for (i=0;i<lso;i++)
      strip.setPixelColor(front_row[i],PLFLASH); 
    for (i=lso;i<so;i++)
      strip.setPixelColor(front_row[i],PRLOW); 
  }else if(rs){
    lso = so/2;
    rso = so -lso;
    for (i=0;i<lso;i++)
      strip.setPixelColor(front_row[i],PLLOW);
    for (i=lso;i<so;i++)
      strip.setPixelColor(front_row[i],PRFLASH); 
  }else if(left){
    rso = so/2;
    lso = so -rso;
    for (i=0;i<lso;i++)
      strip.setPixelColor(front_row[i],PLLOW); 
    for (i=lso;i<so;i++)
      strip.setPixelColor(front_row[i],PRLOW); 
  }else{
    lso = so/2;
    rso = so -lso;
    for (i=0;i<lso;i++)
      strip.setPixelColor(front_row[i],PLLOW); 
    for (i=lso;i<so;i++)
      strip.setPixelColor(front_row[i],PRLOW);
  }
}

/**@}*/
