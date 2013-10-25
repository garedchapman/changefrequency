#include <msp430.h> 
#include "LCD.h"
char letter = 0;
char letter2 = 0;

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    INITSPI();
    LCDinit();
    LCDclear();


    messageScroll("ECE382 is my favorite class!","Coding is very difficult");
    LCDclear();

    while(1){

    }

	return 0;

}
