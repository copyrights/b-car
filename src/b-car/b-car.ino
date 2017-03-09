#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 0
#define NUM_LEDS 50

//100kOhm -> GND
#define BUTTONS A1
//10kOhm
#define BUTTON1 895
//22kOhm
#define BUTTON2 831
//47kOhm
#define BUTTON3 687
//69kOhm
#define BUTTON4 603
//79kOhm
#define BUTTON5 567

#define TURNLIGHT 0xffc000
#define LOWBEAM 0x3f3f3f
#define HIGHBEAM 0x7f7f7f
#define KRR 0x7f
#define KRG 0x00
#define KRB 0x00

byte turn_light_frontleft[]={0};
byte low_beam_left[] ={1};
byte high_beam_left[] = {2};
byte front_row[] = {3,4,5,6,7};
byte low_beam_right[] ={9};
byte high_beam_right[] = {8};
byte turn_light_frontright[]={10};

unsigned long time;
bool modified;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  pinMode(BUTTONS, INPUT);
  strip.begin();
  strip.show();
  //low_beam(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t pressed =  pressedButtons();
  modified=false;
  
  time = millis();
  //Button1
  if((pressed & 1) > 0){
    low_beam(true);
  }else{
    low_beam(false);
  }
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
  //Button4
  if((pressed & (1<<3)) > 0){
    high_beam(true);
  }else{
    high_beam(false);
  }
  
  //Button5
  if((pressed & (1<<4)) > 0){
    noknightrider();
  }else{
    knightrider();
  }
  if(modified) strip.show();
}


