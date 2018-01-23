

#ifndef RVSCALLBACK_H
#define RVSCALLBACK_H 1

#include <stdio.h>
#include <unistd.h>
#include "RvsTypes.h"

extern volatile void* g_hasNewConn;

void LostConnectionCallback(void* connectId, const char* ip, int port);

void NewConnectionCallback(void* connectId, const char* ip, int port);

void PacketReceiveCallback(void* connectId, int cmd, const char* paramString);


#endif // RVSCALLBACK_H
