/*
R2R network
*/
#define DEBOUNCE 20
uint16_t lastbuttons = 0;
uint16_t stablebuttons = 0;
unsigned long dtime = 0;

uint16_t pressedButtons()
{
  uint16_t reading, rest;
  uint32_t correct;
  reading =  analogRead(BUTTONS);
  if (reading > 14)
    reading = reading-14;
  else
    reading = 0;
  correct = (((reading*4)/3) & 0x3fe)>>1;
  correct = (correct*31)/30;
  reading = (uint16_t) correct;/**/
  
  //reading = (reading << 1);
  rest = reading & 0xf;
  if (rest > 7)
    reading = reading + 16;
  max(reading, 0x1ff);
  reading = reading & 0x1f0;
  reading = reading >> 4;
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

