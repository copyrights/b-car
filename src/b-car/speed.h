#ifndef SPEEDH
#define SPEEDH
#include "config.h" 
#ifdef __AVR__
  #include <avr/interrupt.h>
#endif

#define BRAKETIME 1000
static volatile byte speedidx;
extern unsigned long speedts;
extern unsigned long braketime;
extern unsigned int curspeed;
extern bool isbraking;

void setup_interrupt();
unsigned int getspeed();
void acceleration(unsigned int newspeed);
bool braking();
void resetspeed();
byte getspeedidx();
#endif
