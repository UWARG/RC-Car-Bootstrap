/* 
 * File:   InterchipDMA.h
 * Author: Chris Hajduk
 *
 * Created on February 2, 2014, 2:10 PM
 */

#ifndef INTERCHIPDMA_H
#define	INTERCHIPDMA_H

#ifdef	__cplusplus
extern "C" {
#endif

// Includes
#include "main.h"

// Definitions
typedef struct _GPSData {
    long double latitude;  //8 Bytes
    long double longitude; //8 Bytes
    float time;     //4 Bytes
    float speed;
    int altitude;
    int heading;
    char satellites;    //1 Byte
    char positionFix;
} GPSData;

extern GPSData GPS;

// Function Prototypes

/*****************************************************************************
 * Function: void init_DMA0();
 *
 * Preconditions: None.
 *
 * Overview: Initializes the primary Direct Memory Access module for continuous
 *  GPS data transmission. See the "AutoGPS" project for the corresponding GPS
 *  code.
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_DMA0();

#ifdef	__cplusplus
}
#endif

#endif	/* INTERCHIPDMA_H */

