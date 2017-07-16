//
// Created by wolle on 13.07.17.
//

#include <printf.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <zconf.h>
#include <time.h>
#include "../error.h"
#include "../sock.h"

#include "master.h"

#define BUFLEN 1500


void master(int sock, struct sockaddr_in si_me, struct Slaves *slaves){

    struct sockaddr_in si_slave, si_other;

    int siLen = sizeof(si_slave), recvLen;
    //char buf[BUFLEN];

    int timeToSleep = 10;
    int sleepTillNext;

    struct timespec currentTime, receiveTime;
    char timeStr[BUFLEN];

    bool loop = false;
    bool slaveMissResponse = false;

    while(1)
    {
        int counterSlave = (*slaves).counter;
        if(counterSlave > 0){
            printf("Sending slaves new Time\n");
            sleepTillNext = timeToSleep/counterSlave;
        }else{
            printf("No slaves registered");
            sleep(3);
        }
        for(int i = 0; i < counterSlave; i++){

            si_slave = slaves->slaves[i];


            printf("Known Slave %s:%d\n",
                   inet_ntoa(slaves->slaves[i].sin_addr),
                   ntohs(slaves->slaves[i].sin_port));

            if(clock_gettime(CLOCK_REALTIME, &currentTime)) {
                perror("clock_gettime()");
                return;
            }


            //snprintf(timeStr, BUFLEN, "%d:%d", (int)(currentTime.tv_sec), currentTime.tv_nsec);

            printf("%d:%d\n", receiveTime.tv_sec, receiveTime.tv_nsec);
            do {
                if (sendto(sock, (struct timespec*) &currentTime, BUFLEN, 0
                        , (struct sockaddr *) &si_slave, siLen) != -1) {

                    if(loop){

                        loop = false;

                    }else if ((recvLen = recvfrom(sock, (struct timespec*) &receiveTime, BUFLEN, 0
                            , (struct sockaddr *) &si_other, &siLen)) > 0) {
                            //TODO: prove if it is same slave
                        loop = true;
                        printf("%d:%d\n", receiveTime.tv_sec, receiveTime.tv_nsec);

                    }else if(!slaveMissResponse){
                        printf("slave is not responding and will remove after second request");
                        slaveMissResponse = true;
                        sleep(sleepTillNext);
                        loop = true;
                    }else if(slaveMissResponse){
                        printf("slave %s:%d was removed because of not responding"
                                , inet_ntoa(si_slave.sin_addr), ntohs(si_slave.sin_port));
                        removeSlaveByPos(slaves, i);
                        fflush(stdout);
                        slaveMissResponse = false;
                        loop = false;
                    }
                }
            }while(loop);


            sleep(sleepTillNext);

        }

        printf("\n\n");
        sleep(1);
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
        perror("setsockopt()");

    while(1){

        printf("\nwaiting for new slave...\n");
        fflush(stdout);

        if ((recvLen = recvfrom(sock, buf, BUFLEN, 0,
                                (struct sockaddr *) &si_slave, &siLen)) > 0)
        {








                //now reply the client with the same data
                if (sendto(sock, buf, recvLen, 0, (struct sockaddr *) &si_slave, siLen) >= 0) {
                    if(checkIfNewSlave(*slaves, &si_slave) == 0) {
                        //print details of the client/peer and the data received
                        printf("Added new slave: %s:%d\n",
                               inet_ntoa(si_slave.sin_addr), ntohs(si_slave.sin_port));
                        printf("Message from slave: %s\n", buf);
                        addSlave(slaves, &si_slave);
                    }else{
                        printf("Already registered slave: %s:%d\n",
                               inet_ntoa(si_slave.sin_addr), ntohs(si_slave.sin_port));
                    }
                }

        }
    }
}
