#include "rvsapi.h"
extern volatile pid_t g_hasNewConn;
//device inti
int Rvs_Init(int port)
{
	return 0;
}

void Rvs_Clean()
{
	return;
}

//set a new connection
void Rvs_SetNewConnectionCallback(RvsConnectionEventCallback *callback)
{

    pid_t pid_connect;
    pid_connect=fork();
    if(pid_connect==-1)
    {
        perror("fork err 1");
    }
    else if(pid_connect==0)
    {

        printf("connecting the radar......\n");
        callback(pid_connect,"192.168.30.205", 50000);
    }
    //callback(pid_connect,"192.168.30.205", 50000);
	return;
}

void Rvs_SetLostConnectionCallback(RvsConnectionEventCallback *callback)
{
	return;
}
// packet receive
void Rvs_SetPacketReceiveCallback(RvsPacketReceiveCallback *callback)
{
	return;
}
// get device state
int Rvs_GetDeviceState(pid_t connectId, const char** defenceAreaIds, int count, char* bufferOut, int bufSize, int timeout)
{
	return 0;
}
//
int Rvs_SetArm(pid_t connectId, const char* defenceAreaId, int isArm, char* bufferOut, int bufSize, int timeout)
{
	return 0;
}
