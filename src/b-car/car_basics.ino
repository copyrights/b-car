void turn_right(bool on){
  unsigned long t;
  t = time & 1000;
  if(on && t>500){
    for(byte i=0;i<sizeof(turn_light_frontright);i++){
      strip.setPixelColor(turn_light_frontright[i],TURNLIGHT);
    }
  }else{
    for(byte i=0;i<sizeof(turn_light_frontright);i++){
      strip.setPixelColor(turn_light_frontright[i],0x000);
    }
  }
  modified = on;
}

void turn_left(bool on){
  unsigned long t;
  t = time & 1000;
  if(on && t>500){
    for(byte i=0;i<sizeof(turn_light_frontleft);i++){
      strip.setPixelColor(turn_light_frontleft[i],TURNLIGHT);
    }
  }else{
    for(byte i=0;i<sizeof(turn_light_frontleft);i++){
      strip.setPixelColor(turn_light_frontleft[i],0x000);
    }
  }
  modified = on;
}

void low_beam(bool on){
  if (on){
    for(byte i=0;i<sizeof(low_beam_right);i++){
      strip.setPixelColor(low_beam_right[i],LOWBEAM);
    }
    for(byte i=0;i<sizeof(low_beam_left);i++){
      strip.setPixelColor(low_beam_left[i],LOWBEAM);
    }
  }else{
    for(byte i=0;i<sizeof(low_beam_right);i++){
      strip.setPixelColor(low_beam_right[i],0x0);
    }
    for(byte i=0;i<sizeof(low_beam_left);i++){
      strip.setPixelColor(low_beam_left[i],0x0);
    }
  }
  modified=true;
}

void high_beam(bool on){
  if (on){
    for(byte i=0;i<sizeof(high_beam_right);i++){
      strip.setPixelColor(high_beam_right[i],HIGHBEAM);
    }
    for(byte i=0;i<sizeof(high_beam_left);i++){
      strip.setPixelColor(high_beam_left[i],HIGHBEAM);
    }
  }else{
    for(byte i=0;i<sizeof(high_beam_right);i++){
      strip.setPixelColor(high_beam_right[i],0x0);
    }
    for(byte i=0;i<sizeof(high_beam_left);i++){
      strip.setPixelColor(high_beam_left[i],0x0);
    }
  }
  modified=true;
}


