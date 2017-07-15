//
// Created by wolle on 15.07.17.
//

#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include "slave.h"

#define BUFLEN 64

void slave(int sock){

    struct sockaddr_in si_master;
    int recvLen, siMasterLen = sizeof(si_master);
    char buf[BUFLEN];

    bool looped = false;
    while(1){

        if((recvLen = recvfrom(sock, buf, BUFLEN, 0,
                (struct sockaddr*)&si_master, &siMasterLen)) > 0){


            if(looped){

                printf(buf);

                looped = false;

            }else if(sendto(sock, buf, BUFLEN, 0,
                    (struct sockaddr*)&si_master, &siMasterLen)){
                looped = true;
            }
        }

    }
}