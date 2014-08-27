/* 
 * File:   main.c
 * Author: Chris Hajduk
 *
 * Created on August 21, 2014, 11:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "GPS.h"
#include "main.h"
#include "HunterTruckAPI.h"
#include "debug.h"

#include "OutputCompare.h"

_FOSCSEL(FNOSC_FRC); // Internal FRC oscillator
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE);
_FWDT(FWDTEN_OFF & WDTPOST_PS2048 & WDTPRE_PR128); //32,128
/*
 * 
 */



int main(int argc, char** argv) {
    initTruck();
    while(TRUE){
        setThrottle(50);
        setSteering(-100);
//        setOCValue(1,LOWER_PWM);
//        setOCValue(2,UPPER_PWM);
//        background();
    }
    debug("DONE");
    return (EXIT_SUCCESS);
}

