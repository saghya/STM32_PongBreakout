#include "gyro.h"
#include "stm32f429i_discovery_gyroscope.h"
#include "display.h"

void gyroInit()
{
    if(BSP_GYRO_Init()!=GYRO_OK)
    {
        printMsg("ERROR WITH GYRO");
        return;
    }
    BSP_GYRO_Reset();
}

float getXFromGyro()
{
    float buffer[3];
    BSP_GYRO_GetXYZ(buffer);
    return buffer[0];
}