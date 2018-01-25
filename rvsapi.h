#pragma once
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


//#define RVS_NET_API  

#ifdef __cplusplus
extern "C"{
#endif
    typedef void (RvsConnectionEventCallback)(void* connectId,const char* ip, int port);
    typedef void ( RvsPacketReceiveCallback)(void* connectId, int cmd, const char* paramString);
    //system init
     int Rvs_Init(int port);

     void Rvs_Clean();

     void Rvs_SetNewConnectionCallback(RvsConnectionEventCallback *callback);

     void Rvs_SetLostConnectionCallback(RvsConnectionEventCallback *callback);

     void Rvs_SetPacketReceiveCallback(RvsPacketReceiveCallback *callback);

     int Rvs_GetDeviceState(pid_t connectId, const char** defenceAreaIds, int count, char* bufferOut, int bufSize, int timeout);

     int Rvs_SetArm(pid_t connectId, const char* defenceAreaId, int isArm, char* bufferOut, int bufSize, int timeout);

#ifdef __cplusplus
}
#endif
