/*
 * File:   SPI.c
 * Author: Chris Hajduk
 *
 * Created on July 16, 2013, 7:23 PM
 */

#include <p33FJ256GP710A.h>
#include "SPI1.h"
/*
 * SPI uses 4 pins:
 * SDIx: Serial Data Input              --> RF7
 * SDOx: Serial Data Output             --> RF8
 * SCKx: Shift Clock Input/Output       --> RF6
 * SSx/FSYNCx: Active-Low slave select or Frame Synchronization --> RB2
 *
 */

void __attribute__((__interrupt__,no_auto_psv)) _SPI1Interrupt(void){
    SPI1STATbits.SPIROV = 0;
    IFS0bits.SPI1IF = 0;
    IFS0bits.SPI1EIF = 0;
}

void init_SPI1(){
    //Set interrupts
    IFS0bits.SPI1IF = 0;
    IEC0bits.SPI1IE = 0;

    SPI1BUF = 0;
    //Continue module operation in idle mode
    SPI1STATbits.SPISIDL = 1;
    //SPI clock controlled by this module
    SPI1CON1bits.DISSCK = 0;
    //Output pins are controlled by this module
    SPI1CON1bits.DISSDO = 0;
    //16/8 bit communication mode (1/0)
    SPI1CON1bits.MODE16 = 1; //16
    //Master mode(1)/Slave mode(0)
    SPI1CON1bits.MSTEN = 0; //Slave
    //Enable Slave Select
    SPI1CON1bits.SSEN = 0;
    //Sample Phase (end/middle)
    SPI1CON1bits.SMP = 0; //Sample the input at the end of the square wave
    //Clock Edge Select
    SPI1CON1bits.CKE = 0; //Output data changes from idle state to active clock state (1 is the opposite)
    //Clock Polarity
    SPI1CON1bits.CKP = 0; //Idle clock state is low, active clock state is high


    //Secondary Prescale (The prescale of the prescale)(3 bits)
    SPI1CON1bits.SPRE = 0; //8:1 prescale
    //Primary Prescale (The prescale of the clock) (2 bits)
    SPI1CON1bits.PPRE = 0; //64:1 prescale

    //Clear Receive Overflow
    SPI1STATbits.SPIROV = 0;

    //Enable SPI
    SPI1STATbits.SPIEN = 1;

    //Then write to the SPI1BUF


}