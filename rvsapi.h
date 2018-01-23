#pragma once
#include <unistd.h>
#include <sys/socket.h>


//#define RVS_NET_API  

#ifdef __cplusplus
extern "C"{
#endif
	
    typedef void (RvsConnectionEventCallback)(void* connectId, const char* ip, int port);
    typedef void ( RvsPacketReceiveCallback)(void* connectId, int cmd, const char* paramString);


    //≥ı ºªØ
     int Rvs_Init(int port);

     void Rvs_Clean();

     void Rvs_SetNewConnectionCallback(RvsConnectionEventCallback *callback);

     void Rvs_SetLostConnectionCallback(RvsConnectionEventCallback *callback);

     void Rvs_SetPacketReceiveCallback(RvsPacketReceiveCallback *callback);

     int Rvs_GetDeviceState(void* connectId, const char** defenceAreaIds, int count, char* bufferOut, int bufSize, int timeout);

     int Rvs_SetArm(void* connectId, const char* defenceAreaId, int isArm, char* bufferOut, int bufSize, int timeout);

#ifdef __cplusplus
}
#endif
