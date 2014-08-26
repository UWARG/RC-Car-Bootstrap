/* 
 * File:   UART.h
 * Author: Mitch
 *
 * Created on June 15, 2013, 2:52 PM
 */

#ifndef UART_H
#define	UART_H
#endif	/* UART_H */

//Function Prototypes

/*****************************************************************************
 * Function: void initUART1();
 *
 * Preconditions: None.
 *
 * Overview: Initializes the UART1 interface. This function was designed for
 *  initialization of the interface for debugging usage.
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void initUART1();

/*****************************************************************************
 * Function: void UART1_SendString(char *s);
 *
 * Preconditions: UART1 must have been initialized.
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
void UART1_SendChar(char data);

/*****************************************************************************
 * Function: void UART1_SendChar(char data);
 *
 * Preconditions: UART1 must have been initialized.
 *
 * Overview: Sends a single character (or byte of data) through the UART1 port.
 *
 *
 * Input: char data -> byte of data to be transmitted.
 *
 * Output: None.
 *
 *****************************************************************************/
void UART1_SendString(char *s);
