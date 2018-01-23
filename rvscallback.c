#include "rvscallback.h"

volatile void* g_hasNewConn=NULL;
//lost connection
void LostConnectionCallback(void* connectId, const char* ip, int port)
{

    printf("lost conn, id: %p, ip: %s, port: %d\n", connectId, ip, port);
}
//have a new connection
void NewConnectionCallback(void* connectId, const char* ip, int port)
{

    printf("new conn, id: %p, ip: %s, port: %d\n", connectId, ip, port);
    g_hasNewConn = connectId;
}

void PacketReceiveCallback(void* connectId, int cmd, const char* paramString)
{
    printf("recv, id: %p, cmd: %s, \n-----params-----\n%s\n\n", connectId, GetCmdType(cmd), paramString);

    switch ((RvsCmd)cmd)
    {
    case UNKNOWN: break;
    case HEART: break;
    case GET_DEVICE_STATE: break;
    case ARM_DISARM: break;
    case AREA_STATE_UPLOAD: break;
    case AREA_ALARM_UPLOAD: break;
    case TARGETS_UPLOAD: break;
    case COMMAND_END: break;
    default: break;
    }
}
