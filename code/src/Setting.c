/* Setting.c */

//setting(enable) & disable
#include <Setting.h>

/* GLOBAL VARIABLE AREA */
volatile uint8_t state_mask = 0x01;
uint32_t Timer_Period_DC = 0x3A980; // 2[ms] Duty Cycle (500[Hz])
uint32_t Timer_Period_Servo = 0x249F00; // 20[ms] Duty Cycle (50[Hz])

void Initial_Setting(can_frame_t *g_can_tx_frame)
{
    CAN_Setting(g_can_tx_frame); //CAN통신
    AGT0_Setting(); //AGT
    GPT0_Setting(); //GPT, Servo motor
    GPT3_Setting(); //GPT, DC motor
    FND_Reset(); //FND
    LED_Reset(); //LED
    IRQ_Setting(); //Switch
    IRQ_Enable(); //Switch
    DAC_Setting(); //Speaker
}
void CAN_Setting(can_frame_t *g_can_tx_frame)
{
    uint32_t id = 1U;
    uint8_t data_field[8] = {0x43, 0x41, 0x4E, 0x20, 0x4F, 0x4B, 0x41, 0x59}; //CAN OKAY;

    R_CAN_Open(&g_can0_ctrl, &g_can0_cfg);
    CAN_Frame_Setting(g_can_tx_frame, id, STANDARD_CAN_FRAME, data_field);
    R_CAN_Write(&g_can0_ctrl, 0, g_can_tx_frame);
}
void CAN_Frame_Setting(can_frame_t *g_can_tx_frame, uint32_t id, uint8_t dlc, uint8_t *data)
{
    g_can_tx_frame->id = id;
    g_can_tx_frame->id_mode = CAN_ID_MODE_STANDARD;
    g_can_tx_frame->type = CAN_FRAME_TYPE_DATA;

    g_can_tx_frame->data_length_code = dlc;

    if (strlen((const char *)data) <= 8)
        memcpy(g_can_tx_frame->data, data, dlc);
    else
        memset(g_can_tx_frame->data, 0, sizeof(uint8_t) * STANDARD_CAN_FRAME);
}
void AGT0_Setting()
{
    R_AGT_Open(&g_timer1_ctrl, &g_timer1_cfg);
    R_AGT_Start(&g_timer1_ctrl);
}
void GPT0_Setting()
{
    R_MSTP->MSTPCRD_b.MSTPD5 = 0U; // GPT32EH0 Module Stop State Cancel

    R_GPT0->GTCR_b.MD = 0U; // GPT32EH0 Count Mode Setting (Saw-wave PWM Mode)
    R_GPT0->GTCR_b.TPCS = 0U; // GPT32EH0 Clock Source Prescale Setting (PCLKD / 1)

    R_GPT0->GTPR = Timer_Period_Servo - 1; // GPT32EH0 Counting Maximum Cycle Setting
    R_GPT0->GTCNT = 0; // GPT32EH0 Counter Initial Value Setting

    R_GPT0->GTIOR_b.GTIOA = 9U; // Compare Matching Output Control Setting
    R_GPT0->GTIOR_b.OAE = 1U; // GPIOCA Output Pin Enable

    R_GPT0->GTCR_b.CST = 1U;
    R_GPT0->GTCCR[0] = (uint32_t)(Timer_Period_Servo * 0.03); // GTCCR Initial Setting (Angle = 0[degree])
}
void GPT3_Setting()
{
    R_MSTP->MSTPCRD_b.MSTPD5 = 0U;

    R_GPT3->GTCR_b.MD = 0U;
    R_GPT3->GTCR_b.TPCS = 0U;

    R_GPT3->GTPR = Timer_Period_DC - 1;
    R_GPT3->GTCNT = 0;

    R_GPT3->GTIOR_b.GTIOA = 9U;
    R_GPT3->GTIOR_b.OAE = 1U;

    R_GPT3->GTCR_b.CST = 1U;
    R_GPT3->GTCCR[0] = (uint32_t)(Timer_Period_DC * 0.5);
}
void FND_Reset()
{
    uint8_t idx = 0;

    /* 7-Segment Initialization */
    for (idx = 0; idx < SEGMENT_INDEX; idx++)
    {
        if (idx < DIGIT_INDEX)
            R_IOPORT_PinWrite(&g_ioport_ctrl, segment_digit[idx], BSP_IO_LEVEL_LOW);
        R_IOPORT_PinWrite(&g_ioport_ctrl, segment_led_pin[idx], BSP_IO_LEVEL_HIGH);
    }
}

void LED_Reset()
{
    uint8_t idx = 0;
    for (idx = 0; idx < LED_INDEX; idx++)
        R_IOPORT_PinWrite(&g_ioport_ctrl, led_pin[idx], BSP_IO_LEVEL_HIGH);
}
void IRQ_Setting()
{
    R_ICU_ExternalIrqOpen(&g_external_irq11_ctrl, &g_external_irq11_cfg);
    R_ICU_ExternalIrqOpen(&g_external_irq12_ctrl, &g_external_irq12_cfg);
    R_ICU_ExternalIrqOpen(&g_external_irq13_ctrl, &g_external_irq13_cfg);
    R_ICU_ExternalIrqOpen(&g_external_irq14_ctrl, &g_external_irq14_cfg);
}
void IRQ_Enable()
{
    R_ICU_ExternalIrqEnable(&g_external_irq11_ctrl);
    R_ICU_ExternalIrqEnable(&g_external_irq12_ctrl);
    R_ICU_ExternalIrqEnable(&g_external_irq13_ctrl);
    R_ICU_ExternalIrqEnable(&g_external_irq14_ctrl);
}
void IRQ_Disable()
{
    R_ICU_ExternalIrqDisable(&g_external_irq11_ctrl);
    R_ICU_ExternalIrqDisable(&g_external_irq12_ctrl);
    R_ICU_ExternalIrqDisable(&g_external_irq13_ctrl);
    R_ICU_ExternalIrqDisable(&g_external_irq14_ctrl);
}
void DAC_Setting()
{
    R_DAC_Open(&g_dac0_ctrl, &g_dac0_cfg);
    R_DAC_Start(&g_dac0_ctrl);
}
