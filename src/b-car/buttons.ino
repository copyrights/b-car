/**
 * @file buttons.ino
 * @author copyrights
 * @ingroup buttons
 * @brief Use two R-2R resistor ladder networks to connect up to 10 buttons on two analog inputs.
 * @see https://en.wikipedia.org/wiki/Resistor_ladder#R.E2.80.932R_resistor_ladder_network_.28digital_to_analog_conversion.29
 */

/** @ingroup buttons
 * @{
 */

/** @brief Last read of button pressed. */
uint16_t lastbuttons = 0;
/** @brief Pressed Buttons after debounce. */
uint16_t stablebuttons = 0;
/** @brief Stores push buttons as simulated toggle buttons */
uint16_t buttonstore = TOGGLEMASK;
/** @brief Stores current button state with simulated toggle buttons included. */
uint16_t buttonstate = 0;
/** @brief Stores simulated interrupts for rising edge. */
uint16_t rising = 0;
/** @brief Stores simulated interrupts for falling edge. */
uint16_t falling = 0;
/** @brief Filter for simulated interrupts for rising edge */
uint16_t rfilter = 0;
/** @brief Filter for simulated interrupts for falling edge */
uint16_t ffilter = 0;
/** @brief Store the time of the last debounce to calculate delta time to next debounce. */
unsigned long dtime = 0;

/** @brief Read button state and calculate stable button state */
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

/** 
 * @brief Returns the state of a button as boolean.
 * 
 * @param mask Button of interested.
 * @return Returns true, if button is pressed. Returns false, if it is not pressed.
 */
bool buttonState(uint16_t mask)
{
  return ((buttonstate & mask) > 0);
}

/**
 * @brief Calculated the current button state as a 5 bit mask.
 * 
 * @param pin Analog input pin connected to a R-2R resistor ladder network.
 * @return Current button state as 5 bit mask.
 */
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

/**
 * @brief Debounce button presses of the R-2R resistor ladder network.
 * 
 * @param curbuttons Bit mask of current button state.
 * @return Bit mask of debounced button state.
 */
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

/**
 * @brief Update the simulated interrupts of the R-2R resistor ladder network.
 * 
 * @param state Bit mask of current button state.
 */
void updintr(uint16_t state)
{
  rfilter &= state;
  ffilter &= ~state;
  rising = state ^ rfilter;
  falling = ~state ^ ffilter;
}

/** 
 * @brief Get simulated rising edge interrupt(s) for simulated interrupt service routine.
 * 
 * @param mask Button(s) of interest.
 * @return Bit mask of interrupt(s).
 */
uint16_t getRising(uint16_t mask)
{
  uint16_t ret = rising & mask;
  rfilter |= ret;
  rising &= ~rfilter;
  return ret;
}

/** 
 * @brief Get simulated falling edge interrupt(s) for simulated interrupt service routine.
 * 
 * @param mask Button(s) of interest.
 * @return Bit mask of interrupt(s).
 */
uint16_t getFalling(uint16_t mask)
{
  uint16_t ret = falling & mask;
  ffilter |= ret;
  falling &= ~ffilter;
  return ret;
}
/**@}*/

