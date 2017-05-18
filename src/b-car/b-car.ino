#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 0
#define NUM_LEDS 32

#define BUTTONS1 A1
#define BUTTONS2 A2

#define TURNLIGHT 0xffc000
#define LOWBEAM 0x3f3f3f
#define HIGHBEAM 0x7f7f7f
#define BACKLIGHT 0x3f0000

const byte turn_light_left[]={17,27};
const byte low_beam_row[] ={1,2,16,15};
const byte high_beam_row[] = {1,2,16,15};
const byte front_row[] = {3,4,5,13,14};
const byte tacho_row[] = {12,11,10,9,8,7,6};
const byte turn_light_right[]={0,30};
const byte down_left_row[] = {18,19,20,21};
const byte down_right_row[] = {22,23,24,25};
const byte back_light_row[] = {26,28,29,31};

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
