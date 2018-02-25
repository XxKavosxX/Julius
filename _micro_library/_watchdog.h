/*
 * _watchdog.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef MICRO_LIBRARY__WATCHDOG_H_
#define MICRO_LIBRARY__WATCHDOG_H_
#include "../_routine/_main_routine.h"
#include <avr/wdt.h>
#define WTD_PRESCALER_MASK 0x07
#define WTD_STOP_MODE 0x00
#define WTD_INT_MODE 0x04
#define WTD_INIT_MODE 0x40
#define WTD_INTeINIT_MODE 0x48
void watch_dog_reset();
void watch_dog_disable();
_Bool watch_dog_set_prescaler(uint8_t new_prescaler, uint8_t mode);
static _Bool test_prescaler(uint8_t prescaler);
static _Bool test_mode(uint8_t modo);





#endif /* MICRO_LIBRARY__WATCHDOG_H_ */
