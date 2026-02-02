/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_can.h"
#include "r_can_api.h"
#include "r_agt.h"
#include "r_timer_api.h"
#include "r_gpt.h"
#include "r_timer_api.h"
#include "r_dac.h"
#include "r_dac_api.h"
#include "r_icu.h"
#include "r_external_irq_api.h"
FSP_HEADER
/** CAN on CAN Instance. */
extern const can_instance_t g_can0;
/** Access the CAN instance using these structures when calling API functions directly (::p_api is not used). */
extern can_instance_ctrl_t g_can0_ctrl;
extern const can_cfg_t g_can0_cfg;
extern const can_extended_cfg_t g_can0_cfg_extend;

#ifndef can_callback
void can_callback(can_callback_args_t *p_args);
#endif
#define CAN_NO_OF_MAILBOXES_g_can0 (32)
/** AGT Timer Instance */
extern const timer_instance_t g_timer1;

/** Access the AGT instance using these structures when calling API functions directly (::p_api is not used). */
extern agt_instance_ctrl_t g_timer1_ctrl;
extern const timer_cfg_t g_timer1_cfg;

#ifndef R_AGT0_Interrupt
void R_AGT0_Interrupt(timer_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer0;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t g_timer0_ctrl;
extern const timer_cfg_t g_timer0_cfg;

#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
/** DAC on DAC Instance. */
extern const dac_instance_t g_dac0;

/** Access the DAC instance using these structures when calling API functions directly (::p_api is not used). */
extern dac_instance_ctrl_t g_dac0_ctrl;
extern const dac_cfg_t g_dac0_cfg;
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq14;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq14_ctrl;
extern const external_irq_cfg_t g_external_irq14_cfg;

#ifndef R_IRQ_Interrupt
void R_IRQ_Interrupt(external_irq_callback_args_t *p_args);
#endif
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq13;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq13_ctrl;
extern const external_irq_cfg_t g_external_irq13_cfg;

#ifndef R_IRQ_Interrupt
void R_IRQ_Interrupt(external_irq_callback_args_t *p_args);
#endif
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq12;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq12_ctrl;
extern const external_irq_cfg_t g_external_irq12_cfg;

#ifndef R_IRQ_Interrupt
void R_IRQ_Interrupt(external_irq_callback_args_t *p_args);
#endif
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq11;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq11_ctrl;
extern const external_irq_cfg_t g_external_irq11_cfg;

#ifndef R_IRQ_Interrupt
void R_IRQ_Interrupt(external_irq_callback_args_t *p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
