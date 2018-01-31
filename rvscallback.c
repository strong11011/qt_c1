#include "rvscallback.h"


volatile pid_t g_hasNewConn=0;
//get error number return the type of error
const char* GetErrorType(int err)
{
    char* p_str = NULL;
    switch (err)
    {
    case  RVS_NO_ERROR:
        p_str = "RVS_NO_ERROR";
        break;
    case  RVS_NO_INIT:
        p_str = "RVS_NO_INIT";
        break;
    case   RVS_PORT_ERROR:
        p_str = "RVS_PORT_ERROR";
        break;
    case   RVS_PORT_CONFLICT:
        p_str = "RVS_PORT_CONFLICT";
        break;
    case  RVS_CONNECT_ID_ERROR:
        p_str = "RVS_CONNECT_ID_ERROR";
        break;
    case  RVS_ERROR_TIMEOUT:
        p_str = "RVS_ERROR_TIMEOUT";
        break;
    case  RVS_COMMAND_ERROR:
        p_str = "RVS_COMMAND_ERROR";
        break;
    default:
        p_str = "RVS_UNKNOWN_ERROR";
        break;
    }
    return p_str;
}

const char* GetCmdType(RvsCmd cmd)
{
    char* p_str = NULL;
    switch (cmd)
    {
    case HEART:
        p_str = "HEART";
        break;
    case GET_DEVICE_STATE:
        p_str = "GET_DEVICE_STATE";
        break;
    case ARM_DISARM:
        p_str = "ARM_DISARM";
        break;
    case AREA_STATE_UPLOAD:
        p_str = "AREA_STATE_UPLOAD";
        break;
    case AREA_ALARM_UPLOAD:
        p_str = "AREA_ALARM_UPLOAD";
        break;
    case TARGETS_UPLOAD:
        p_str = "TARGETS_UPLOAD";
        break;
    default:
        p_str = "UNKNOWN";
        break;
    }

    return p_str;
}
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

    int n=0;

    unsigned char bufSend[1024]={0};
    unsigned char bufReceive[1024]={0};

    Cmd_ToPacket(1, bufSend );
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    //use ip4
    servaddr.sin_family=AF_INET;
    inet_pton(AF_INET,ip,&servaddr.sin_addr);
    servaddr.sin_port=htons(50000);

    ret=connect(sockfd,(struct sockaddr*) &servaddr,sizeof(servaddr));
    if(!ret)
        printf("connecting success!!\n");

    g_hasNewConn=connectId;
    connectId=g_hasNewConn;
    //write(sockfd,bufSend,8);
    printf("waiting signal...\n");
    while(n=read(sockfd,bufReceive,1024))
    {

        for(int i=0;i<n;i++)
        {
            printf("%02x ",bufReceive[i]);
        }
        printf("\n");
        //sleep(1);

    }

    //write(STDOUT_FILENO,buf1,1024);
    perror("connect error:");
    printf("new conn, id: %d, ip: %s, port: %d\n",connectId,  ip, port);
    close(sockfd);
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

int SetParamString(  char *buf,int cmd,const char* paramString)
{
    if(cmd<0||cmd>7)
    {
        printf("cmd err\n");
        exit(-1);
    }

    buf[0]=0xa5;
    buf[1]=0x5a;
    buf[2]=0x10;//src_addr pc
    buf[3]=0x40;//dis_addr sp100
    switch ((RvsCmd)cmd)
    {
    case UNKNOWN: break;
    case HEART: break;
    case GET_DEVICE_STATE:buf[4]=0x0a; break;
    case ARM_DISARM: break;
    case AREA_STATE_UPLOAD: break;
    case AREA_ALARM_UPLOAD: break;
    case TARGETS_UPLOAD: break;
    case COMMAND_END: break;
    default: break;
    }

    return 0;
}

int Cmd_ToPacket(int cmd, char * pout )
{
    switch (cmd) {
    case 1:Load_Cmd_Connection(pout);


        break;
    default:
        break;
    }
}
