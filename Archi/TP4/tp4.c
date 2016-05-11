#include "msp430fg4618.h"
#include "lcd.h"
#include "intrinsics.h"
unsigned int cpt;

int pause = 0;

int main(void)
{
__eint();
lcd_init(); // Initialize screen
P5DIR |= 0x02 ; // Set P5.1 to output direction
cpt = 0;
TACCR0 = 10486;
TACTL = TASSEL_2 + MC_1;
TACCTL0 = CCIE;
P1IE = 3;

for(;;)
{
volatile unsigned int i;

for(i=0;i<0xFFF0;i++) // software delay
{ // do nothing
}

P5OUT = P5OUT ^ 0x02 ;

}

}

// This will get executed 100 times per second
void __attribute__ ((interrupt(TIMERA0_VECTOR))) mon_traitant_interruption_timer(void)
{
	if(!pause)
	{
		lcd_display_number(cpt);
		cpt++;
	}
}

void __attribute__ ((interrupt(PORT1_VECTOR))) bouton1_appuye (void)
{
	if(!(P1IN & BIT0))
	{
		cpt = 0;
		lcd_display_number(cpt);
	}
	else
	{
		pause = 1 - pause;
	}
	P1IFG = 0;
}

