/* 
 * File:   SPI.h
 * Author: Chris Hajduk
 *
 * Created on August 24, 2014, 8:08 PM
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

// Includes
#include "main.h"
    
//Function Handles

/*****************************************************************************
 * Function: void init_SPI1();
 *
 * Preconditions: None.
 *
 * Overview: Initializes the SPI1 interface. Originally meant to communicate
 *  with the GPS.
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_SPI1();


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

