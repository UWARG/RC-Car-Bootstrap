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
extern char newGPSDataAvailable;

long double relativeLatitude = 0;
long double relativeLongitude = 0;
char GPSLock = 0;

void initGPS(){
    init_SPI1();
    init_DMA0();
}

void getXYCoordinates(long double longitude, long double latitude, float* xyCoordinates){
    //NOT INCLUDED IN FINAL PROJECT
    xyCoordinates[0] = getDistance(relativeLatitude, relativeLongitude, relativeLatitude, longitude);//Longitude relative to (0,0)
    xyCoordinates[1] = getDistance(relativeLatitude, relativeLongitude, latitude, relativeLongitude);
}

float getDistance(long double lat1, long double lon1, long double lat2, long double lon2){ //in meters
    ///NOT INCLUDED IN FINAL PROJECT
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

void setRelativeAnchor(long double longitude, long double latitude){
    //NOT INCLUDED IN FINAL PROJECT
    relativeLatitude = latitude;
    relativeLongitude = longitude;
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
void getXYPosition(float* position){
    getXYCoordinates(GPS.longitude, GPS.latitude, position);
}
char isGPSLocked(){
    return GPS.positionFix;
}
char getSatellites(){
    return GPS.satellites;
}
float getUTCTime(){
    if (newGPSDataAvailable){
        return GPS.time;
    }
    else
        return 0;
}
char getHour(){
    return (char)((int)(GPS.time/10000) % 100);
}
char getMin(){
    return (char)((int)(GPS.time/100) % 100);
}
char getSec(){
    return (char)((int)(GPS.time) % 100);
}