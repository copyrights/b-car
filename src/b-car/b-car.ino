#include <Adafruit_NeoPixel.h>
#include "config.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif



static volatile unsigned long time;
byte mode=0;



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
  updateButtons();
  time = millis();
  if(mode == 0){
    normalmode();
  }
  else if (mode == 1)
  {
    rainbowmode();
  }                                                     
  if (getRising(S1)>0)
  {
    mode=(mode+1)%2;
    resetspeed();
  }
  strip.show();
}


void normalmode(){
  unsigned long beamstate=0;
  clearAll();
  //Button5
  if(buttonState(S5)){
    beamstate=LOWBEAM;  
  }
  //Button4
  if(buttonState(S4)){
    beamstate=HIGHBEAM;
  }
  //Button7 white
  if (buttonState(S7))
    beam(beamstate);
  
  //Button2
  if(buttonState(S2))
    turn_right();
    
  //Button3
  if (buttonState(S3))
    turn_left();
  
  //Button6 red
  if(buttonState(S6))
    knightrider();
  
  tacho();
  //Button8 black
  if(buttonState(S8))
    underbody_rb();
  //Button 9 kill
  if (buttonState(S9))
    police();
  //Button 10 horn
  if (buttonState(S10))
    flash();
}
