#pragma once


#define PROTOCOL_HEAD "NOVASKY"
#define PROTOCOL_END "END"

#define SPILTER_PART "@@"
#define SPILTER_PARAM ";"
#define SPILTER_OBJECT "##"
#define SPILTER_OBJECT_PARAM "%%"
#define PARAM_EMPTY "Empty"


typedef enum RvsCmdEnum
{
    UNKNOWN,
    HEART,
    GET_DEVICE_STATE,
    ARM_DISARM,
    AREA_STATE_UPLOAD,
    AREA_ALARM_UPLOAD,
    TARGETS_UPLOAD,
    COMMAND_END,
}RvsCmd;

#define RVS_NO_ERROR            0
#define RVS_NO_INIT              -1
#define RVS_PORT_ERROR          -2
#define RVS_PORT_CONFLICT       -3
#define RVS_CONNECT_ID_ERROR    -4
#define RVS_ERROR_TIMEOUT       -5
#define RVS_COMMAND_ERROR       -6
#define RVS_UNKNOWN_ERROR       -20