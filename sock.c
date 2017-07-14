//
// Created by wolle on 12.07.17.
//

#include "sock.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <zconf.h>
#include <arpa/inet.h>
#include <string.h>
#include "error.h"

#define BUFLEN 50


int setReciveTimeout(int sock, int sec, int usec){
    struct timeval timeout;
    timeout.tv_sec = sec;
    timeout.tv_usec = usec;

    if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) == -1){
        return -1;
    }

    return 0;
}
int allowBroadcast(int sock, int allow){
    return setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &allow, sizeof(allow));
}

int isThereAMaster(int sock, char* broadcastIP, int port, struct sockaddr_in *si_master){

    struct sockaddr_in si_braod, si_test;
    si_braod.sin_addr.s_addr = inet_addr((broadcastIP));//htonl(INADDR_BROADCAST);
    si_braod.sin_family = AF_INET;
    si_braod.sin_port = htons(port);

//    printf(broadcastIP);

    static const char hello[] = "hello, is there anybody?";
    char buf[BUFLEN];
    memset(buf, 0, sizeof buf);
    int recvLen, helloLen = sizeof(hello);

    //setReciveTimeout(sock, 7, 0);

    //create udp socket
    /*if((sock=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
        die("Could not establish a socket");
    }

    //bind socket to port
    if(bind(sock, (struct sockaddr*)&si_, sizeof(si_braod)) == -1){
        die("Could not bind a socket to port");
    }*/

    if(allowBroadcast(sock, 1) == -1){
        die("allowBroadcast()");
    }


/*    if(sendto(sock, hello, helloLen, 0, (struct sockaddr*)&si_braod, sizeof(si_braod)) == -1){
        die("sendto()");
    }
*/
    if(allowBroadcast(sock, 0) == -1){
        die("allowBroadcast()");
    }
    printf("Waiting for master response\n");


//    for(int i = 0; i<200; i++) {
        recvLen = recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr *) &si_test, sizeof(si_test));
//        recvLen = recvfrom(sock, buf, BUFLEN, 0, (struct sockadd *)&si_test, sizeof(si_test));
        if (recvLen > 0) {
            //print details of the client/peer and the data received
            //printf("Received packet from %s:%d\n", inet_ntoa((*si_test).sin_addr), ntohs((*si_test).sin_port));
            //printf("Data: %s\n", buf);
            //close(sock);
            //return 0;
        } else if (recvLen) {
            //print details of the client/peer and the data received

            //return -1;
        }
//    }

    printf("Received packet from %s:%d\n", inet_ntoa((si_test).sin_addr), ntohs((si_test).sin_port));
            printf("Data: %s\n", buf);
            printf("%d\n", recvLen);
            close(sock);

    return 0;

}




int addSlave(struct Slaves *slaves, struct sockaddr_in* si_slave){
    int counter = ++(*slaves).counter;
    (*slaves).slaves[counter] = *si_slave;
    return 0;
}
