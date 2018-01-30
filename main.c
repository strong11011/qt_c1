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


void mymenu(void)
{
    printf("======================================\n");
    printf("1. Connect the radar server\n");
    printf("2. Disconnect the radar server\n");
    printf("3. Get radar state.\n");
    printf("4. Defence area arm.\n");
    printf("5. Defence area disarm.\n");
    printf("6. Defence area state upload.\n");
    printf("7. Defence area alarm upload.\n");
    printf("8. Targets state upload.\n");
    printf("======================================\n");
}

int main(int argc,char** argv)
{
    int ret=0;
    for(;;)
    {
       //display the main menu
        mymenu();
        scanf("%d",&ret);
        switch (ret)
        {
            case 1:Rvs_SetNewConnectionCallback(NewConnectionCallback);
                break;
            case 2:
            default:
                break;
        }
    }
}

int main1(int argc,char** argv)
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
