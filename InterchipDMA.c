/*
 * File:   InterchipDMA.c
 * Author: Chris Hajduk
 *
 * Created on February 2, 2014, 2:10 PM
 */
#include <p33FJ256GP710A.h>
#include "InterchipDMA.h"

char newGPSDataAvailable = 0;
GPSData GPS __attribute__((space(dma)));
/*
 *
 */

void __attribute__((__interrupt__, no_auto_psv)) _DMA0Interrupt(void){
    newGPSDataAvailable = 1;
    IFS0bits.DMA0IF = 0;// Clear the DMA0 Interrupt Flag
}
void init_DMA0(){
    IFS0bits.DMA0IF = 0;
    IEC0bits.DMA0IE = 1;

    DMA0CONbits.AMODE = 0b00; //Register Indirect Mode
    DMA0CONbits.DIR = 0; //Transfer from SPI to DSPRAM
    DMA0CONbits.MODE = 0b00; //Transfer continuously
    DMA0CONbits.SIZE = 1; //Transfer bytes (8 bits)
    DMA0STA = __builtin_dmaoffset(&GPS); //Primary Transfer Buffer
    DMA0PAD = (volatile unsigned int) &SPI1BUF; //Peripheral Address
    DMA0CNT = sizeof(GPSData) - 1; //+1 for checksum //DMA Transfer Count Length
    DMA0REQ = 0b0001010; //IRQ code for SPI1
    DMA0CONbits.CHEN = 1; //Enable the channel
}
