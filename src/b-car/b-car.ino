#include <Adafruit_NeoPixel.h>
#include "config.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif



static volatile unsigned long time;
bool modified;
byte mode=0;
uint16_t buttonstore = S6|S7|S8;
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
  if (getRising(S1)>0)
    mode=(mode+1)%2;
  if(modified) strip.show();
}


void normalmode(){
  unsigned long beamstate=0;
  
  buttonstore ^= getRising(S6|S7|S8);
  

  //Button5
  if((pressed & S5) > 0){
    beamstate=LOWBEAM;  
  }
  //Button4
  if((pressed & S4) > 0){
    beamstate=HIGHBEAM;
  }
  
  beam(beamstate);
  
  //Button2
  turn_right((pressed & S2) > 0);
    
  //Button3
  turn_left((pressed & S3) > 0);
  
  //Button6 red
  knightrider((buttonstore & S6) > 0);
  //Button7 white
  tacho((buttonstore & S7) > 0);
  //Button8 black
  underbody_rb((buttonstore & S8) > 0);
  //Button 9 kill
  if ((pressed & S9) > 0)
    police();
  //Button 10 horn
  if ((pressed & S10) > 0)
    flash();
}
