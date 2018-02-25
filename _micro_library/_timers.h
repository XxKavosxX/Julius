/*
 * _timers.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef MICRO_LIBRARY__TIMERS_H_
#define MICRO_LIBRARY__TIMERS_H_
#include "../_routine/_main_routine.h"
#include <avr/delay.h>

ISR(TIMER1_OVF_vect);

void timer_set_range(uint32_t tempo_em_segundos);
void timer_start_count();
void timer_stop_count();



#endif /* MICRO_LIBRARY__TIMERS_H_ */
