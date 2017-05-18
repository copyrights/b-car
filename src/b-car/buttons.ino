/*
R2R network
*/
#define DEBOUNCE 20
uint16_t lastbuttons = 0;
uint16_t stablebuttons = 0;
unsigned long dtime = 0;

uint16_t pressedButtons()
{
  uint16_t reading = readr2r(BUTTONS1) + (readr2r(BUTTONS2)<<5);
  reading = debounce(reading);
  return reading;
}

uint16_t readr2r(int pin)
{
  uint16_t reading =  analogRead(pin);
  uint16_t rest;
  rest = reading & 0x1f;
  reading = reading & 0x3e0;
  if (rest > 0xf)
    reading = reading  + 32;
  reading = reading >> 5;
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

