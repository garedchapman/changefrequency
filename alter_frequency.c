/*
 * alter_frequency.c
 *
 *  Created on: Oct 25, 2013
 *      Author: C15Gared.Chapman
 */
#include "alter_frequency.h"

void alter1MHz(){
        BCSCTL1 = CALBC1_1MHZ;       // Set range
        DCOCTL = CALDCO_1MHZ;        // Set DCO step and modulation
}

void alter8MHz(){
        BCSCTL1 = CALBC1_8MHZ;       // Set range
        DCOCTL = CALDCO_8MHZ;        // Set DCO step and modulation
}

void alter12MHz(){
        BCSCTL1 = CALBC1_12MHZ;       // Set range
        DCOCTL = CALDCO_12MHZ;        // Set DCO step and modulation
}

void alter16MHz(){
        BCSCTL1 = CALBC1_12MHZ;       // Set range
        DCOCTL = CALDCO_12MHZ;        // Set DCO step and modulation




