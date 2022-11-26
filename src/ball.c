#include "ball.h"
#include "display.h"
#include <stdbool.h>

void initBall(ball *ball)
{
    ball->position = (coordinate){WIDTH/2,HEIGHT/2};
    ball->direction_vector = (coordinate){0,1};
}

void drawBall(ball ball)
{
    BSP_LCD_DrawCircle(ball.position.x,ball.position.y,RAD);
}

void stepBall(ball *ball)
{
    ball->position = sumVector(ball->position,ball->direction_vector);
    if(isBallAtWall(*ball))
    {

    }
}