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
void getPosition(long double* position){
    position[0] = GPS.longitude;
    position[1] = GPS.latitude;
}
char isGPSLocked(){
    return GPS.positionFix;
}
char getSatellites(){
    return GPS.satellites;
}
float getUTCTime(){
    return GPS.time;
}
char getHour(){
    return (char)((int)(GPS.time/10000) % 100);
}
char getMin(){
    return (char)((int)(GPS.time/100) % 100);
}
char getSec(){
    return (char)((int)GPS.time % 100);
}