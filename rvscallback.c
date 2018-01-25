#include "rvscallback.h"

volatile pid_t g_hasNewConn=0;
//lost connection
void LostConnectionCallback(pid_t connectId, const char* ip, int port)
{


    printf("lost conn, id: %p, ip: %s, port: %d\n", connectId, ip, port);
}
//have a new connection
void NewConnectionCallback(pid_t connectId, const char* ip, int port)
{
    struct sockaddr_in servaddr;
    int sockfd;
    int ret=0;
    pid_t pid;

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    //use ip4
    servaddr.sin_family=AF_INET;
    inet_pton(AF_INET,"192.168.30.205",&servaddr.sin_addr);
    servaddr.sin_port=htons(50000);


    pid=fork();
    if(pid<0)
    {
        perror("fork connect error:");
        exit(-1);
    }
    if(pid>0)
    {
        ret=connect(sockfd,(struct sockaddr*) &servaddr,sizeof(servaddr));
        g_hasNewConn=pid;
        connectId=g_hasNewConn;
    }
    //use TCP
    perror("connect error:");
    printf("new conn, id: %d, ip: %s, port: %d\n",connectId,  ip, port);
    g_hasNewConn = connectId;
}

void PacketReceiveCallback(pid_t connectId, int cmd, const char* paramString)
{
    printf("recv, id: %d, cmd: %s, \n-----params-----\n%s\n\n", connectId, GetCmdType(cmd), paramString);

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
