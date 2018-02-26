/*
 * _timers.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef THECODES_INCLUDES__TIMERS_H_
#define THECODES_INCLUDES__TIMERS_H_
#include <avr/delay.h>

#include "_main_routine.h"

ISR(TIMER1_OVF_vect);

void timer_set_range(uint32_t tempo_em_segundos);
void timer_start_count();
void timer_stop_count();



#endif /* THECODES_INCLUDES__TIMERS_H_ */
