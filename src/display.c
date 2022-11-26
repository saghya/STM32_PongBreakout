#include "display.h"

void displayInit()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(0, LCD_FRAME_BUFFER);
    BSP_LCD_LayerDefaultInit(1, LCD_FRAME_BUFFER);
    BSP_LCD_DisplayOn();
}

void menu()
{
    /* Set the LCD Text Color */
    BSP_LCD_SelectLayer(0);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
    BSP_LCD_FillCircle(50, 220, 20);
}