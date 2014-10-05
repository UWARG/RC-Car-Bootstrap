/*
 * File:   GPS.c
 * Author: Chris Hajduk
 *
 * Created on August 24, 2014, 9:09 PM
 */

#include "InterchipDMA.h"
#include "SPI1.h"
#include "GPS.h"

extern GPSData GPS;

long double relativeLatitude = 0;
long double relativeLongitude = 0;
char GPSLock = 0;
static float lastGpsTime = 0.0;

void initGPS(){
    init_SPI1();
    init_DMA0();
}

long double getLatitude(){
    return GPS.latitude;
}

long double getLongitude(){
    return GPS.longitude;
}

int getHeading(){
    return GPS.heading;
}
float getSpeed(){
    return GPS.speed;
}
int getAltitude(){
    return GPS.altitude;
}
void getPosition(long double* position){ //must pass in an array[2] to hold position
    position[0] = GPS.longitude;         // puts lat in [0] and long in [1]
    position[1] = GPS.latitude;
}
char isGPSLocked(){   // returns 0 or 1 if locked or not
    return GPS.positionFix;
}
char getSatellites(){
    return GPS.satellites;
}
float getUTCTime(){
    float localTime = GPS.time;
    if (lastGpsTime > localTime) {
        localTime = lastGpsTime;
    }
    else {
        lastGpsTime = localTime;
    }
    return localTime;
}
char getHour(){
    float localTime = GPS.time;
    if (lastGpsTime > localTime) {
        localTime = lastGpsTime;
    }
    else {
        lastGpsTime = localTime;
    }
    return (char)((int)(localTime/10000) % 100);
}
char getMin(){
    float localTime = GPS.time;
    if (lastGpsTime > localTime) {
        localTime = lastGpsTime;
    }
    else {
        lastGpsTime = localTime;
    }
    return (char)((int)(localTime/100) % 100);
}
char getSec(){
    float localTime = GPS.time;
    if (lastGpsTime > localTime) {
        localTime = lastGpsTime;
    }
    else {
        lastGpsTime = localTime;
    }
    return (char)((long)localTime % 100);
}