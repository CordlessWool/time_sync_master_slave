//
// Created by wolle on 13.07.17.
//

#include <printf.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "master.h"
#include "../error.h"



int master(int sock, struct sockaddr_in si_me, int BUFLEN){

    struct sockaddr_in si_other;

    int siLen = sizeof(si_other), recvLen;
    char buf[BUFLEN];

    while(1)
    {
        printf("Waiting for data...");
        fflush(stdout);

        //try to receive some data, this is a blocking call
        if ((recvLen = recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &siLen)) == -1)
        {
            die("recvfrom()");
        }

        //print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n" , buf);

        //now reply the client with the same data
        if (sendto(sock, buf, recvLen, 0, (struct sockaddr*) &si_other, siLen) == -1)
        {
            die("sendto()");
        }
    }

}