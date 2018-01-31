

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
#include "rvswritecmd.h"

extern volatile pid_t g_hasNewConn;

//get error type
const char* GetErrorType(int err);
//get cmd type
const char* GetCmdType(RvsCmd cmd);
//
void LostConnectionCallback(pid_t connectId, const char* ip, int port);

void NewConnectionCallback(pid_t connectId, const char* ip, int port);

void PacketReceiveCallback(pid_t connectId, int cmd, const char* paramString);


#endif // RVSCALLBACK_H
