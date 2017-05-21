#include <Adafruit_NeoPixel.h>
#include "config.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif



static volatile unsigned long time;
bool modified;
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
  
  //Button5
  if(buttonState(S5)){
    beamstate=LOWBEAM;  
  }
  //Button4
  if(buttonState(S4)){
    beamstate=HIGHBEAM;
  }
  
  beam(beamstate);
  
  //Button2
  turn_right(buttonState(S2));
    
  //Button3
  turn_left(buttonState(S3));
  
  //Button6 red
  knightrider(buttonState(S6));
  //Button7 white
  tacho(buttonState(S7));
  //Button8 black
  underbody_rb(buttonState(S8));
  //Button 9 kill
  if (buttonState(S9))
    police();
  //Button 10 horn
  if (buttonState(S10))
    flash();
}
