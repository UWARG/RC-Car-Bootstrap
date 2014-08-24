/*
 * File:   debug.c
 *
 * Created on August 24, 2014, 05:38 PM
 */
#include "StringUtils.h"
#include "UART2.h"

void error(char* message){
    char* errorMessage = concat(concat("[error]", message),"/n");
    UART2_SendString(errorMessage);
    free(errorMessage);
}

void warning(char* message){
    char* warningMessage = concat(concat("[warning]", message),"/n");
    UART2_SendString(warningMessage);
    free(warningMessage);
}

void debug(char* message){
    UART2_SendString(message);
}