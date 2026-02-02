/* Confirm.h */

#ifndef CONFIRM_H_
#define CONFIRM_H_

#include "hal_data.h"

void Confirm_state(uint8_t floor_state[4], uint8_t *Elebator_state);
void Confirm_floor(uint8_t direction, uint8_t Current_floor, uint8_t *Goal_floor, uint8_t floor_state[4]);
void Confirm_direction(uint8_t Elevator_state, uint8_t *direction, uint8_t Current_floor, uint8_t Goal_floor);

#endif /* CONFIRM_H_ */
