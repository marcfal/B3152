#include <msp430fg4618.h>

/*  Initialize the LCD_A controller
    
    claims P5.2-P5.4, P8, P9, and P10.0-P10.5
    assumes ACLK to be default 32khz (LFXT1)
*/
void lcd_init()
{
  // our LCD screen is a SBLCDA4 => 4-mux operation (cf motherboard.pdf p6)
  
  // 4-mux operation needs all  4 common lines (COM0-COM3). COM0 has
  // its dedicated pin  (pin 52, cf datasheet.pdf p3),  so let's claim the
  // other three.
  P5DIR |= (BIT4 | BIT3 | BIT2); // pins are output direction
  P5SEL |= (BIT4 | BIT3 | BIT2); // select 'peripheral' function (VS GPIO)
  
  // Configure LCD controller (cf msp430.pdf page 750)
  LCDACTL = 0b00011101;
  // bit 0 turns on the LCD_A module
  // bit 1 unused
  // bit 2 enables LCD segments
  // bits 3-4 set LCD mux rate: 4-mux
  // bits 5-7 set LCD frequency
  
  // Configure port pins
  //
  // mappings  are  detailed  on motherboard.pdf p19: our  screen  has  22
  // segments, wired to MCU pins S4 to S25 (shared with GPIO P8, P9,
  // and P10.0 to P10.5)
  LCDAPCTL0 = 0b01111110;
  // bit 0: MCU S0-S3   => not connected to the screen
  // bit 1: MCU S4-S7   => screen pins S0-S3   (P$14-P$11)
  // bit 2: MCU S8-S11  => screen pins S4-S7   (P$10-P$7)
  // bit 3: MCU S12-S15 => screen pins S8-S11  (P$6 -P$3)
  // bit 4: MCU S16-S19 => screen pins S12-S15 (P$2, P$1, P$19, P$20)
  // bit 5: MCU S20-S23 => screen pins S16-S19 (P$21-P$24)
  // bit 6: MCU S24-S25 => screen pins S20-21  (P$25, P$26)
  // bit 7: MCU S28-S31 => not connected to the screen
  
  LCDAPCTL1 = 0 ; // MCU S32-S39 => not connected to the screen
}

void lcd_clear()
{
	int i;
	for(i=145; i<165;i++)
	{
	*(unsigned char*)i=0;
	}
}

void lcd_fill()
{
	int i;
	for(i=145; i<165;i++)
	{
	*(unsigned char*)i=255;
	}
	
}

void lcd_display_digit(int pos, int digit)
{
	unsigned char* octet = (unsigned char*)(pos + 146);
	int bits;
	bits = 0;
	if (digit == 0)
	{
		bits = 95;
	}
	else if (digit == 1)
	{
		bits = 6;
	}
	else if (digit == 2)
	{
		bits = 107;
	}
	else if (digit == 3)
	{
		bits = 47;
	}
	else if (digit == 4)
	{
		bits = 54;
	}
	else if (digit == 5)
	{
		bits = 61;
	}
	else if (digit == 6)
	{
		bits = 125;
	}
	else if (digit == 7)
	{
		bits = 7;
	}
	else if (digit == 8)
	{
		bits = 127;
	}
	else if (digit == 9)
	{
		bits = 63;
	}

	*octet = bits;

}

void lcd_display_number(unsigned int n)
{
	int j;
	for(j=1; j<8; j++)
	{
		lcd_display_digit(j, n%10);
		n=n/10;
	}

}

