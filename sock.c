//
// Created by wolle on 12.07.17.
//

#include "sock.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include "error.h"

#define BUFLEN 500




int setReciveTimeout(int sock, int sec, int usec){
    struct timeval timeout;
    timeout.tv_sec = sec;
    timeout.tv_usec = usec;

    if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) == -1){
        return -1;
    }

    return 0;
}


int isThereAMaster(int sock, char* broadcastIP, int port, struct sockaddr_in *si_master){

    struct sockaddr_in si_braod;
    si_braod.sin_addr.s_addr = *broadcastIP;
    si_braod.sin_family = AF_INET;
    si_braod.sin_port = htons(port);



    static const char hello[] = "hello, is there anybody?";
    char buf[BUFLEN];
    int recvLen, helloLen = sizeof(hello);

    if(sendto(sock, hello, helloLen, 0, (struct sockaddr*)&si_braod, sizeof(si_braod)) == -1){
        die("Could not send broadcast");
    }

    setReciveTimeout(sock, 7, 0);

    if((recvLen = recvfrom(sock, buf, BUFLEN, 0, (struct sockadd *)si_master, sizeof((*si_master)))) == -1){
        return -1;
    }

    return 0;

}

int addSlave(struct Slaves *slaves, struct sockaddr_in* si_slave){
    int counter = ++(*slaves).counter;
    (*slaves).slaves[counter] = *si_slave;
    return 0;
}
