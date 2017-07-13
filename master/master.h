//
// Created by wolle on 13.07.17.
//

#ifndef MASTERSLAVETIMESYNC_MASTER_H
#define MASTERSLAVETIMESYNC_MASTER_H

int master(int sock, struct sockaddr_in si_me);

void *waitingForSlaves(void *data);

#endif //MASTERSLAVETIMESYNC_MASTER_H
