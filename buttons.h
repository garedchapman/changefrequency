/*
 * buttons.h
 *
 *  Created on: Oct 25, 2013
 *      Author: C15Gared.Chapman
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_



//
// Configures pin as input with internal pull-up resistor.
//
void configureP1toButton(char pin);

//
// Returns one if button pin is high, zero if button pin is low.
char P1ButtonReleased(char pin);

//
// Blocks while button pin is low.  Debounces on release.
//
void waitForP1ButtonRelease(char pin);

//
// Returns one if button pin is low, zero if button pin is high.
//
char P1ButtonPressed(char pin);

//
// Polls one or more buttons for press, returns bit mask of pressed button
//
char pollP1Buttons(char buttonsToPoll[], char numberOfButtonsToPoll);

//
// Delays for 1000 clock cycles.
//
void debounce();

#endif

