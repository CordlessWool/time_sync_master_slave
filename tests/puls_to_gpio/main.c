//
// Created by wolle on 04.10.17.
//
#include <time.h>
#include "gpio_setup.h"

int main(){

    struct timespec currentTime;

    int fd = gpio_setup(4);

    while(1) {

        clock_gettime(CLOCK_REALTIME, &currentTime);
        if(currentTime.tv_nsec <= 1000){
            write(fd, "1", 1);
            usleep(100);
            write(fd, "0", 1);
        }
    }

    return 0;

}