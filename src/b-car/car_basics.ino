void turn_right(bool on){
  unsigned long t;
  t = time & 1000;
  if(on && t>500){
    for(byte i=0;i<sizeof(turn_light_right);i++){
      strip.setPixelColor(turn_light_right[i],TURNLIGHT);
    }
  }else{
    for(byte i=0;i<sizeof(turn_light_right);i++){
      strip.setPixelColor(turn_light_right[i],0x000);
    }
  }
  modified = on;
}

void turn_left(bool on){
  unsigned long t;
  t = time & 1000;
  if(on && t>500){
    for(byte i=0;i<sizeof(turn_light_left);i++){
      strip.setPixelColor(turn_light_left[i],TURNLIGHT);
    }
  }else{
    for(byte i=0;i<sizeof(turn_light_left);i++){
      strip.setPixelColor(turn_light_left[i],0x000);
    }
  }
  modified = on;
}
void beam(unsigned long state){
  if(state == HIGHBEAM){
    high_beam(true);
  }
  else if(state == LOWBEAM)
  {
    low_beam(true);
  }
  else
  {
    low_beam(false);
    high_beam(false);
  }
}
void low_beam(bool on){
  if (on){
    for(byte i=0;i<sizeof(low_beam_row);i++){
      strip.setPixelColor(low_beam_row[i],LOWBEAM);
    }
    for(byte i=0;i<sizeof(back_light_row);i++){
      strip.setPixelColor(back_light_row[i],BACKLIGHT);
    }
  }else{
    for(byte i=0;i<sizeof(low_beam_row);i++){
      strip.setPixelColor(low_beam_row[i],0x0);
    }
    for(byte i=0;i<sizeof(back_light_row);i++){
      strip.setPixelColor(back_light_row[i],0x0);
    }
  }
  modified=true;
}

void high_beam(bool on){
  if (on){
    for(byte i=0;i<sizeof(high_beam_row);i++){
      strip.setPixelColor(high_beam_row[i],HIGHBEAM);
    }
    for(byte i=0;i<sizeof(back_light_row);i++){
      strip.setPixelColor(back_light_row[i],BACKLIGHT);
    }
  }else{
    for(byte i=0;i<sizeof(high_beam_row);i++){
      strip.setPixelColor(high_beam_row[i],0x0);
    }
    for(byte i=0;i<sizeof(back_light_row);i++){
      strip.setPixelColor(back_light_row[i],0x0);
    }
  }
  modified=true;
}
void tacho()
{
  byte pit = ((time % (sizeof(tacho_row)*600))/200);
  uint32_t color;
  if (pit<=sizeof(tacho_row))
  {
     color=0x001100;
     for( byte i = 0;i<sizeof(tacho_row);i++) strip.setPixelColor(tacho_row[i], 0);
  }
  else if (pit<=(sizeof(tacho_row)*2))
  {
    color=0x110800;
    pit = pit - sizeof(tacho_row);
  }
  else //if (pit<=(sizeof(tacho_row)*3))
  {
    color=0x110000;
    pit = pit - 2*sizeof(tacho_row);
  /*}else{
    color=0x000000;
    pit = pit - 3*sizeof(tacho_row);
  */}
  
  for( byte i = 0;i<sizeof(tacho_row);i++){
      if( i<pit){
        strip.setPixelColor(tacho_row[i], Wheel());
        //strip.show();
      }/*else{
        strip.setPixelColor(tacho_row[i], 0);
      }*/
    }
}
/*
void tacho()
{
  
  unsigned int leds = getspeedidx();//(cur_speed*sizeof(tacho_row))/400;
  unsigned int cur_speed = getspeed();
  byte color = 0;
  uint32_t c;
  //cur_speed = (cur_speed >>1);
  *//*
  if (cur_speed < 5000)
  {
    c = 0x002222;
  }
  else if (cur_speed < 10000)
  {
    c = 0x005500;
  }
  else if (cur_speed < 15000)
  {
    c = 0x000055;
  }
  else
  {
    c = 0x550000;
  }
  *//*
  for( byte i = 0;i<sizeof(tacho_row);i++) strip.setPixelColor(tacho_row[i], 0);
  
  while (leds > 0)
  {
    if(leds<=sizeof(tacho_row))
    {
      for( byte i = 0;i<sizeof(tacho_row);i++){
        if( i<leds){
          strip.setPixelColor(tacho_row[i], Wheel(color));
          //strip.show();
        }else{
          strip.setPixelColor(tacho_row[i], 0);
        }
      }
    }
    leds = max(0,leds-sizeof(tacho_row));
    color = (color+1)%0xff;
  }
  
  *//*
  uint16_t slot = time % 4000;
  uint16_t pos = time % 1000;
  uint32_t color;
  if ((slot / 1000) == 0)
    color=0x007f00;
  else if ((slot / 1000) == 1)
    color=0x646400;
  else if ((slot / 1000) == 2)
    color=0x7f0000;
  else
    color=0x0;
  pos = ((sizeof(tacho_row)+1)*pos)/1000;
  if(color==0)
    pos=sizeof(tacho_row);
  for (byte i=0;i<pos;i++){
     strip.setPixelColor(tacho_row[i],color);
  }
  modified=true;
  *//*
}
*/

void flash(){
  for(byte i=0;i<sizeof(high_beam_row);i++)
  {
    strip.setPixelColor(high_beam_row[i],HIGHBEAM);
  }
  for(byte i=0;i<sizeof(front_row);i++)
  {
    strip.setPixelColor(front_row[i],HIGHBEAM);
  }
  for(byte i=0;i<sizeof(back_light_row);i++)
  {
    strip.setPixelColor(back_light_row[i],HIGHBEAM);
  }
}


