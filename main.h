/* 
 * File:   main.h
 * Author: Chris Hajduk
 *
 * Created on October 15, 2013, 8:14 PM
 *
 * This file contains all GLOBAL constants needed for the code.
 * Avoiding adding stuff here unless you really need to.
 *
 */

#ifndef MAIN_H
#define MAIN_H
//Include Libraries
#include <p33FJ256GP710A.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define constants for global use in the code
#define TRUE	1
#define FALSE	0

//Mathematical Constants
#define PI 3.14159265

//Basic Mathematical Conversions
#define deg2rad(DEG) ((DEG) * PI/180.0)
#define rad2deg(RAD) ((RAD) * 180.0/PI)

typedef enum{
    waitingToStartTimer,
    drivingTimer,
    NUMBER_OF_TIMERS,
} Timer;

typedef enum{
    waitingToStart,
    drivingForward,
    drivingBackward,
    turningRight,
    turningLeft,
} MoveState;

typedef enum{
    phase1,
    phase2,
} Task;


typedef enum { false, true } boolean;

#endif