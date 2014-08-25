/*
 * File:   GPS.c
 * Author: Chris Hajduk
 *
 * Created on August 24, 2014, 9:09 PM
 */

#include "InterchipDMA.h"
#include "SPI1.h"
#include "GPS.h"

extern GPSData gpsData;

long double relativeLatitude = 0;
long double relativeLongitude = 0;
char GPSLock = 0;

void initGPS(){
    init_SPI1();
    init_DMA0();
}

//TODO: Functions to checek GPS status isGPSLocked, getPosition, getXYPosition, getHeading, getSpeed, etc

void getXYCoordinates(long double longitude, long double latitude, float* xyCoordinates){
    xyCoordinates[0] = getDistance(relativeLatitude, relativeLongitude, relativeLatitude, longitude);//Longitude relative to (0,0)
    xyCoordinates[1] = getDistance(relativeLatitude, relativeLongitude, latitude, relativeLongitude);
}

float getDistance(long double lat1, long double lon1, long double lat2, long double lon2){ //in meters
    long double dLat = deg2rad(lat2 - lat1);
    long double dLon = deg2rad(lon2 - lon1);

    float a = sin(dLat / 2) * sin(dLat / 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dLon / 2) * sin(dLon / 2);

    if ((dLat >= 0 && dLon >=0)||(dLat < 0 && dLon < 0)){
        return EARTH_RADIUS * (2 * atan2(sqrt(a),sqrt(1 - a))) * 1000;
    }
    else {
         return EARTH_RADIUS * (2 * atan2(sqrt(a),sqrt(1 - a))) * -1000;
    }
}