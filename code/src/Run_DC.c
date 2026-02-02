/* Run_DC.c */

#include <Run_DC.h>

//DC모터 ON
void Run_DC(uint8_t direction)
{
    if (direction == 1) //올라가는 중, CW
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_09_PIN_01, BSP_IO_LEVEL_HIGH);
    else if (direction == 2) //내려가는 중, CCW
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_09_PIN_01, BSP_IO_LEVEL_LOW);
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_09_PIN_00, BSP_IO_LEVEL_HIGH); //ON
}
//DC모터 OFF
void Stop_DC()
{
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_09_PIN_00, BSP_IO_LEVEL_LOW);
}
