/**
 * @file car_basics.ino
 * @author copyrights
 * @brief Basic car functionality.
 * @ingroup car
 * @todo Write a function for brake lights.
 */
 
 /**
  * @ingroup car
  * @{
  */
#include "car_basics.h"
#include "speed.h"
#ifndef CUSTOM
const byte turn_light_left[]={17,27};
const byte low_beam_row[] ={1,2,16,15};
const byte high_beam_row[] = {1,2,16,15};
const byte front_row[] = {3,4,5,13,14};
const byte tacho_row[] = {12,11,10,9,8,7,6};
const byte turn_light_right[]={0,30};
const byte down_left_row[] = {18,19,20,21};
const byte down_right_row[] = {22,23,24,25};
const byte back_light_row[] = {26,28,29,31};
#endif
/** @brief Activate right turn lights */
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

/** @brief Activate left turn lights */
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

/** 
 * @brief Activate low beam or high beam.
 * @todo Rewrite as all LEDs get clear at the beginning of the main loop */
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

/**
 * @brief Display the current speed on tacho_row LEDs.
 * 
 * It is show from left to right in three different color.
 * 
 * - Green (0x001100): low speed
 * - Orange (0x110800): medium speed
 * - Red (0x110000): ludicrous speed
 * 
 * The function @ref getspeed() returns an unsigned integer with a step size of
 * 1 equals 0.4302 km/h. As the speed is displayed in three color the
 * maximum speed should be dividable by three. 
 * 
 * The integer value 30 -> 12.9 km/h. 12.9 km/h should be enough for 
 * small children. If you have a older child or use this for different 
 * purposes (e.g. a bicycle), the maximum speed should be higher.
 * 
 * 30/3 = 10 -> speed * count of tachometer LEDs / 10
 * @see getspeed()
 */
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

/**
 * @brief Flash light.
 * 
 * Put @ref high_beam_row, @ref front_row and @ref back_light_row to @ref HIGHBEAM.
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

/**
 * @brief Brake light.
 * 
 * Put @ref back_light_row to @ref BRAKELIGHT.
 */
void brakelight()
{
  for(byte i=0;i<sizeof(back_light_row);i++){
    strip.setPixelColor(back_light_row[i],BRAKELIGHT);
  }
}

/**@}*/
