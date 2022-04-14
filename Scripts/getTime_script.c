// Copyright 2022-2022 The MathWorks, Inc

#include <stdlib.h>            //exit_success, exit_failure
#include <time.h>              //clock_gettime()
#include <stdio.h>             //printf, perror
#include <stdint.h>            //uint32_t, uint64_t
#include "getTime.h"
#define NANO 1000000000L

/*
 * This program returns the current system clock time.
 * The time is printed in nanoseconds, on standard out.
 * 64-bit timestamp is stored as an  arr of [uint32 uint32], 
 * where arr[0] is the 32 least significant bits and 
 * arr[1] is the 32 most significant bits of the timestamp.
 * double inputPort is not used, added to match previous releases API
 * Return an int status.
 */

int findUnixTime(uint32_t* unixTime32, double inputPort) {
    struct timespec localUnixTime;   
    //Print error if attempted to compile on Windows
    #if defined(_WIN32)
    #error The Elapsed Time block does not support Windows. Supported on QNX and Linux.
    #endif   
    // Get system time
    int localUnixTimeStatus = clock_gettime(CLOCK_REALTIME, &localUnixTime);          
    if(localUnixTimeStatus == -1) {
      perror( "clock gettime" );
      return EXIT_FAILURE;
    }
    // Convert to nanoseconds
    uint64_t timeInNs = localUnixTime.tv_sec * NANO + localUnixTime.tv_nsec;
    printf("time as unix timestamp: %lu\n", timeInNs);
    // Get the 32 least significant bits
    unixTime32[0] = (uint32_t) timeInNs;               //32-lsb
    // Get the 32 most significant bits
    unixTime32[1] = (uint32_t) (timeInNs >> 32);       //32-msb
    printf("unix time as array: %u %u\n", unixTime32[0], unixTime32[1]);  
    return EXIT_SUCCESS;
}
