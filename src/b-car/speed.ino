#ifdef __AVR__
  #include <avr/interrupt.h>
#endif


#define INTERRUPTPIN PCINT1 //this is PB1 per the schematic
#define IPIN 1

//CF = 150 *Pi = 235.61944901923448
#define CF 236
#define INCR 4


static volatile byte speedidx;
static unsigned long volatile measures[INCR*2];

void setup_interrupt()
{
  speedidx = 0;
  for(int i=0;i<INCR;i++)measures[i]=0;
  pinMode(IPIN,INPUT);
  cli();//disable interrupts during setup
  PCMSK |= _BV(INTERRUPTPIN); // Use PB1 as interrupt pin
  GIMSK |= _BV(PCIE);   // Enable Pin Change Interrupts
  sei(); // Enable interrupts
}

ISR(PCINT0_vect) {
  if(digitalRead(IPIN) == LOW)
  {
    if((time - measures[((INCR*2)+speedidx-1)%(INCR*2)]) > 50)
    {
      speedidx=(speedidx+1)%(INCR*2);
      measures[speedidx] = time;
    }
  }
}

//mm/s 
unsigned int getspeed()
{
  unsigned long p, cur_speed;
  p = period();
  if (p == 0) return 0;
  cur_speed = (CF*1000)/p;
  return cur_speed;
}

unsigned int period(){
  byte nidx, lidx;
  nidx = speedidx;
  lidx = (INCR*2 + nidx-1) % (INCR*2);
  return (measures[nidx] - measures[lidx]);
}
byte getspeedidx()
{
  return speedidx;
}
