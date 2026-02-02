/* CAN.h */

#ifndef CAN_H_
#define CAN_H_

#include "hal_data.h"

void Send_to_PC(uint8_t identifier, uint8_t N);
void Send_message(uint8_t *message, uint8_t message_length);
uint8_t DECtoASCII(uint8_t N);

#endif /* CAN_H_ */
