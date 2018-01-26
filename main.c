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
#include "rvsapi.h"
#include "RvsTypes.h"
#include "rvscallback.h"


int main(int argc,char** argv)
{


   // Rvs_SetLostConnectionCallback(LostConnectionCallback);
    Rvs_SetNewConnectionCallback(NewConnectionCallback);
    //Rvs_SetPacketReceiveCallback(PacketReceiveCallback);
     char buf[1024 * 10];
    int err = Rvs_Init(5089);//初始化雷达
    //if (RVS_NO_ERROR != err)
    //{
    //	printf("%s\n", GetErrorType(err));//打印错误信息
    //}

    puts("Waitting connection...");//等待连接
//the main thread test the connect status
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
	return 0;
}
