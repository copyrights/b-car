#
# Simple Arduino Makefile original by Nick Gammon 18th March 2015
#

# where you installed the Arduino app
ARDUINO_DIR = ~/Downloads/arduino-1.5.8-64bit/
SKETCHES = ~/Arduino

# various programs
CC = $(ARDUINO_DIR)hardware/tools/avr/bin/avr-gcc
CPP = $(ARDUINO_DIR)hardware/tools/avr/bin/avr-g++
AR = $(ARDUINO_DIR)hardware/tools/avr/bin/avr-ar
OBJ_COPY = $(ARDUINO_DIR)hardware/tools/avr/bin/avr-objcopy

MAIN_SKETCH = b-car.cpp

# compile flags for g++ and gcc

# may need to change these
F_CPU = 16500000
MCU = attiny85

# compile flags
GENERAL_FLAGS = -c -g -Os -Wall -ffunction-sections -fdata-sections -mmcu=$(MCU) -DF_CPU=$(F_CPU)L -MMD -DUSB_VID=null -DUSB_PID=null -DARDUINO=106 -DMORERAINBOW
CPP_FLAGS = $(GENERAL_FLAGS) -fno-exceptions
CC_FLAGS  = $(GENERAL_FLAGS)

# location of include files
INCLUDE_FILES = -I $(ARDUINO_DIR)hardware/digistump/avr/cores/tiny/ -I $(ARDUINO_DIR)hardware/digistump/avr/variants/digispark/ -I $(SKETCHES)/libraries/Adafruit_NeoPixel/

# library sources
LIBRARY_DIR = $(ARDUINO_DIR)hardware/digistump/avr/cores/tiny/

build:

	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) $(MAIN_SKETCH) -o $(MAIN_SKETCH).o
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) buttons.cpp -o buttons.cpp.o
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) car_basics.cpp -o car_basics.cpp.o
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) knightrider.cpp -o knightrider.cpp.o
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) police.cpp -o police.cpp.o
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) rainbow.cpp -o rainbow.cpp.o
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) speed.cpp -o speed.cpp.o
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) utils.cpp -o utils.cpp.o
	$(CC) $(CC_FLAGS) $(INCLUDE_FILES) $(LIBRARY_DIR)pins_arduino.c -o pins_arduino.c.o 
	$(CC) $(CC_FLAGS) $(INCLUDE_FILES) $(LIBRARY_DIR)WInterrupts.c -o WInterrupts.c.o 
	$(CC) $(CC_FLAGS) $(INCLUDE_FILES) $(LIBRARY_DIR)wiring.c -o wiring.c.o 
	$(CC) $(CC_FLAGS) $(INCLUDE_FILES) $(LIBRARY_DIR)wiring_analog.c -o wiring_analog.c.o 
	$(CC) $(CC_FLAGS) $(INCLUDE_FILES) $(LIBRARY_DIR)wiring_digital.c -o wiring_digital.c.o 
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) $(LIBRARY_DIR)main.cpp -o main.cpp.o 
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) $(LIBRARY_DIR)new.cpp -o new.cpp.o 
	$(CPP) $(CPP_FLAGS) $(INCLUDE_FILES) $(SKETCHES)/libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp -o Adafruit_NeoPixel.o 
	rm -f core.a
	$(AR) rcs core.a pins_arduino.c.o 
	$(AR) rcs core.a WInterrupts.c.o 
	$(AR) rcs core.a wiring.c.o 
	$(AR) rcs core.a wiring_analog.c.o 
	$(AR) rcs core.a wiring_digital.c.o 
	$(AR) rcs core.a main.cpp.o 
	$(AR) rcs core.a new.cpp.o 
	$(AR) rcs core.a Adafruit_NeoPixel.o
	$(AR) rcs core.a buttons.cpp.o
	$(AR) rcs core.a car_basics.cpp.o
	$(AR) rcs core.a knightrider.cpp.o
	$(AR) rcs core.a police.cpp.o
	$(AR) rcs core.a rainbow.cpp.o
	$(AR) rcs core.a speed.cpp.o
	$(AR) rcs core.a utils.cpp.o
	$(CC) -Os -Wl,--gc-sections -mmcu=$(MCU) -o $(MAIN_SKETCH).elf $(MAIN_SKETCH).o core.a -lm 
	$(OBJ_COPY) -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 $(MAIN_SKETCH).elf $(MAIN_SKETCH).eep 
	$(OBJ_COPY) -O ihex -R .eeprom $(MAIN_SKETCH).elf $(MAIN_SKETCH).hex
	rm -f *.o
	rm -f *.d
	rm -f *.a
	rm -f *.elf
	rm -f *.eep
	
clean:
	rm -f *.o
	rm -f *.d
	rm -f *.a
	rm -f *.elf
	rm -f *.eep
	rm -f *.hex
	
