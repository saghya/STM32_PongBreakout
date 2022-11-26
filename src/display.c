#include "display.h"
#include "stm32f429i_discovery_lcd.h"

void displayInit()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(0, LCD_FRAME_BUFFER);
    BSP_LCD_SelectLayer(0);
    /* Clear the LCD */ 
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
}

void menu()
{
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    /* Set the LCD Text Color */
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
}