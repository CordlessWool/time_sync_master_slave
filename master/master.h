//
// Created by wolle on 13.07.17.
//

#ifndef MASTERSLAVETIMESYNC_MASTER_H
#define MASTERSLAVETIMESYNC_MASTER_H

void master(int sock, struct sockaddr_in si_me, struct Slaves *slaves);
void *waitingForSlaves(void *data);

#endif //MASTERSLAVETIMESYNC_MASTER_H
