//
// Created by wolle on 15.07.17.
//

#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "slave.h"

#define BUFLEN 64

void slave(int sock){

    struct sockaddr_in si_master;
    int siMasterLen = sizeof(si_master), recvLen;
    char buf[BUFLEN];
    memset(buf, 0, BUFLEN);

    bool looped = false;
    while(1){

        if((recvLen = recvfrom(sock, buf, BUFLEN, 0,
                (struct sockaddr*)&si_master, &siMasterLen)) > 0){

            if(looped){

                printf("%s", buf);

                looped = false;

            }else if(sendto(sock, buf, BUFLEN, 0,
                    (struct sockaddr*)&si_master, siMasterLen)){
                looped = true;
            }
        }

    }
}