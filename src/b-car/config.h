#define PIN 0
#define NUM_LEDS 32

#define BUTTONS1 A1
#define BUTTONS2 A2

#define S1  0b0000000001
#define S2  0b0000000010
#define S3  0b0000000100
#define S4  0b0000001000
#define S5  0b0000010000
#define S6  0b0000100000
#define S7  0b0001000000
#define S8  0b0010000000
#define S9  0b0100000000
#define S10 0b1000000000

#define TOGGLEMASK 0b0011100000

#define TURNLIGHT 0xffc000
#define LOWBEAM 0x3f3f3f
#define HIGHBEAM 0x7f7f7f
#define BACKLIGHT 0x3f0000

#define DEBOUNCE 20

#define KRR 0x7f
#define KRG 0x00
#define KRB 0x00
#define KRPERIOD 500
#define KRDTZ 200

#define PR 0x00
#define PG 0x00
#define PB 0xff
#define PPERIOD 1000
#define PDTZ 200
#define PLFLASH 0xff0000
#define PLLOW 0x1f0000
#define PRFLASH 0x0000ff
#define PRLOW 0x00001f
#define RBSTEP 40

#define INTERRUPTPIN PCINT1 //this is PB1 per the schematic
#define PCINT_VECTOR PCINT0_vect  //this step is not necessary
#define DATADIRECTIONPIN DDB1 //Page 64 of data sheet
#define PORTPIN PB1 //Page 64
#define READPIN PINB1 //page 64
//CF = 150 *Pi = 235.61944901923448
#define CF 236
#define INCR 4

const byte turn_light_left[]={17,27};
const byte low_beam_row[] ={1,2,16,15};
const byte high_beam_row[] = {1,2,16,15};
const byte front_row[] = {3,4,5,13,14};
const byte tacho_row[] = {12,11,10,9,8,7,6};
const byte turn_light_right[]={0,30};
const byte down_left_row[] = {18,19,20,21};
const byte down_right_row[] = {22,23,24,25};
const byte back_light_row[] = {26,28,29,31};

const byte rainbowrow_left[]  = {5,13,14,17,15,16,18,19,20,21,30,31,29, 9,10,11,12};
const byte rainbowrow_right[] = {5, 4, 3, 0 , 2, 1,22,23,24,25,27,26,28, 9, 8, 7, 6};

