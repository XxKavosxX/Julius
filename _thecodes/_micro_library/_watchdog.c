/*
 * _watchdog.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../includes/_watchdog.h"
void watchdog_reset() {

	cli();
	wdt_reset();
	MCUSR &= ~(1 << WDRF);
	WDTCSR &= ~(1 << WDE);
	sei();

}
void watchdog_disable() {

	cli();
	wdt_reset();
	MCUSR &= ~(1 << WDRF);
	WDTCSR |= (1 << WDCE) | (1 << WDE);
	WDTCSR = 0x00;
	sei();

}
_Bool watchdog_set_prescaler(uint8_t new_prescaler, uint8_t mode) {

	if (!(test_prescaler(new_prescaler) && test_mode(mode)))
		return 0;

	cli();
	wdt_reset();
	WDTCSR |= (1 << WDCE) | (1 << WDE);
	WDTCSR = (1 << WDE) | (WTD_PRESCALER_MASK & new_prescaler);
	sei();
	return 1;

}
static _Bool test_prescaler(uint8_t prescaler) {

	if (!(prescaler >= 0 && prescaler <= 9))
		return 0;

	return 1;

}
static _Bool test_mode(uint8_t modo) {

	if (!((modo == WTD_STOP_MODE) | (modo == WTD_INT_MODE)
			| (modo == WTD_INIT_MODE) | (modo == WTD_INTeINIT_MODE)))
		return 0;

	return 1;

}

