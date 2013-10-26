/*
 * buttons.c
 *
 *  Created on: Oct 25, 2013
 *      Author: C15Gared.Chapman
 */
#include <msp430.h>
#include "buttons.h"

#define TRUE 1

void configureP1toButton(char pin)
{
    P1DIR &= ~pin;
    P1OUT |= pin;
    P1REN |= pin;
}

char P1ButtonReleased(char pin)
{
    return P1IN & pin;
}

void waitForP1ButtonRelease(char pin)
{
    while (!isP1ButtonReleased(pin)) {}
    debounce();
}

char P1ButtonPressed(char pin)
{
    return !(P1IN & pin);
}

char pollP1Buttons(char buttonsToPoll[], char numberOfButtonsToPoll)
{
    int i;

    while (TRUE)
    {
        for (i = 0; i < numberOfButtonsToPoll; i++) {
            if (P1ButtonPressed(buttonsToPoll[i]))
            {
                return buttonsToPoll[i];
            }
        }
    }
}

void debounce()
{
    __delay_cycles(1000);
}





