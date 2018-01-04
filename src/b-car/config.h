/**
 * @file config.h
 * @brief Adjust your settings here.
 *
 * Create a custom.h file and copy line 15 to second last line of config.h to it. Then uncomment line 10 of config.h file.
 * @author copyrights
 */
#ifndef CONFIGH
#define CONFIGH
#include <Arduino.h> 
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include <Adafruit_NeoPixel.h>
/* uncomment the next line to use custom settings instead of mine */
//#define CUSTOM

#ifdef CUSTOM
#include "custom.h"
#else
/**
 * @defgroup buttons Buttons
 * @brief Use R-2R resistor ladder network for more buttons.
 * 
 * @{
 */
/** @brief Define analog input for first five buttons. */
#define BUTTONS1 A1
/** @brief Define analog input for second five buttons. */
#define BUTTONS2 A2
/** @brief Define delay in ms to debounce button presses.*/
#define DEBOUNCE 20

/** @brief Bit mask for button 5 */
#define S5  0b0000000001
/** @brief Bit mask for button 4 */
#define S4  0b0000000010
/** @brief Bit mask for button 3 */
#define S3  0b0000000100
/** @brief Bit mask for button 2 */
#define S2  0b0000001000
/** @brief Bit mask for button 1 */
#define S1  0b0000010000
/** @brief Bit mask for button 10 */
#define S10 0b0000100000
/** @brief Bit mask for button 9 */
#define S9  0b0001000000
/** @brief Bit mask for button 8 */
#define S8  0b0010000000
/** @brief Bit mask for button 7 */
#define S7  0b0100000000
/** @brief Bit mask for button 6 */
#define S6  0b1000000000

/** @brief Bit mask for simulated toggle buttons. */
#define TOGGLEMASK 0b1110000000

/**@}*/

/**
 * @defgroup car Car Basics 
 * @brief Basic car functionality.
 * 
 * @{
 */
/** @brief Color of turn lights. */
#define TURNLIGHT 0xffc000
/** @brief Color of low beam. */
#define LOWBEAM 0x3f3f3f
/** @brief Color of high beam. */
#define HIGHBEAM 0x7f7f7f
/** @brief Color of back lights. */
#define BACKLIGHT 0x3f0000
/** @brief Color of brake lights. */
#define BRAKELIGHT 0xff0000
/** @brief time brake lights glow in ms. */
#define BRAKETIME 1000
/**@}*/

/**
 * @defgroup knightrider Knight Rider
 * @brief A Knight Rider like front row.
 * 
 * @{
 */
/** @brief Red part of Knight Rider like front row. */
#define KRR 0x7f
/** @brief Green part of Knight Rider like front row. */
#define KRG 0x00
/** @brief Blue part of Knight Rider like front row. */
#define KRB 0x00
/** @brief Period in ms the Knight Rider like front row needs to move in one direction. */
#define KRPERIOD 500
/** @brief Fade out period in ms for a smooth light flow. */
#define KRDTZ 200
/**@}*/

/**@defgroup police Police
 * @brief Police beacon light and front flash.
 * @{
 */
/** @brief Red part of the police beacon light.*/
#define PR 0x00
/** @brief Green part of the police beacon light.*/
#define PG 0x00
/** @brief Blue part of the police beacon light.*/
#define PB 0xff
/** @brief Rotation period in ms of the police beacon light.*/
#define PPERIOD 1000
/** @brief Fade out period in ms for a smooth light flow. */
#define PDTZ 200
/** @brief Left side flash color of the police front row.*/
#define PLFLASH 0xff0000
/** @brief Left side low light color of the police front row.*/
#define PLLOW 0x1f0000
/** @brief Right side flash color of the police front row.*/
#define PRFLASH 0x0000ff
/** @brief Right side low light color of the police front row.*/
#define PRLOW 0x00001f
/**@}*/

/**@defgroup rainbow Rainbow
 * @brief Puts rainbow color to the LEDs.
 * @{
 */
/** @brief Rainbow step size between two LEDs. */
#define RBSTEP 40
/** @brief If defined more functions are added to rainbow mode. */
//#define MORERAINBOW
/**@}*/

/**
 * @defgroup speed Speed
 * @brief Measure speed by interrupts.
 * 
 * @{
 */
#define INTERRUPTPIN PCINT1 //!< This is PB1 per the schematic
#define PCINT_VECTOR PCINT0_vect  //!< @note This step is not necessary
#define DATADIRECTIONPIN DDB1 //!< @see Page 64 of data sheet
#define PORTPIN PB1 //!< @see Page 64
#define READPIN PINB1 //!< @see Page 64
/**@}*/

/**
 * @defgroup deployment Deployment
 * @brief Deployment of LEDs.
 * 
 * @{
 */
 
/** PIN is the data pin for LEDs control.*/
#define PIN 0
/** NUM_LEDS is the count of LEDs use in b-car.*/
#define NUM_LEDS 32
extern const byte turn_light_left[2];
extern const byte low_beam_row[4];
extern const byte high_beam_row[4];
extern const byte front_row[5];
extern const byte tacho_row[7];
extern const byte turn_light_right[2];
extern const byte down_left_row[4];
extern const byte down_right_row[4];
extern const byte back_light_row[4];

extern const byte rainbowrow_left[17];
extern const byte rainbowrow_right[17];

extern Adafruit_NeoPixel strip;
/**@}*/

/**
 * @defgroup main Main 
 * @brief Main program.
 * 
 * @{
 */
 
/**
 * @brief Global accessible variable that stores the current time after program start in ms.
 * @see millis()
 */
extern volatile unsigned long time;

/** @brief stores current operation mode */
extern byte mode;
/**@}*/
#endif
#endif
