#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "rvsapi.h"
#include "RvsTypes.h"
#include "rvscallback.h"

//获取错误码，并返回错误类型名
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
int main(int argc,char** argv)
{
    struct sockaddr_in servaddr;
    int sockfd,n;
    char buf[1024 * 10];

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    bzero(&servaddr,sizeof(servaddr));


    Rvs_SetLostConnectionCallback(LostConnectionCallback);
    Rvs_SetNewConnectionCallback(NewConnectionCallback);
    Rvs_SetPacketReceiveCallback(PacketReceiveCallback);
	int err = Rvs_Init(5089);//初始化雷达
	if (RVS_NO_ERROR != err)
	{
		printf("%s\n", GetErrorType(err));//打印错误信息
	}

	puts("Waitting connection...");//等待连接

	while (g_hasNewConn == NULL)
	{
        sleep(1);
	}

	puts("Rvs_GetDeviceState, all");

	err = Rvs_GetDeviceState(g_hasNewConn, NULL, 0, buf, sizeof(buf), 3000);
	if (RVS_NO_ERROR == err)
	{
		printf("%s\n\n", buf);
	}
	else
	{
		printf("Failed :%s\n\n", GetErrorType(err));
	}

#define RVS_DEMO_GET_DEVICE_STATE_COUNT 2

	printf("Rvs_GetDeviceState, count = %d\n", RVS_DEMO_GET_DEVICE_STATE_COUNT);

	char *(ids[RVS_DEMO_GET_DEVICE_STATE_COUNT]);
	ids[0] = "192.168.10.115";
	ids[1] = "192.168.10.114";

	err = Rvs_GetDeviceState(g_hasNewConn, ids, RVS_DEMO_GET_DEVICE_STATE_COUNT, buf, sizeof(buf), 3000);
	if (RVS_NO_ERROR == err)
	{
		printf("%s\n\n", buf);
	}
	else
	{
		printf("Failed :%s\n\n", GetErrorType(err));
	}


	getchar();
	return 0;
}
