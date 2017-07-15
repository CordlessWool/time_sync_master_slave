#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <zconf.h>
#include <pthread.h>
#include <string.h>
#include "error.h"
#include "sock.h"
#include "master/master.h"
#include "slave/slave.h"

#define BUFLEN 64
#define PORT 5005
#define REGIST_PORT 4004

int main(int argc, char **argv) {
    printf("Hello, World!\n");
    printf("%s", argv[1]);

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
    while(1) {
        if (isThereAMaster(sock, argv[1], REGIST_PORT, &si_master) == -1) {

            pthread_t thread;

            struct Slaves slaves;
            slaves.slaves[50];
            memset(slaves.slaves, 0, 50);
            slaves.max = 50;
            slaves.counter = 0;
            slaves.registerPort = REGIST_PORT;

            pthread_create(&thread, NULL, &waitingForSlaves, (void *) (&slaves));

            printf("I am the master\n");
            master(sock, si_me, &slaves);
        } else {
            printf("I am a slave\n");
            slave(sock);
        }

        //sleep((rand()%7));

    }

    //keep listening for data


    close(sock);
    return 0;
}