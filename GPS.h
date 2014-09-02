/* 
 * File:   GPS.h
 * Author: Chris Hajduk
 *
 * Created on August 24, 2014, 10:00 PM
 */

#ifndef GPS_H
#define	GPS_H

#ifdef	__cplusplus
extern "C" {
#endif

//Includes
#include "main.h"

// Definitions
#define EARTH_RADIUS 6378.137

// Function Prototypes
/*****************************************************************************
 * Function: void initGPS();
 *
 * Preconditions: None.
 *
 * Overview: Initializes the SPI1 and DMA0 interfaces to communicate with the GPS.
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void initGPS();

/*****************************************************************************
 * Function: getXYCoordinates(long double longitude, long double latitude, float* xyCoordinates);
 *
 * Preconditions: None.
 *
 * Overview: Uses the getDistance function to create an xy coordinate system
 * reference to a relative longitude and latitude (which is [0,0] on the x/y
 * plane). The relative coordinates can be set using the setRelativeAnchor
 * function.
 *
 * Input: long double latitude -> The latitude of the position.
 *        long double longitude -> The longitude of the position.
 *        float* xyCoordinates -> The return array (will be overwritten when
 *           function is called).
 * Output: None.
 *
 *****************************************************************************/
void getXYCoordinates(long double longitude, long double latitude, float* xyCoordinates);

/*****************************************************************************
 * Function: float getDistance(long double lat1, long double lon1, long double lat2, long double lon2);
 *
 * Preconditions: None.
 *
 * Overview: Calculates the distance between two longitude and latitude points
 *
 * Input: long double lat1 -> The latitude of the first point.
 *        long double lon1 -> The longitude of the first point.
 *        long double lat2 -> The latitude of the second point.
 *        long double lon2 -> The longitude of the second point.
 * Output: float -> The distance between the two points in meters.
 *
 *****************************************************************************/
float getDistance(long double lat1, long double lon1, long double lat2, long double lon2);

/*****************************************************************************
 * Function: void setRelativeAnchor(long double longitude, long double latitude);
 *
 * Preconditions: None.
 *
 * Overview: Sets the origin for the XY coordinate system. Used to calculate the
 *      X-Y coordinates of longitude-latitude points.
 *
 * Input: long double longitude -> The longitude of the anchor (0,0).
 *        long double latitude -> The longitude of the anchor (0,0).
 *
 * Output: None.
 *
 *****************************************************************************/
void setRelativeAnchor(long double longitude, long double latitude);

/*****************************************************************************
 * Function: int getLatitude();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the latitude position of the device.
 *
 * Input: None.
 *
 * Output: iint -> The latitude value (in degrees).
 *
 *****************************************************************************/
long double getLatitude();

/*****************************************************************************
 * Function: int getLongitude();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the longitude position of the device.
 *
 * Input: None.
 *
 * Output: long double -> The longitude value (in degrees)
 *
 *****************************************************************************/
long double getLongitude();

/*****************************************************************************
 * Function: int getHeading();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the real (not magnetic) heading of the GPS.
 *
 * Input: None.
 *
 * Output: long double -> The heading in degrees.
 *
 *****************************************************************************/
int getHeading();

/*****************************************************************************
 * Function: int getSpeed();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the speed of the vehicle in m/s.
 *
 * Input: None.
 *
 * Output: int -> The speed in meters per second.
 *
 *****************************************************************************/
float getSpeed();

/*****************************************************************************
 * Function: int getAltitude();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the altitude above the mean sea level in meters.
 *
 * Input: None.
 *
 * Output: int -> The altitude above MSL in meters.
 *
 *****************************************************************************/
int getAltitude();

/*****************************************************************************
 * Function: void getPosition(long double* position);
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Latitude and longitude position of the vehicle.
 *
 * Input: long double* position -> An array (preferably empty).
 *      Returns the longitude and latitude in this array. Note any contents will
 *      be overwritten.
 *
 * Output: None.
 *
 *****************************************************************************/
void getPosition(long double* position);

/*****************************************************************************
 * Function: void getXYPosition(float* position);
 *
 * Preconditions: GPS should be initialized for valid data. A relative longitude
 *          and latitude should be picked.
 *
 * Overview: XY position of the vehicle relative to a predefined point.
 *
 * Input: long double* position -> An array (preferably empty).
 *      Returns the XY coordinates in this array. Note any contents will
 *      be overwritten.
 *
 * Output: None.
 *
 *****************************************************************************/
void getXYPosition(float* position);

/*****************************************************************************
 * Function: char isGPSLocked();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Indicates if the GPS system is active and "locked on".
 *
 * Input: None.
 *
 * Output: char -> The status of the GPS lock.
 *                  0 = No lock, 1 = GPS Lock, 2 = DGPS Lock
 *
 *****************************************************************************/
char isGPSLocked();

/*****************************************************************************
 * Function: char getSatellites();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Indicates the number of satellites the GPS is currently connected to.
 *
 * Input: None.
 *
 * Output: char -> The number of satellites the GPS is connected to.
 *
 *****************************************************************************/
char getSatellites();

/*****************************************************************************
 * Function: float getUTCTime();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the UTC time in a 24-hour floating point representation of
 *          the time(HHMMSS.SSSS).
 *
 * Input: None.
 *
 * Output: float -> the UTC time.
 *
 *****************************************************************************/
float getUTCTime();

/*****************************************************************************
 * Function: float getHour();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the current hour of Greenwhich Mean Time.
 *
 * Input: None.
 *
 * Output: char -> the hour ranging from 0-23.
 *
 *****************************************************************************/
char getHour();

/*****************************************************************************
 * Function: float getMin();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the current minute of Greenwhich Mean Time.
 *
 * Input: None.
 *
 * Output: char -> the minutes ranging from 0-59.
 *
 *****************************************************************************/
char getMin();

/*****************************************************************************
 * Function: float getSec();
 *
 * Preconditions: GPS should be initialized for valid data.
 *
 * Overview: Returns the current second of Greenwhich Mean Time.
 *
 * Input: None.
 *
 * Output: char -> the seconds ranging from 0-59.
 *
 *****************************************************************************/
char getSec();

#ifdef	__cplusplus
}
#endif

#endif	/* GPS_H */

