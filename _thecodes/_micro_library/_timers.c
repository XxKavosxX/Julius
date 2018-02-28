/*
 * _timers.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../includes/_timers.h"
volatile uint32_t timeout_in_minutes;
volatile uint16_t counter_steps = 0;

void timer_alarm_clk(uint32_t seconds) {

	timeout_in_minutes = (uint16_t) (seconds) / 60.0;
}
void timer_start_count() {

	TCCR1B = (1 << CS12) | (1 << CS10);  //take ATmega328P datasheet.
	TCNT1 = ~0xF424;
	TIMSK0 = (1 << TOIE1);
	sei();

}
void timer_stop_count() {

	TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10)); //clock off
	TCNT1 = ~0xF424;
	TIMSK0 = (1 << TOIE1);                   			  //enable counter overflow interrupt
}
ISR(TIMER1_OVF_vect) {

	TCNT1 = ~0xF424;
	if (!(counter_steps >= (timeout_in_minutes)))
		counter_steps++;

	counter_steps = 0;
	timer_stop_count();

}

