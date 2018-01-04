#ifndef UTILSH
#define UTILSH
#include "config.h" 
void clearAll();
uint8_t fade8(uint16_t distance, uint16_t dtz);
uint8_t percent8(uint8_t full, uint8_t fac);
/**
 * @defgroup FastLED FastLED
 * @brief @ref sin8 and @ref cos8 are copied from FastLED 
 * @see https://github.com/FastLED/FastLED/blob/master/lib8tion/trig8.h
 * @{
 */
const uint8_t b_m16_interleave[] = { 0, 49, 49, 41, 90, 27, 117, 10 };
uint8_t sin8( uint8_t theta);
uint8_t cos8( uint8_t theta);
uint32_t Wheel(byte WheelPos);

#endif
