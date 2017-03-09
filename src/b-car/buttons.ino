/*
R2R network
*/
uint16_t pressedButtons()
{
  uint16_t reading, rest;
  
  reading =  analogRead(BUTTONS);
  rest = reading & 0x1f;
  if (rest > 0xF)
    reading = reading + 32;
  reading = reading & 0x3e0;
  reading = reading >> 5;
  return reading;
}


