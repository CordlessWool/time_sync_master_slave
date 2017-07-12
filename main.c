#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <zconf.h>
#include "error.h"
#include "sock.h"
#include "master/master.h"

#define BUFLEN 512
#define PORT 5005


int main(char *argv[]) {
    printf("Hello, World!\n");

    struct sockaddr_in si_me, si_other, si_master;

    int sock, siLen = sizeof(si_other), recvLen;
    char buf[BUFLEN];

    //create udp socket
    if((sock=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
        die("Could not establish a socket");
    }

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind socket to port
    if(bind(sock, (struct sockaddr*)&si_me, sizeof(si_me)) == -1){
        die("Could not bind a socket to port");
    }

    if(isThereAMaster(sock, argv[0], PORT, si_master) == -1){
        printf("I am the master\n");
        master(sock, si_me, BUFLEN);
    }else{
        printf("I am a slave\n");
    }

    //keep listening for data


    close(sock);
    return 0;
}