/**
 * @file speed.ino 
 * @author copyrights
 * @brief Measure speed.
 * @ingroup speed
 * @todo Write a function that detects braking via negative acceleration.
 */

/**
 * @ingroup speed
 * @{
 */
#include "speed.h"
unsigned long speedts;
unsigned long braketime;
unsigned int curspeed;
bool isbraking;

void setup_interrupt()
{
  speedidx = 0;
  curspeed =0;
  speedts=0;
  braketime = 0;
  isbraking = false;
  //pinMode(IPIN,INPUT);
  cli();//disable interrupts during setup
  PCMSK |= _BV(INTERRUPTPIN); // Use PB1 as interrupt pin
  GIMSK |= _BV(PCIE);   // Enable Pin Change Interrupts
  DDRB &= ~(1 << DATADIRECTIONPIN); //cbi(DDRB, DATADIRECTIONPIN);//  set up as input  - pin2 clear bit  - set to zero
  PORTB |= (1<< PORTPIN); //cbi(PORTB, PORTPIN);// disable pull-up. hook up pulldown resistor. - set to zero  
  sei(); // Enable interrupts
}

ISR(PCINT_VECTOR) {
  //Since the PCINTn triggers on both rising and falling edge let's just looks for rising edge
  //i.e. pin goes to 5V
  byte pinState;
  pinState = (PINB >> READPIN)& 1; //PINB is the register to read the state of the pins
  if (pinState >0) //look at the pin state on the pin PINB register- returns 1 if high
  {
    speedidx++;
  }
}
/**
 * @brief Get current speed. 
 * 
 * The speed is measured as integral of interrupts in an interval of at 
 * least 256ms. The smallest measurable speed is one interrupt per 
 * 256ms. This function returns an unsigned integer, so the smallest 
 * value above 0 should be 1. To get this result the count of interrupts
 * is bit shifted by 8.
 * 
 * 1<<8 = 256; 256/256 = 1
 * 
 * But what does 1 represent?
 * 
 * I put 16 interrupt marks to tire of my Bobby Car. One interrupt every
 * 250 ms are 15 rpm (revolutions per minute).
 * 
 * My Bobby Car has a tire diameter of about 153 mm. So the circumference
 * is 478mm (d*pi).
 * 
 * 478mm * 15 rpm = 0.4302 km/h
 * 
 * @return current speed.
 * @see ISR(PCINT_VECTOR)
 * @see tacho()
 */
unsigned int getspeed()
{
  unsigned int v = 0;
  unsigned int s = (unsigned int) speedidx;
  unsigned long dt = time - speedts;
  
  if (dt > 255)
  {
     if ( s > 0)
     {
       s = s<<8;
       v = s/dt;
     }
     acceleration(v);
     curspeed = v;
     resetspeed();

  }
  return curspeed;
}

/**
 * @brief Test for negative accelaration (braking)
 * 
 * @param newspeed current speed.
 */
void acceleration(unsigned int newspeed)
{
  if (curspeed==0) return;
  if (newspeed > curspeed)
  {
    isbraking = false;
  }
  if ((curspeed/2) > newspeed)
  {
    isbraking = true;
    braketime = time;
  }
}

/**
 * @brief Braking information
 * 
 * Return true if car is braking.
 * @return braking state.
 */
bool braking()
{
  return (isbraking && (time-braketime) < BRAKETIME);
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

/**@}*/
