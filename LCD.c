/*
 * LCD_implement.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Gared.Chapman
 */
#include <msp430.h>
#include "LCD.h"
#define RS_MASK 0x40
char LCDCON;
char pointer = 0;
void INITSPI(void)
{
	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;
	UCB0CTL1 |= UCSSEL1;
	UCB0STAT |= UCLISTEN;
	P1SEL |= BIT5;
	P1SEL2 |= BIT5;
	P1SEL |= BIT6;
	P1SEL2 |= BIT6;
	P1SEL |= BIT7;
	P1SEL2 |= BIT7;

	UCB0CTL1 &= ~UCSWRST;
}

void set_SS_hi(void)
{
	P1DIR |= BIT0;
	P1OUT |= BIT0;
}
//write 4, ss hi, ss lo,

void set_SS_lo(void)
{
	P1DIR |= BIT0;
	P1OUT &= ~BIT0;
}


void delayMilli(void){

	_delay_cycles(10000);

}

void delayMicro(void){

	_delay_cycles(1000);

}


void LCD_write_4(char LCDDATA)
{
	unsigned char databyte = LCDDATA;
	databyte &= 0x0F;

	databyte |= LCDCON;
	databyte &= 0x7F;

	SPI_send(databyte);

	delayMicro();

	databyte |= 0x80;
	SPI_send(databyte);

	delayMicro();

	databyte &= 0x7F;
	SPI_send(databyte);

	delayMicro();

}

void LCD_write_8(char byteToSend)
{
    unsigned char sendByte = byteToSend;

    sendByte &= 0xF0;

    sendByte = sendByte >> 4;               // rotate to the right 4 times

    LCD_write_4(sendByte);

    sendByte = byteToSend;

    sendByte &= 0x0F;

    LCD_write_4(sendByte);
}


void SPI_send(char byteToSend)
{
    volatile char readByte;

    set_SS_lo();

    UCB0TXBUF = byteToSend;

    while(!(UCB0RXIFG & IFG2))
    {
        // wait until you've received a byte
    }

    readByte = UCB0RXBUF;

    set_SS_hi();
}


void writeCommandNibble(char commandNibble)
{
    LCDCON &= ~RS_MASK;
    LCD_write_4(commandNibble);
    delayMilli();
}

void writeCommandByte(char commandByte)
{
    LCDCON &= ~RS_MASK;
    LCD_write_8(commandByte);
    delayMilli();
}

void LCDinit()
{
    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x02);

    writeCommandByte(0x28);

    writeCommandByte(0x0C);

    writeCommandByte(0x01);

    writeCommandByte(0x06);

    writeCommandByte(0x01);

    writeCommandByte(0x02);

    SPI_send(0);
    delayMicro();
}


void LCDclear()
{
    writeCommandByte(1);
}


void writeDataByte(char dataByte)
{
    LCDCON |= RS_MASK;
    LCD_write_8(dataByte);
    delayMilli();
}

void rotate_string(char string[])
{
	int i = 0;
	int j = 0;

	int arraylength = 0;
	while(string[j] != 0)
	{
		arraylength++;
		j++;

	}
	char firstvalue = string[i];
	for (i = 0;i<arraylength; i++)
	{
		string[i]=string[i+1];
	}

	string[arraylength-1] = firstvalue;
}

