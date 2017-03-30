/*
R2R network
*/
#define DEBOUNCE 50
uint16_t lastbuttons = 0;
uint16_t stablebuttons = 0;
unsigned long dtime = 0;

uint16_t pressedButtons()
{
  uint16_t reading, rest;
  
  reading =  analogRead(BUTTONS);
  rest = reading & 0x1f;
  if (rest > 0xF)
    reading = reading + 32;
  reading = reading & 0x3e0;
  reading = reading >> 5;
  reading = debounce(reading);
  return reading;
}


uint16_t debounce(uint16_t curbuttons)
{
  if (curbuttons == lastbuttons)
  {
    if(stablebuttons != lastbuttons && (time-dtime) > DEBOUNCE){
        stablebuttons = lastbuttons;
    }
  }
  else
  {
    lastbuttons = curbuttons;
    dtime = time;
  }
  return stablebuttons;
}

