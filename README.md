# b-car
That a classic Big Bobby Car, cut a hole in the underbody, drill some more holes, put some RGB-LEDs, buttons and a sensor through holes, place a battery and a circuit board inside and you ready to go.

  ![b-car GIF](res/b-car.gif) 
## Features
* Knight Rider like front row
* full control
  * connect up to 10 button (+power button)
  * program via USB
  * write our own program with Arduino IDE 1.6.5+ (Arduino 1.6.5r2 - NOT 1.6.6 or 1.6.7 strongly recommended) 
* tachometer
  * three colors
  * show real speed via photo sensor at a tire
* car basics
  * low beam
  * high beam 
  * back light
  * turn lights
* flash light
* police beacon light an front flash
* rainbow mode

![b-car police mode GIF](res/b-car_police.gif) ![b-car rainbow GIF](res/b-car_rainbow.gif)
## Hardware
### Circuit 

![schematic](res/b-car_schematic.png)

![bread board](res/b-car_breadboard.png)

![pcb front side](res/b-car_pcb_front.png)

![pcb back side](res/b-car_pcb_back.png)

![final board](res/real_pcb.jpg)
### Bobby Car 

![sketch front](res/sketch_front.png)

![Sketch front](res/sketch_back.png)

## Software
The b-car runs the [micronucleus tiny85](https://github.com/micronucleus/micronucleus) bootloader. 
