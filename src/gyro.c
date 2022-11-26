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
    printMsg("TEST");
}