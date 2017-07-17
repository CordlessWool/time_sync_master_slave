//
// Created by wolle on 17.07.17.
//

#include "calc.h"

struct timespec getTimeDifference(struct timespec start, struct timespec end){

    struct timespec difference;

    difference.tv_nsec = end.tv_nsec - start.tv_nsec;
    difference.tv_sec = end.tv_sec - start.tv_sec;

    if(end.tv_nsec > start.tv_nsec){
        difference.tv_sec+1;
    }

    return difference;
}
