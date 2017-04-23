uint8_t fade8(uint16_t distance, uint16_t dtz)
{
  uint8_t relative;
  if (distance > dtz)
    return 0;
  relative = (uint8_t) ((distance * 127) / dtz);
  return cos8(relative);
}

uint8_t percent8(uint8_t full, uint8_t fac)
{
  uint16_t value = (full * fac) / 255;
  return (uint8_t) value;
}

/*
sin8 and cos8 are copied from FastLED 
https://github.com/FastLED/FastLED/blob/master/lib8tion/trig8.h
*/
const uint8_t b_m16_interleave[] = { 0, 49, 49, 41, 90, 27, 117, 10 };
/// Fast 8-bit approximation of sin(x). This approximation never varies more than
/// 2% from the floating point value you'd get by doing
///
///     float s = (sin(x) * 128.0) + 128;
///
/// @param theta input angle from 0-255
/// @returns sin of theta, value between 0 and 255
uint8_t sin8( uint8_t theta)
{
    uint8_t offset = theta;
    if( theta & 0x40 ) {
        offset = (uint8_t)255 - offset;
    }
    offset &= 0x3F; // 0..63

    uint8_t secoffset  = offset & 0x0F; // 0..15
    if( theta & 0x40) secoffset++;

    uint8_t section = offset >> 4; // 0..3
    uint8_t s2 = section * 2;
    const uint8_t* p = b_m16_interleave;
    p += s2;
    uint8_t b   =  *p;
    p++;
    uint8_t m16 =  *p;

    uint8_t mx = (m16 * secoffset) >> 4;

    int8_t y = mx + b;
    if( theta & 0x80 ) y = -y;

    y += 128;

    return y;
}

uint8_t cos8( uint8_t theta)
{
    return sin8( theta + 64);
}

/*
Wheel is copied from Adafruit_NeoPixel examples.
https://github.com/adafruit/Adafruit_NeoPixel/blob/master/examples/strandtest/strandtest.ino
*/
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

