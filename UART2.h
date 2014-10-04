/* 
 * File:   UART.h
 * Author: Mitch
 *
 * Created on June 15, 2013, 2:52 PM
 */

#ifndef UART2_H
#define	UART2_H

#ifdef	__cplusplus
extern "C" {
#endif
    
// Includes
#include "main.h"

//Function Prototypes

/*****************************************************************************
 * Function: void InitUART2();
 *
 * Preconditions: None.
 *
 * Overview: Initializes the UART2 interface. This function was designed for
 *  initialization of the interface for debugging usage.
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void initUART2();

/*****************************************************************************
 * Function: void UART2_SendString(char *s);
 *
 * Preconditions: UART2 must have been initialized.
 *
 * Overview: Sends a string of characters specified by an array of char values.
 *  Note the char array does not need to represent characters, it can be any
 *  type of binary data.
 *
 *
 * Input: char *s -> pointer to the data to be transmitted.
 *
 * Output: None.
 *
 *****************************************************************************/
void UART2_SendString(char *s);

/*****************************************************************************
 * Function: void UART2_SendChar(char data);
 *
 * Preconditions: UART2 must have been initialized.
 *
 * Overview: Sends a single character (or byte of data) through the UART2 port.
 *
 *
 * Input: char data -> byte of data to be transmitted.
 *
 * Output: None.
 *
 *****************************************************************************/
void UART2_SendChar(char data);

#ifdef	__cplusplus
}
#endif

#endif	/* UART2_H */