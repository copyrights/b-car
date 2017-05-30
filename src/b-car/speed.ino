#ifdef __AVR__
  #include <avr/interrupt.h>
#endif

static volatile byte speedidx;
unsigned long speedts;
unsigned int curspeed;

void setup_interrupt()
{
  speedidx = 0;
  curspeed =0;
  speedts=0;
  //pinMode(IPIN,INPUT);
  cli();//disable interrupts during setup
  PCMSK |= _BV(INTERRUPTPIN); // Use PB1 as interrupt pin
  GIMSK |= _BV(PCIE);   // Enable Pin Change Interrupts
  DDRB &= ~(1 << DATADIRECTIONPIN); //cbi(DDRB, DATADIRECTIONPIN);//  set up as input  - pin2 clear bit  - set to zero
  PORTB |= (1<< PORTPIN); //cbi(PORTB, PORTPIN);// disable pull-up. hook up pulldown resistor. - set to zero  
  sei(); // Enable interrupts
}

ISR(PCINT_VECTOR ) {
  //Since the PCINTn triggers on both rising and falling edge let's just looks for rising edge
  //i.e. pin goes to 5v
  byte pinState;
  pinState = (PINB >> READPIN)& 1; //PINB is the register to read the state of the pins
  if (pinState >0) //look at the pin state on the pin PINB register- returns 1 if high
  {
    speedidx++;
  }
}

unsigned int getspeed()
{
  unsigned int v = 0;
  unsigned int s = (unsigned int) speedidx;
  unsigned long dt = time - speedts;
  
  if (dt > 250)
  {
     if ( s > 0)
     {
       s = s<<8;
       v = s/dt;
     }
     curspeed = v;
     resetspeed();

  }
  return curspeed;
}

void resetspeed()
{
     speedts = time;
     //cli();
     speedidx = 0;
     //sei();
}

byte getspeedidx()
{
  return speedidx;
}
/*
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
*/
