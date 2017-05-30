void turn_right(){
  unsigned long t;
  t = time & 1000;
  if(t>500){
    for(byte i=0;i<sizeof(turn_light_right);i++){
      strip.setPixelColor(turn_light_right[i],TURNLIGHT);
    }
  }else{
    for(byte i=0;i<sizeof(turn_light_right);i++){
      strip.setPixelColor(turn_light_right[i],0x000);
    }
  }
}

void turn_left(){
  unsigned long t;
  t = time & 1000;
  if(t>500){
    for(byte i=0;i<sizeof(turn_light_left);i++){
      strip.setPixelColor(turn_light_left[i],TURNLIGHT);
    }
  }else{
    for(byte i=0;i<sizeof(turn_light_left);i++){
      strip.setPixelColor(turn_light_left[i],0x000);
    }
  }
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
}
void tacho()
{
  unsigned int v = getspeed()*sizeof(tacho_row)/10;
  uint32_t color;
  if (v<=sizeof(tacho_row))
  {
    for( byte i = 0;i<sizeof(tacho_row);i++) strip.setPixelColor(tacho_row[i], 0);
    color=0x001100; 
  }
  else if (v<=(sizeof(tacho_row)*2))
  {
    for( byte i = 0;i<sizeof(tacho_row);i++) strip.setPixelColor(tacho_row[i], 0x001100);
    color=0x110800;
    v = v - sizeof(tacho_row);
  }
  else
  {
    for( byte i = 0;i<sizeof(tacho_row);i++) strip.setPixelColor(tacho_row[i], 0x110800);
    color=0x110000;
    v = v - 2*sizeof(tacho_row);
  }
  
  for( byte i = 0;i<sizeof(tacho_row);i++){
      if( i<v){
        strip.setPixelColor(tacho_row[i], color);

      }
    }
}

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


