#include "display.h"

static int32_t activeLayer = LCD_BACKGROUND_LAYER;

void displayInit()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(0, LCD_FRAME_BUFFER);
    BSP_LCD_LayerDefaultInit(1, LCD_FRAME_BUFFER+BUFFER_OFFSET);
    BSP_LCD_DisplayOn();
    BSP_LCD_SetLayerVisible(activeLayer,DISABLE);
    BSP_LCD_SetLayerVisible(!activeLayer,DISABLE);
}

void swapDisplayedLayer()
{
    activeLayer = !activeLayer;
    BSP_LCD_SetLayerVisible_NoReload(activeLayer,ENABLE);
    BSP_LCD_SetLayerVisible_NoReload(!activeLayer,DISABLE);
    while(!(LTDC->CDSR & LTDC_CDSR_VSYNCS));
    BSP_LCD_Relaod(LCD_RELOAD_IMMEDIATE);
}

void selectInactiveLayer()
{
    BSP_LCD_SelectLayer(!activeLayer);
}

void menu()
{
    /* Set the LCD Text Color */
    selectInactiveLayer();
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
    BSP_LCD_DisplayStringAt(0,HEIGHT/8,(uint8_t *)"BOUNCEY",CENTER_MODE);
    BSP_LCD_DisplayStringAt(0,HEIGHT/4,(uint8_t *)"MENU",CENTER_MODE);
    BSP_LCD_DisplayStringAt(0,2*HEIGHT/4,(uint8_t *)"START",CENTER_MODE);
    BSP_LCD_DisplayStringAt(0,7*HEIGHT/8,(uint8_t *)"V1.0",CENTER_MODE);
    swapDisplayedLayer();
}

void printMsg(uint8_t *msg)
{
    selectInactiveLayer();
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAt(0,HEIGHT/2,msg,CENTER_MODE);
    swapDisplayedLayer();
}