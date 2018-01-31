#include "rvsreaddata.h"



int Read_Data_Judje(const unsigned char *pin,int* n)
{

    switch (pin[4]) {
    case 0xa2:
        break;
    case 0xa8:Make_Target(pin);
        break;
    default:
        break;
    }

}
target* Make_Target(const unsigned char *pin)
{


}
