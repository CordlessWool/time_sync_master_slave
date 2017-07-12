//
// Created by wolle on 12.07.17.
//

#ifndef MASTERSLAVETIMESYNC_CREATECONNECTION_H
#define MASTERSLAVETIMESYNC_CREATECONNECTION_H

#include <netinet/in.h>

int setReciveTimeout(int sock, int sec, int usec);
int isThereAMaster(int sock, char* broadcastIP, int port, struct sockaddr_in si_master);

#endif //MASTERSLAVETIMESYNC_CREATECONNECTION_H
