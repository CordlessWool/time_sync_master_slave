//
// Created by wolle on 12.07.17.
//

#ifndef MASTERSLAVETIMESYNC_CREATECONNECTION_H
#define MASTERSLAVETIMESYNC_CREATECONNECTION_H

#include <netinet/in.h>

struct Slaves{
    struct sockaddr_in slaves[15];
    int counter;
    int max;
    int registerPort;
};

int setReciveTimeout(int sock, int sec, int usec);
int isThereAMaster(int sock, char* broadcastIP, int port, struct sockaddr_in *si_master);
int addSlave(struct Slaves * slaves, struct sockaddr_in *si_slave);

#endif //MASTERSLAVETIMESYNC_CREATECONNECTION_H
