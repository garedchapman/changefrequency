#include <msp430.h> 
#include "LCD.h"
#include "buttons.h"
/*
 * C2C Gared Chapman
 * Lab 4 - LCD Device Driver in C
 * ECE 382
 */
char *mess1="This is the first message";
char *mess2="Message number two is just for you!";
char *mess3="Message Three, time management is key!";
char *topline1="Message?";
char *bottomline1="Press123";
char *topline2="ECE 382 is my favorite class!";
char * resultmessage;

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    INITSPI();
    LCDinit();
    LCDclear();


    //messageScroll("ECE382 is my favorite class!","Coding is very difficult");
   // LCDclear();

    firstLine();
    print(topline1);
    secondLine();
    print(bottomline1);

    configureP1toButton(BIT1|BIT2|BIT3);

    P1DIR |= BIT0|BIT6;

    while(1){
          char buttons[] = {BIT1, BIT2, BIT3};
          char pressedButton = pollP1Buttons(buttons, 3);

          switch (pressedButton) {
              case BIT1:
            	  resultmessage = mess1;
                  messageScroll(topline2, resultmessage);

                  break;
              case BIT2:
            	  resultmessage = mess2;
                  messageScroll(topline2, resultmessage);

                  break;
              case BIT3:
            	  resultmessage = mess3;
                  messageScroll(topline2, resultmessage);

                 // P1OUT ^= BIT0|BIT6;
                  //waitForP1ButtonRelease(BIT3);
                  break;
          }

    while(1){

    }


}

}
