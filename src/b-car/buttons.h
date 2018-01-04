#ifndef BUTTONSH
#define BUTTONSH
#include "config.h" 
/** @brief Last read of button pressed. */
extern uint16_t lastbuttons;
/** @brief Pressed Buttons after debounce. */
extern uint16_t stablebuttons;
/** @brief Stores push buttons as simulated toggle buttons */
extern uint16_t buttonstore;
/** @brief Stores current button state with simulated toggle buttons included. */
extern uint16_t buttonstate;
/** @brief Stores simulated interrupts for rising edge. */
extern uint16_t rising;
/** @brief Stores simulated interrupts for falling edge. */
extern uint16_t falling;
/** @brief Filter for simulated interrupts for rising edge */
extern uint16_t rfilter;
/** @brief Filter for simulated interrupts for falling edge */
extern uint16_t ffilter;
/** @brief Store the time of the last debounce to calculate delta time to next debounce. */
extern unsigned long dtime;

void updateButtons();
bool buttonState(uint16_t mask);
uint16_t readr2r(int pin);
uint16_t debounce(uint16_t curbuttons);
void updintr(uint16_t state);
uint16_t getRising(uint16_t mask);
uint16_t getFalling(uint16_t mask);


#endif
