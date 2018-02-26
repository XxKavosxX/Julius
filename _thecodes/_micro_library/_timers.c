/*
 * _timers.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../includes/_timers.h"
volatile uint32_t timeout_in_minutes;
volatile uint16_t counter_steps = 0;

void timer_set_range(uint32_t seconds) {
	timeout_in_minutes = (uint16_t) (seconds) / 60.0;
}
void timer_start_count() {
	TCCR1B = (1 << CS12) | (1 << CS10); //SETA O PRESCALER PARA 1024  Te(s) = 65536x(1/16MHz)x1024 = 4,194304 s
	TCNT1 = ~0xF424; //SETA O VALOR INICIAL DO CONTADOR PARA CONSEGUIR TEMPO DE ESTOURO DE 4 s  => 4x16MHz/(1024) = 62500 = 0xF424
	TIMSK0 = (1 << TOIE1);                   //HABILITA A INTERRUP��O POR ESTOURO
	sei();
}
void timer_stop_count() {
	TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10)); //DESLIGA A FONTE DE CLOCK
	//TCNT1 = 0xC2F7;
	TCNT1 = ~0xF424;        //SETA O VALOR INICIAL PARA OBTER ESTOURO A CADA 1 s
	TIMSK0 = (1 << TOIE1);                   //HABILITA A INTERRUP��O POR ESTOURO
}
ISR(TIMER1_OVF_vect) {
	TCNT1 = ~0xF424;
	//SETA O VALOR INICIAL PARA OBTER ESTOURO A CADA 1 s
	//tempo para desligar em segundos
	if (counter_steps >= (timeout_in_minutes)) {

		counter_steps = 0;
		timer_stop_count();

		//Shutdown a device
	} else {
		counter_steps++;

	}
}

