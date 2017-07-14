//
// Created by wolle on 13.07.17.
//

#include <printf.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "master.h"
#include "../error.h"
#include "../sock.h"

#define BUFLEN 512


int master(int sock, struct sockaddr_in si_me){

    struct sockaddr_in si_other;

    int siLen = sizeof(si_other), recvLen;
    char buf[BUFLEN];

    while(1)
    {
        //printf("Waiting for data...");
        fflush(stdout);

        //try to receive some data, this is a blocking call
        if ((recvLen = recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &siLen)) > 0)
        {
                //die("recvfrom()");


            //print details of the client/peer and the data received
            printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
            printf("Data: %s\n" , buf);

            //now reply the client with the same data
            if (sendto(sock, buf, recvLen, 0, (struct sockaddr*) &si_other, siLen) == -1)
            {
                //die("sendto()");
            }
        }
    }

}


void* waitingForSlaves(void *data){
    struct Slaves *slaves =  (struct Slaves*) data;

    struct sockaddr_in si_me, si_slave;

    int sock, siLen = sizeof(si_slave), recvLen;
    char buf[BUFLEN];

    //create udp socket
    if((sock=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
        die("socket()");
    }

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons((*slaves).registerPort);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);


    //bind socket to port
    if(bind(sock, (struct sockaddr*)&si_me, sizeof(si_me)) == -1){
        die("Could not bind a socket to port");
    }

     /* Set socket to allow broadcast */
    if (allowBroadcast(sock, 1) < 0)
        perror("setsockopt() failed");

    while(1){

        printf("waiting for new slave...");

        if ((recvLen = recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr *) &si_slave, &siLen)) > 0)
        {


            //print details of the client/peer and the data received
            printf("Received packet from %s:%d\n", inet_ntoa(si_slave.sin_addr), ntohs(si_slave.sin_port));
            printf("Data: %s\n" , buf);

            //now reply the client with the same data
            if (sendto(sock, buf, recvLen, 0, (struct sockaddr*) &si_slave, siLen) >= 0)
            {
                addSlave(slaves, &si_slave);
            }
        }
    }
}