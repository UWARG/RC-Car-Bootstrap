/*
 * File:   HunterTruckAPI.c
 * Author: Chris Hajduk
 *
 * Created on August 24, 2014, 9:08 PM
 */

#include "PWM.h"
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

void initTruck(){
    initGPS();
    initUART1();
    initUART2();
    initPWM(2,2);
    initDataLink();
    checkErrorCodes();
}

void setSteering(int percent){
    //This is channel 1
    setPWM(1,(int)(percent * 10.24));//Range: Percentage (-100/100) converted to -1024 to 1024
}

void setThrottle(int percent){
    //This is channel 2
    percent -= 50;
    setPWM(2,(int)(percent * 10.24/2));//Range: Percentage (0-100) converted to -1024 to 1024
}

void background(){
    readDatalink();
    time = getUTCTime();
    writeDatalink(DATALINK_SEND_FREQUENCY);
    
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
            default:
                break;
        }
        destroyCommand( cmd );
    }

}
int writeDatalink(long frequency){

    if (time - lastTime > frequency) {
        lastTime = time;
    }
    else if (time < lastTime){
        lastTime = time;
    }

        struct telem_block* statusData = createTelemetryBlock();

        statusData->lat = getLatitude();
        statusData->lon = getLongitude();
        statusData->millis = getUTCTime();
        statusData->heading = getHeading();
        statusData->groundSpeed = getSpeed();
//        statusData->headingSetpoint = sp_Heading;
//        statusData->throttleSetpoint = (int) ((float) (sp_ThrottleRate - 454) / (890 - 454)*100);
//        statusData->headingOutput = sp_Heading;
//        statusData->throttleOutput = (int) ((float) (sp_ThrottleRate - 454) / (890 - 454)*100);
        statusData->lastCommandSent = lastCommandSentCode;
        statusData->errorCodes = getErrorCodes();
        statusData->gpsStatus = getSatellites() + (isGPSLocked() << 4);


        if (BLOCKING_MODE) {
            sendTelemetryBlock(statusData);
            destroyTelemetryBlock(statusData);
        } else {
            return pushOutboundTelemetryQueue(statusData);
        }
    }