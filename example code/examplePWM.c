/*
 This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

An example program (For the spinnekop-board) that fades the LED at PB1
between HIGH and LOW state. (Breathing light effect)
Example usage: The board can be connected to the power LED pin inside 
a desktop computer 

([VCC --> LED+] & [GND --> LED-] of the board pins instead of the LED),

Then the LED inside the case can be connected to the spinnekop-board 

([LED+ --> PB0] & [LED- --> GND] of the LED pins onto the board)

PB0 is pin 5 on the microcontroller.
The LED on the desktop's case will now fade in a breathing pattern,
with a board implanted between the LED and the motherboard to create
the effect. 

Made by Philip Goosen
*/

#define F_CPU 9600000 // 9.6MHz with internal oscillator
#define TIMEW 1024 // Sets the rate of the fading effect.

#include <avr/io.h>
#include <util/delay_basic.h>

void setup_pwm()
{
	//prescaler
	TCCR0B |= (1 << CS01) | (1 << CS00);

	//fast pwm
	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	TCCR0A |= (1 << COM0B1);
}

void write_pwm(int val)
{
	OCR0B = val;
}



int main(void)
{
	int val;

	DDRB |= (1 << PB1); // Set LED as output on PB1 

	setup_pwm();


	while(1)
		{
			for(val = 0; val < 255; val++) // Increases the brightness
			{
				write_pwm(val);
				_delay_loop_2(TIMEW);
			}
			
			for(val = 255; val > 0; val--) // Decreases the brightness
			{
				write_pwm(val);
				_delay_loop_2(TIMEW);
			}
		}
}
