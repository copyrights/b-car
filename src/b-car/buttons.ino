/*
R2R network
*/

uint16_t lastbuttons = 0;
uint16_t stablebuttons = 0;
uint16_t buttonstore = TOGGLEMASK;
uint16_t buttonstate = 0;
uint16_t rising = 0;
uint16_t falling = 0;
uint16_t rfilter = 0;
uint16_t ffilter = 0;
unsigned long dtime = 0;

void updateButtons()
{
  uint16_t reading = readr2r(BUTTONS1) + (readr2r(BUTTONS2)<<5);
  reading = debounce(reading);
  stablebuttons = reading;
  updintr(reading);
  buttonstore ^= getRising(TOGGLEMASK);
  buttonstate = (~TOGGLEMASK) & stablebuttons;
  buttonstate |= TOGGLEMASK & buttonstore;
}

bool buttonState(uint16_t mask)
{
  return ((buttonstate & mask) > 0);
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
  uint16_t ret = stablebuttons;
  if (curbuttons == lastbuttons)
  {
    if(stablebuttons != lastbuttons && (time-dtime) > DEBOUNCE){
        ret = lastbuttons;
    }
  }
  else
  {
    lastbuttons = curbuttons;
    dtime = time;
  }
  return ret;
}

void updintr(uint16_t state)
{
  rfilter &= state;
  ffilter &= ~state;
  rising = state ^ rfilter;
  falling = ~state ^ ffilter;
}

uint16_t getRising(uint16_t mask)
{
  uint16_t ret = rising & mask;
  rfilter |= ret;
  rising &= ~rfilter;
  return ret;
}

uint16_t getFalling(uint16_t mask)
{
  uint16_t ret = falling & mask;
  ffilter |= ret;
  falling &= ~ffilter;
  return ret;
}


