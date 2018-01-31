#ifndef READDATA_H
#define READDATA_H

typedef struct target
{
    unsigned int ID;
    unsigned char type[4];
    float x_speed;
    float y_speed;
    float z_speed;
    float x_axes;
    float y_axes;
    float z_axex;
    float length;
    float azimuth_angle;
    float elevation_angle;
    float snr;
    float peek_energy;
    unsigned char keep_unuse[16];
} target;

int Read_Data_Judje(const unsigned char *pin,int* n);

target* Make_Target(const unsigned char *pin);


#endif // READDATA_H
