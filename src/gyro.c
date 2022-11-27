#include "gyro.h"
#include "stm32f429i_discovery_gyroscope.h"
#include "display.h"
uint8_t state = 0;

void gyroInit()
{
    if(BSP_GYRO_Init()!=GYRO_OK)
    {
        printMsg((uint8_t *)"ERROR WITH GYRO");
        return;
    }
    BSP_GYRO_Reset();
}

int8_t getXFromGyro()
{
    float buffer[3][3];
    for(int i = 0; i < 3; i++)
    {
        BSP_GYRO_GetXYZ(buffer[i]);
    }
    float avg = (buffer[0][1]+buffer[1][1]+buffer[2][1])/3;
    if(avg>3000)
    {
        return 1;
    }
    else if(avg<-3000)
    {
        return -1;
    }
    return 0;
}