#include "msp430fg4618.h"
#include "lcd.h"
unsigned int cpt;
int main(void)
{
lcd_init(); // Initialize screen
P5DIR |= 0x02 ; // Set P5.1 to output direction
cpt = 0;
TACCR0 = 10486;
TACTL = TASSEL_2 + MC_1;

for(;;)
{
volatile unsigned int i;

if(TACTL & TAIFG == 1)
	{
	TACTL = TASSEL_2 + MC_1;
	lcd_display_number(cpt);
	cpt++;
	P5OUT = P5OUT ^ 0x02 ; // toggle P5.1 (LED4)
	}
}
}
