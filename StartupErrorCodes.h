/* 
 * File:   StartupErrorCodes.h
 * Author: Chris Hajduk
 *
 * Created on October 15, 2013, 8:33 PM
 */

/*****************************************************************************
 * Function: void checkErrorCodes();
 *
 * Preconditions: None, but if debugging is initialized, the error codes will be
 *  output there.
 *
 * Overview: Checks what caused the last chip reset.
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void checkErrorCodes();

/*****************************************************************************
 * Function: unsigned int getErrorCodes();
 *
 * Preconditions: None.
 *
 * Overview: Provides a series of boolean values (bits within the integer)
 *          representing the errors that cause the last chip reset.
 *
 * Input: None.
 *
 * Output: unsigned int -> bits representing each possible error on start up.
 *
 *****************************************************************************/
unsigned int getErrorCodes();
