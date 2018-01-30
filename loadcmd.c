#include "loadcmd.h"

int Load_Cmd_Connection( unsigned char* p)
{
    p[0]=0xa5;
    p[1]=0x5a;
    p[2]=0x10;//src_addr pc
    p[3]=0x60;//dis_addr sp100
    p[4]=0x0a;
    p[5]=0x00;
    p[6]=0x00;
    p[7]=p[2]+p[3]+p[4]+p[5]+p[6];
}
int load_Cmd_Disconnection( unsigned char* p);
int load_connection( unsigned char* p);
int load_connection( unsigned char* p);
int load_connection( unsigned char* p);
int load_connection( unsigned char* p);
