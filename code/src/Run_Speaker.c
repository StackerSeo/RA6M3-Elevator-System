/* Run_Speaker.c */

#include <Run_Speaker.h>

/* GLOBAL VARIABLE AREA */
extern unsigned char sound1[155616]; //Sound

void Run_Speaker()
{
    uint16_t value;
    for (uint32_t i = 0; i < SOUND1_SIZE; i += 2) {
        value = (uint16_t)(sound1[i] | sound1[i + 1] << 8);
        R_DAC_Write(&g_dac0_ctrl, value);
        R_BSP_SoftwareDelay(20, BSP_DELAY_UNITS_MICROSECONDS);
    }
}
