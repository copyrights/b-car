#ifndef CARBASICSH
#define CARBASICSH
#include "config.h" 
void turn_right();
void turn_left();
void beam(unsigned long state);
void low_beam(bool on);
void high_beam(bool on);
void tacho();
void flash();
void brakelight();

#endif
