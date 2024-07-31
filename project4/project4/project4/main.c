 /******************************************************************************
 *
 *
 * File Name: main.c
 *
 * Description: measure the distance using ultrasonic sensor
 *
 * Author: aya ashraf
 *
 *******************************************************************************/
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */


int main()
{
	uint32 distance = 0;


	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);


	/* Initialize both the LCD and ultrasonic driver */
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance =");


	while(1)
	{    LCD_moveCursor(0,10);
		{
		    /* read the distance from the ultrasonic */
			distance = Ultrasonic_readDistance();
			if(distance>100)
			{
				/* display the period on LCD screen */
				LCD_intgerToString(distance);
				LCD_displayString(" cm");

			}
			else
			{
			/* display the period on LCD screen */

			LCD_intgerToString(distance);
			LCD_displayString(" cm");
			LCD_displayString(" ");
			}
		}
	}
}
