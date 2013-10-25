/*
 * LCD_API.h
 *works as an interface
 *  Created on: Oct 22, 2013
 *      Author: C15Gared.Chapman
 */

#ifndef LCD_API_H_
#define LCD_API_H_

void INITSPI();

void LCDINIT();

void LCDCLR();

void PRINT();

void printsecondline();

void writeChar(char asciiChar);

void writeString(char * string);

void scrollString(char * string1, char * string2);

void LCD_write_8(char byteToSend);

void LCD_write_4(char LCDDATA);

void SPI_send(char byteToSend);

void set_SS_hi(void);

void set_SS_lo(void);

void print(char * string);

void printCharacter(char asciiChar);

void messageScroll(char * string1, char * string2);

char * scroll_help(char * start, char * current);


void writeDataByte(char dataByte);
void writeCommandNibble(char commandNibble);
void writeCommandByte(char commandByte);

#endif /* LCD_API_H_ */
