#include <Adafruit_NeoPixel.h>
#include "config.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif



static volatile unsigned long time;
bool modified;
byte mode=0;
bool tooglebutton = false;
uint16_t pressed;



Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  pinMode(BUTTONS1, INPUT);
  pinMode(BUTTONS2, INPUT);
  strip.begin();
  strip.show();
  //low_beam(true);
  setup_interrupt();
}

void loop() {
  pressed =  pressedButtons();
  modified=false;
  
  time = millis();
  if(mode == 0){
    normalmode();
  }
  else if (mode == 1)
  {
    rainbowmode();
  }                                                     
  //Button1
  if((pressed & 1) == 0){
    tooglebutton = false;
  }else if(!tooglebutton){
    tooglebutton = true;
    mode=(mode+1)%2;
  }
  if(modified) strip.show();
}


void normalmode(){
  unsigned long beamstate=0;

  

  
  //Button5
  if((pressed & (1<<4)) > 0){
    beamstate=LOWBEAM;  
  }
  //Button4
  if((pressed & (1<<3)) > 0){
    beamstate=HIGHBEAM;
  }
  
  beam(beamstate);
  
  //Button2
  if((pressed & (1<<1)) > 0){
    turn_right(true);
  }else{
    turn_right(false);
  }
  
  //Button3
  if((pressed & (1<<2)) > 0){
    turn_left(true);
  }else{
    turn_left(false);
  }
  //Button6
  if((pressed & (1<<5)) == 0)//rot
    knightrider();
  //Button7
  if((pressed & (1<<6)) == 0)//white
    tacho();
  //Button8
  if((pressed & (1<<7)) == 0)//black
    underbody_rb();
  //Button 9 kill
  if ((pressed & (1<<8)) > 0)
    police();
  //Button 10 horn
  if ((pressed & (1<<9)) > 0)
    flash();
}
