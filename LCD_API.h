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

// Here are some helper functions from my LCD.c
// I don't expose these in my header, but may be helpful to you.

void writeDataByte(char dataByte);
void writeCommandNibble(char commandNibble);
void writeCommandByte(char commandByte);

#endif /* LCD_API_H_ */
