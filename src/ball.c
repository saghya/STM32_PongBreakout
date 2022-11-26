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
    if(ball->position.x + RAD >= WIDTH || ball->position.x - RAD < 0)
    {
        ball->position.x *= -1;
    }
    if(ball->position.y + RAD >= HEIGHT || ball->position.y - RAD < 0)
    {
        ball->position.y *= -1;
    }
}
