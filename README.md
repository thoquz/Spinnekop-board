# Spinnekop-board
### A minimalist development board for 8-pin ATtiny series chips from Atmel.
---

Basic useful feature list:

 * Designed to be put on the edge of a breadboard, thus taking up minimal space for prototyping.
 * Acts as a breakout board for surface-mount ATtiny chips, each pin is directly broken out the same as the chip's topology.
 * Can be easily made at home, only a single layer of copper traces and 8 components. (including connectors)
 * Supports the ATtiny13/45/85 chips.
 * A programming port. (6-pin ICSP)
 * A linear voltage regulator for powering the board externally. (The LM78L05 can be swapped with a LP2950)


The board is designed in [KiCAD](www.kicad-pcb.org)

The example code requires [avr-gcc compiler](https://gcc.gnu.org/wiki/avr-gcc).

Compiling and flashing the code on a Debian-based distro:

```Shell
sudo apt-get install gcc-avr binutils-avr gdb-avr avr-libc avrdude
make
make flash
```
If the last command fails, change the PROGRAMMER variable in the Makefile to match your programming device.
Consult the avrdude man page for the name of your programming device.