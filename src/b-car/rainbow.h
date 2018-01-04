#ifndef RAINBOWH
#define RAINBOWH
#include "config.h"
#ifdef MORERAINBOW
	#include "buttons.h"
#endif
void rainbowmode();
void underbody_rb();
void rainbow(byte led, byte pos,byte distance);
#endif
