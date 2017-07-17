//
// Created by wolle on 15.07.17.
//

#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../sock.h"
#include "slave.h"

#define BUFLEN 2048

void slave(int sock){

    struct sockaddr_in si_master;
    int siMasterLen = sizeof(si_master), recvLen;
    char buf[BUFLEN];
    struct timespec timeFromMaster;
    int timeouts = 0;

    memset(buf, 0, BUFLEN);

    setReciveTimeout(sock, 13, 0);

    bool looped = false;
    while(1){

        if((recvLen = recvfrom(sock, (struct timespec*) &timeFromMaster, BUFLEN, 0,
                (struct sockaddr*)&si_master, &siMasterLen)) > 0){

            if(looped){

                //printf("%s\n", buf);
                printf("%ld:%ld\n", timeFromMaster.tv_sec, timeFromMaster.tv_nsec);
                fflush(stdout);
                looped = false;
                timeouts = 0;

            }else if(sendto(sock, (struct timespec*)&timeFromMaster, sizeof(timeFromMaster), 0,
                    (struct sockaddr*)&si_master, siMasterLen)){
                looped = true;

                printf("First: %ld:%ld\n", timeFromMaster.tv_sec, timeFromMaster.tv_nsec);
                fflush(stdout);
            }
        }else if(timeouts < 3){
            timeouts++;
            looped = false;
            printf("no message from master\n");
        }else{
            return;
        }

    }
}