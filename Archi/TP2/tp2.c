#include <msp430fg4618.h>
#include "lcd.h"


volatile unsigned int i;

int main(void)
{	
	lcd_init();
	lcd_clear();

	int i = 0;
	for(;;)
	{
		lcd_display_number(i++);
		sleep(10000);
	}
	







	/*
	P5DIR = 2;
	P2DIR = 6;
	P5OUT = 0;
	P2OUT = 0;
	for(;;)
	{
		while(P1IN > 2){} 	//aucun bouton pressé
		while(P1IN <= 2){} 	//un bouton pressé

		P2OUT = 4;	//vert
		P5OUT = 0; 
		
		sleep();

		while(P1IN > 2){} 	//aucun bouton pressé
		while(P1IN <= 2){} 	//un bouton pressé

		P2OUT = 2;	//jaune

		sleep();

		while(P1IN > 2){} 	//aucun bouton pressé
		while(P1IN <= 2){} 	//un bouton pressé

		P5OUT = 2;	//rouge
		P2OUT = 0;

		sleep();
	}*/

	/*for(;;)
	{
		// software delay
		for(i=0;i<20000;i++)
		{}//do nothing

		// turn red LED on
		P5OUT = 2;
		P2OUT = 6;
		
		for(i=0;i<20000;i++)
		{}//do nothing

		// turn red LED off
		P5OUT = 0;
		P2OUT = 0;

	}*/
}

void sleep(int duree){
	int j;
	for(j=0; j<duree; j++){}
}
