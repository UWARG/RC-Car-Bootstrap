/* 
 * File:   HunterTruckAPI.h
 * Author: Chris Hajduk
 *
 * Created on August 26, 2014, 2:48 PM
 */

#ifndef HUNTERTRUCKAPI_H
#define	HUNTERTRUCKAPI_H

#ifdef	__cplusplus
extern "C" {
#endif

//Includes
#include "OutputCompare.h"
#include "PWM.h"

//Definitions
#define HUNTER_TRUCK_STEERING_SCALE_FACTOR ((float)(UPPER_PWM - MIDDLE_PWM)/MAX_PWM * 0.8)
#define HUNTER_TRUCK_STEERING_OFFSET MIDDLE_PWM
#define HUNTER_TRUCK_THROTTLE_SCALE_FACTOR ((float)(UPPER_PWM - MIDDLE_PWM)/MAX_PWM * 0.8)
#define HUNTER_TRUCK_THROTTLE_OFFSET MIDDLE_PWM + 0//72//18


//Function Prototypes

/*****************************************************************************
 * Function: void initTruck();
 *
 * Preconditions: None.
 *
 * Overview: Initializes all necessary components for this project.
 *
 * Input: None.
 *
 * Output: None.
 *
 ****************************************************************************/
void initTruck();

/*****************************************************************************
 * Function: void setSteering(int percent);
 *
 * Preconditions: The required PWM channel must be initialized (channel 1).
 *
 * Overview: Controls the steering of the car as a percentage. 100 is full right,
 *      -100 is full left. 0 is the middle.
 *
 * Input: int percent -> The percentage representing the direction the front
 *                      (steering) wheels are pointing.
 *
 * Output: None.
 *
 ****************************************************************************/
void setSteering(int percent);

/*****************************************************************************
 * Function: void setThrottle(int percent);
 *
 * Preconditions: The required PWM channel must be initialized (channel 2).
 *
 * Overview: Controls the throttle of the car as a percentage. 100 is full throttle.
 *          0 is no throttle.
 *
 * Input: int percent -> The percentage to throttle the motor.
 *
 * Output: None.
 *
 ****************************************************************************/
void setThrottle(int percent);

/*****************************************************************************
 * Function: void background();
 *
 * Preconditions: None.
 *
 * Overview: A series of preconfigured background functions needed to be
 *              completed each program cycle.
 *
 * Input: None.
 *
 * Output: None.
 *
 ****************************************************************************/
void background();

/*****************************************************************************
 * Function: void readDatalink(void);
 *
 * Preconditions: The datalink must have been initialized.
 *
 * Overview: Reads any commands recieved from the ground station, and executes
 *          the corresponding functions.
 *
 * Input: None.
 *
 * Output: unsigned char -> the last command received.
 *
 ****************************************************************************/
unsigned char readDatalink(void);

/*****************************************************************************
 * Function: int writeDatalink(long frequency);
 *
 * Preconditions: The datalink must have been initialized.
 *
 * Overview: Writes predetermined data to the datalink at a defined frequency.
 *
 * Input: long frequency -> The rate at which the datalink should send data in seconds.
 *
 * Output: None.
 *
 ****************************************************************************/
int writeDatalink(float frequency);

/*****************************************************************************
 * Function: void setDebugChar(char dChar);
 *
 * Preconditions: None
 *
 * Overview: Set a char to send back next time around
 *
 * Input: char dChar -> The the debug char to send back
 *
 * Output: None.
 *
 ****************************************************************************/
void setDebugChar(char dChar);

/*****************************************************************************
 * Function: void setDebugInt(int dInt);
 *
 * Preconditions: None
 *
 * Overview: Set a int to send back next time around
 *
 * Input: int dInt -> The the debug int to send back
 *
 * Output: None.
 *
 ****************************************************************************/
void setDebugInt(int dInt);

/*****************************************************************************
 * Function: void setDebugFloat(float dFloat);
 *
 * Preconditions: None
 *
 * Overview: Set a float to send back next time around
 *
 * Input: float dFloat -> The the debug float to send back
 *
 * Output: None.
 *
 ****************************************************************************/
void setDebugFloat(float dFloat);

#ifdef	__cplusplus
}
#endif

#endif	/* HUNTERTRUCKAPI_H */

