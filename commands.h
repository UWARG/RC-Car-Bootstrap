/* 
 * File:   commands.h
 * Author: andrew
 *
 * Created on March 8, 2014, 3:17 AM
 */

#ifndef COMMANDS_H
#define	COMMANDS_H

#define DEBUG_TEST 0


//Multipart Commands

//Multipart Command Structs
typedef struct _newwaypointwrapper {
    long double longitude;  //TODO: Longitude and Latitude is bulky. If problems arise, change the format.
    long double latitude;
    float altitude;
    float radius; //Radius of turn
} NewWaypointWrapper;
#endif	/* COMMANDS_H */

