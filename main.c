/* 
 * File:   main.c
 * Author: Chris Hajduk
 *
 * Created on August 21, 2014, 11:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GPS.h"
#include "main.h"
#include "HunterTruckAPI.h"
#include "debug.h"

#include "OutputCompare.h"
#include "InterchipDMA.h"
#include "PWM.h"

_FOSCSEL(FNOSC_FRC); // Internal FRC oscillator
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE);
_FWDT(FWDTEN_OFF & WDTPOST_PS2048 & WDTPRE_PR128); //32,128
/*
 * 
 */


/*
 * Prototypes
 */
float distance(float, float, float, float);
void driveForward(float, float);
void driveBackward(float, float);
void turnRight(float, float, float);
void driveStop();
void startTimer(Timer, float);
boolean isExpiredTimer(Timer);
unsigned long seconds();
void updateSeconds();
void delay(int);


/*
 * GPS Functions
 */
#define TO_RAD (PI/180)
#define R_EARTH 6371 //KM

float distance(float lat1, float long1, float lat2, float long2)
{
    float dlat, dlong;
    dlat = (lat1- lat2) * TO_RAD;
    dlong = (long1 - long2) * TO_RAD;
    lat1 *= TO_RAD;
    lat2 *= TO_RAD;
    long1 *= TO_RAD;
    long2 *= TO_RAD;

    float a;
    a = sin(dlat/2) * sin(dlat/2) + cos(lat1)*cos(lat2)
        * sin(dlong/2) * sin(dlong/2);
    float c;
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    c *= -1000;
    float d;
    d = R_EARTH * c;
    return d;
}

/*
* Move Functions
*/
void driveForward(float time, float throttlePercent)
{
    setThrottle(throttlePercent);
    setSteering(0);
    startTimer(drivingTimer, time);
}

void driveBackward(float time, float throttlePercent)
{
    setThrottle(-1*throttlePercent);
    setSteering(0);
    startTimer(drivingTimer, time);
}

void turn(float time, float throttlePercent, float steeringPercent)
{
    setThrottle(throttlePercent);
    setSteering(steeringPercent);
    startTimer(drivingTimer, time);
}
void driveStop()
{
    setThrottle(0);
}


/*******
* Timers
********/
double expiryTime[NUMBER_OF_TIMERS];
boolean expiredTimers[NUMBER_OF_TIMERS];

// Start a timer with that runs for lenght seconds
void startTimer(Timer timer, float length)
{
    expiryTime[timer] = length + seconds();
}

// returns true if the timer is expired
boolean isExpiredTimer(Timer timer)
{
    return (seconds() >= expiryTime[timer]);
}
/*
Timer areTimersExpired()
{
    for (int i = 0; i <= NUMBER_OF_TIMERS; i++)
    {
        if(isExpiredTimer(Timer(i)))
        {
            expiredTimers[i] = true;
        }
    }
}
*/

void delay(int delayTime){
    int waitTime = seconds() + delayTime;
    while (seconds() <= waitTime)
    {
      background();  
    }
}
/*********
*Time Functions
*
**********/


//unsigned long seconds = 0;

unsigned long seconds()
{
    return ((int)getSec() + (int)getMin() * 60);
}

/*
void updateSeconds()
{
    seconds = seconds();
}
*/




MoveState moveState = waitingToStart;

Task task = phase1;

int main(int argc, char** argv) {
    initTruck();
    while(true){
        //This is how you move the car. Throttle goes from -100% to 100%. Steering goes from -100 to 100%.
        setThrottle(0);   //Note that the first -20%/20% is a safety buffer region. Anything less than 20% is equivalent to no throttle.
        setSteering(0);

        switch (task)
        {
            case(phase1):
                driveForward(10,50);
                delay(10);

                driveStop();
                delay(3);

                driveBackward(10,50);
                delay(10);

                driveStop();
                delay(3);

                turn(10, 50, 40);
                delay(10);

                driveStop();
                delay(3);

                turn(10, 50, -40);
                delay(10);
                break;

            case(phase2):
                delay(2); //delay on startup
                boolean Done = false;
                float distanceToTravel = 10; //in meters
                while(!Done)
                {
                    moveState = waitingToStart;
                    long double pos[2];
                    float startPos[2];
                    float distTravelled;

                     switch (moveState)
                     {
                         case(waitingToStart):
                             if (isGPSLocked())
                             {
                                moveState = drivingForward;
                                driveForward(10, 50);

                                getPosition(pos);
                                startPos[0] = pos[0];
                                startPos[1] = pos[1];
                             }
                             break;

                         case(drivingForward):
                            getPosition(pos);
                            distTravelled = distance(startPos[0], startPos[1], pos[0], pos[1]);
                            if(distTravelled >= distanceToTravel)
                            {
                                driveStop();
                                delay(2);
                                moveState = drivingBackward;
                                getPosition(pos);
                                startPos[0] = pos[0];
                                startPos[1] = pos[1];
                                driveBackward(10, 50);
                            }
                            break;

                         case(drivingBackward):
                            getPosition(pos);
                            distTravelled = distance(startPos[0], startPos[1], pos[0], pos[1]);
                            if(distTravelled >= distanceToTravel)
                            {
                                Done = true;
                            }

                     }

                     background();
                }

            case (phase3):
                //statement
                break;

        }

        driveStop();

        while(true);

//        This is an example of how you can print the GPS time to the debugging interface.
//        char str[16];
//        sprintf((char *)&str, "GPS: %f", GPS.time);
//        debug((char *)&str);

        // updateSeconds();
        background();
    }
    return (EXIT_SUCCESS);
}
