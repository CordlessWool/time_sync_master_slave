//
// Created by wolle on 04.10.17.
//
#include <time.h>
#include <sched.h>
#include <stdio.h>
#include "gpio_setup.h"

int main(){

    struct sched_param sparam;
    sparam.sched_priority = 99;
    sched_setscheduler(0, SCHED_FIFO, &sparam);

    struct timespec currentTime;

    int fd = gpio_setup(4);

    while(1) {

        clock_gettime(CLOCK_REALTIME, &currentTime);
        if(currentTime.tv_nsec <= 1000){
            write(fd, "1", 1);
            //printf("1");
            usleep(500);
            write(fd, "0", 1);
            //printf("0");
            fflush(stdout);

        }
    }

    close(fd);

    return 0;

}