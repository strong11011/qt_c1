

#ifndef RVSCALLBACK_H
#define RVSCALLBACK_H 1

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include "RvsTypes.h"

extern volatile pid_t g_hasNewConn;

void LostConnectionCallback(pid_t connectId, const char* ip, int port);

void NewConnectionCallback(pid_t connectId, const char* ip, int port);

void PacketReceiveCallback(pid_t connectId, int cmd, const char* paramString);


#endif // RVSCALLBACK_H
