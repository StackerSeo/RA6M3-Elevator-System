/* Run_Servo.c */

#include <Run_Servo.h>

/* GLOBAL VARIABLE AREA */
const double SERVO_MINIMUM_DUTY = 0.03; //0도
const double SERVO_MAXIMUM_DUTY = 0.12; //180도
uint32_t Timer_Period = 0x249F00; // 20[ms] Duty Cycle (50[Hz])

//서보모터 각도 동작
void Run_Servo(uint8_t num)
{
    if (num == 0) //0이면 0도로
        R_GPT0->GTCCR[0] = (uint32_t)(Timer_Period * SERVO_MAXIMUM_DUTY);
    else //180도로
        R_GPT0->GTCCR[0] = (uint32_t)(Timer_Period * SERVO_MINIMUM_DUTY);
}
