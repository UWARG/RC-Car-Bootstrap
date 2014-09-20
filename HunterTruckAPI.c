/*
 * File:   HunterTruckAPI.c
 * Author: Chris Hajduk
 *
 * Created on August 24, 2014, 9:08 PM
 */

#include "debug.h"
#include "GPS.h"
#include "UART1.h"
#include "UART2.h"
#include "net.h"
#include "commands.h"
#include "HunterTruckAPI.h"
#include "StartupErrorCodes.h"

int lastCommandSentCode = 0;
float time = 0;
float lastTime = 0;
char sData = 0;
char tData = 0;

void initTruck(){
    //Setup Debugging Connection
    initUART1();

    //Check for any errors
    checkErrorCodes();

    //Setup GPS
    initGPS();

    //Setup Input and Output
    initPWM(0b11,0b11);
    PWMOutputCalibration(1,HUNTER_TRUCK_STEERING_SCALE_FACTOR, HUNTER_TRUCK_STEERING_OFFSET);
    PWMOutputCalibration(2,HUNTER_TRUCK_THROTTLE_SCALE_FACTOR, HUNTER_TRUCK_THROTTLE_OFFSET);

    setThrottle(0);
    setSteering(0);

    //Setup Datalink
    initDataLink();
}

void setSteering(int percent){
    //This is channel 1
    //Limit the range between -100% and 100%
    if (percent > 100)
        percent = 100;
    if (percent < -100)
        percent = -100;
    sData = percent; //Records the steering history
    setPWM(1,(int)(percent * 10.24));//Range: Percentage (-100/100) converted to -1024 to 1024
}

void setThrottle(int percent){
    //This is channel 2
    //Limit the range between 0% and 100%
    if (percent > 100)
        percent = 100;
    if (percent < -100)
        percent = -100;
    tData = percent; //Records the throttle history
    setPWM(2,(int)(percent * 10.24));//Range: Percentage (0/100) converted to -1024 to 1024
}

void background(){
    readDatalink();
    time = getUTCTime();
    writeDatalink(DATALINK_SEND_FREQUENCY);
    outboundBufferMaintenance();
    inboundBufferMaintenance();
}

void readDatalink(void){

    struct command* cmd = popCommand();
    if ( cmd ) {
        if (lastCommandSentCode == cmd->cmd){
            lastCommandSentCode++;
        }
        else{
            lastCommandSentCode = cmd->cmd * 100;
        }
        switch (cmd->cmd) {
            case DEBUG_TEST:             // Debugging command, writes to debug UART
                debug((char*) cmd->data);
                break;
            //TODO: Add commands here
            default:
                break;
        }
        destroyCommand( cmd );
    }

}
int writeDatalink(long frequency){

    if (time - lastTime > frequency) {
        lastTime = time;

        struct telem_block* statusData = getDebugTelemetryBlock();//createTelemetryBlock();

        if (statusData == 0){
            return 0;
        }
        
        statusData->lat = getLatitude();
        statusData->lon = getLongitude();
        statusData->millis = getUTCTime();
        statusData->groundSpeed = getSpeed();
        statusData->heading = getHeading();
        statusData->lastCommandSent = lastCommandSentCode;
        statusData->errorCodes = getErrorCodes();
        statusData->gpsStatus = (char)(getSatellites() + (isGPSLocked() << 4));
        statusData->steeringSetpoint = getPWM(1);
        statusData->throttleSetpoint = getPWM(2);
        statusData->steeringOutput = sData;
        statusData->throttleOutput = tData;


        if (BLOCKING_MODE) {
            sendTelemetryBlock(statusData);
            destroyTelemetryBlock(statusData);
        } else {
            return pushOutboundTelemetryQueue(statusData);
        }
    }
    else if (time < lastTime){
        lastTime = time;
        return 0;
    }
    return 0;
}