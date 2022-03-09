// Copyright 2022-2022 The MathWorks, Inc

#include <stdint.h>          // uint32_t, uint64_t
#include <stdio.h>           // printf
#include <inttypes.h>        // PRIu64
#include "findDelta.h"

/*
 * This program calculates delta between two timestamps in nanoseconds.
 * If only one timestamp is passed and the other input is grounded (= [0 0])
 * the program returns the timestamp in nanoseconds.
 * 64-bit timestamp is stored as an  arr of [uint32 uint32], 
 * where arr[0] is the 32 least significant bits and 
 * arr[1] is the 32 most significant bits of the timestamp.
 * Delta is returned as double.
 */
double findDelta(const uint32_t* timestamp1, const uint32_t* timestamp2) {
    // Construct a 64-bit timestamp from each of the uint32_t* timestamps
    uint64_t ts1 = (uint64_t)timestamp1[1] << 32 | timestamp1[0];
    uint64_t ts2 = (uint64_t)timestamp2[1] << 32 | timestamp2[0];
    double delta;
    // Find delta
    delta = ts1 - ts2;
    printf("ts1 == %" PRIu64 ", ts2 == %" PRIu64 ", delta == %f\n", ts1, ts2, delta);
    return delta;
}