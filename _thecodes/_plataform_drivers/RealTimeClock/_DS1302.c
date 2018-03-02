/*
 * _DS1302.c
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#include "../../includes/_DS1302.h"

struct Date *current_date;
uint8_t aux_date[8] = { 0 };

void initialize_ds1302() {
	//CE
	_clr_bit(PORTB, CE_PIN);
	_set_bit(DDRB, CE_PIN);
	//CLK
	_clr_bit(PORTD, CLOCK_PIN);
	_set_bit(DDRD, CLOCK_PIN);
	//IO
	_set_bit(DDRD, IO_PIN);
	_set_bit(PORTB, CE_PIN);
	_delay_us(5);
}
void stop_data_transference() {

	_clr_bit(PORTB, CE_PIN);
	_delay_us(5);

}
void write_date(uint8_t *date) {

	initialize_ds1302();
	write_data_to_rtc(BURST_BURST_WRITE_MODE);
	_delay_us(4);

	for (uint8_t i = 0; i <= 7; i++)
		write_data_to_rtc(*(date + i));

	stop_data_transference();

}
void read_date(uint8_t *date) {

	initialize_ds1302();
	read_data_from_rtc(CLOCK_BURST_READ_MODE);

	for (uint8_t i = 0; i <= 7; i++)
		*(date + i) = read_data_from_rtc();

	stop_data_transference();
}

void write_data_to_rtc(const uint8_t byte) {

	uint8_t aux_bit = 0x00;

	for (uint8_t i = 0; i <= 7; i++) {

		aux_bit = (_tst_bit(byte, i)) >> i;

		if (aux_bit == 1)
			_set_bit(PORTD, IO_PIN);
		else
			_clr_bit(PORTD, IO_PIN);

		_pulse_clock_rising()
		;
		_pulse_clock_falling()
		;
	}
}
uint8_t read_data_from_rtc() {

	uint8_t byte = 0x00;
	uint8_t aux_bit = 0x00;

	_clr_bit(DDRD, IO_PIN);  // I/O como entrada
	_delay_us(4);

	for (uint8_t i = 0; i <= 7; i++) {

		_pulse_clock_rising()
		;
		_pulse_clock_falling()
		;
		aux_bit = (_tst_bit(PIND, IO_PIN)) >> 7;
		byte |= (aux_bit << i);

	}
	return byte;
}
uint8_t read_from_register(const uint8_t register_number) {

	uint8_t aux = 0;
	write_data_to_rtc(0x81 | (register_number)); // Mascara o comando de leitura com o numero do registrador
	_delay_us(4);
	aux = read_data_from_rtc();
	return aux;
}
void write_to_register(const uint8_t register_number, uint8_t valor) {

	write_data_to_rtc(FIRST_REG_ADDRESS_WRITE_MODE | (register_number));
	write_data_to_rtc(valor);
	_delay_us(4);

}

void enable_write() {
	write_to_register(WP_WRITE_MODE, 0);
}
_Bool set_date_on_rtc(uint8_t seconds, uint8_t minutes, uint8_t hour,
		uint8_t day, uint8_t month, uint8_t week_day, uint8_t year) {

	if (current_date != NULL)
		return ERRRTC_INIT;

	current_date = new_date();

	if (current_date == NULL)
		return ERRRTC_INIT;

	enable_write();
	setup_date(current_date, seconds, minutes, hour, day, month, week_day,
			year);
	write_date((uint8_t*) date_to_array(current_date));
	return 1;
}
_Bool get_date_from_rtc() {

	if (current_date == NULL)
		current_date = new_date();

	if (current_date == NULL)
		return ERRRTC_READ;

	read_date((uint8_t*) aux_date);
	setup_date(current_date, aux_date[0], aux_date[1], aux_date[2], aux_date[3],
			aux_date[4], aux_date[5], aux_date[6]);
	return 1;
}
struct Date *get_current_date(){
	get_date_from_rtc();
	return current_date;
}

