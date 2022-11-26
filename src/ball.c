#include "ball.h"
#include "display.h"
#include <stdbool.h>

initBall(ball *ball)
{
    ball->position = (coordinate){WIDTH/2,HEIGHT/2};
    ball->direction_vector = (coordinate){0,1};
}

drawBall(ball ball)
{
    BSP_LCD_DrawCircle(ball.position.x,ball.position.y,RAD);
}

static bool isBallAtWall(ball ball)
{
    return ball.position.x-RAD<=0||ball.position.x+RAD>=WIDTH||ball.position.y+RAD>=HEIGHT||ball.position.y-RAD<=0;
}

stepBall(ball *ball)
{
    ball->position = sumVector(ball->position,ball->direction_vector);
    if(isBallAtWall(*ball))
    {
        //(2*pi-arccos((wallvector*direction_vector)/(length(wallvector)*length(direction_vector))))-pi/2-> ahh nem tudom ki kell matekozni a visszapattanást->fény jellegűen
    }
}