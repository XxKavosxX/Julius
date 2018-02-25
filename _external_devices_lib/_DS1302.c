/*
 * _DS1302.c
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#include "_DS1302.h"

struct Date* current_date;
uint8_t aux[8] = { 0 };
void initialize_DS1302() {
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
void stop_DS1302() {
	_clr_bit(PORTB, CE_PIN);
	_delay_us(5);
}
uint8_t read_data_from_rtc() {
	uint8_t byte = 0x00;
	uint8_t aux_bit = 0x00;
	_clr_bit(DDRD, IO_PIN);  // I/O como entrada
	_delay_us(4);
	for (uint8_t i = 0; i <= 7; i++) {
		pulse_clock_rising()
		;
		pulse_clock_falling()
		;
		aux_bit = (_tst_bit(PIND, IO_PIN)) >> 7;
		byte |= (aux_bit << i);
	}
	return byte;
}
void write_data_to_rtc(const uint8_t byte) {
	uint8_t aux_bit = 0x00;
	for (uint8_t i = 0; i <= 7; i++) {
		aux_bit = (_tst_bit(byte, i)) >> i;
		if (aux_bit == 1) {
			_set_bit(PORTD, IO_PIN);
		} else {
			_clr_bit(PORTD, IO_PIN);
		}
		pulse_clock_rising()
		;
		pulse_clock_falling()
		;
	}
}
uint8_t read_from_register(const uint8_t register_number) {
	uint8_t aux = 0;
	write_data_to_rtc(0x81 | (register_number)); // Mascara o comando de leitura com o numero do registrador
	_delay_us(4);
	aux = read_data_from_rtc();
	return aux;
}
void write_to_register(const uint8_t register_number, uint8_t valor) {
	write_data_to_rtc(0x80 | (register_number));
	write_data_to_rtc(valor);
	_delay_us(4);
}
void date_write(uint8_t *date) {

	initialize_DS1302();
	write_data_to_rtc(0xBE);

	for (uint8_t i = 0; i <= 7; i++) {
		write_data_to_rtc(*(date + i)); // retorna valores das funcoes get usando ponteiro para funcao membro
		lcd_send_command(*(date + i) + 48, 1);
	}
	stop_DS1302();
}
void date_read(uint8_t *date) {

	initialize_DS1302();
	write_data_to_rtc(0xBF);
	_delay_us(4);

	for (uint8_t i = 0; i <= 7; i++) {
		*(date + i) = read_data_from_rtc(); // para valores paras as funcoes set usando ponteiro para funcao membro
	}
	stop_DS1302();
}
void enable_write() {
	write_to_register(0x8E, 0);
}
_Bool init_RTC(uint8_t seconds, uint8_t minutes, uint8_t hour, uint8_t day,
		uint8_t month, uint8_t week_day, uint8_t year) {

	if (current_date == NULL) {
		current_date = new_date_structure();
		if (current_date != NULL) {
			enable_write();
			set_date_structure(current_date, seconds, minutes, hour, day, month,
					week_day, year);
			date_write((uint8_t*) get_date_structure(current_date));
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}
_Bool read_RTC() {
	if (current_date == NULL) {
		if ((current_date = new_date_structure()) != NULL) {

			date_read((uint8_t*) aux);
			set_date_structure(current_date, aux[0], aux[1], aux[2], aux[3],
					aux[4], aux[5], aux[6]);

			//date_read((uint8_t*) &current_date);

			return 1;
		} else {
			return 0;
		}

	} else {

		//date_read((uint8_t*) get_date_structure(current_date));

		lcd_clear();
		date_read((uint8_t*) aux);

		lcd_send_command(_dec_to_bcd_high(aux[2]), 1);
		lcd_send_command(_dec_to_bcd_low(aux[2]), 1);
		lcd_send_command(58, 1);
		lcd_send_command(_dec_to_bcd_high(aux[1]), 1);
		lcd_send_command(_dec_to_bcd_low(aux[1]), 1);
		lcd_send_command(58, 1);
		lcd_send_command(_dec_to_bcd_high(aux[0]), 1);
		lcd_send_command(_dec_to_bcd_low(aux[0]), 1);
		lcd_send_command(95, 1);
		lcd_send_command(_dec_to_bcd_high(aux[5]), 1);
		lcd_send_command(_dec_to_bcd_low(aux[5]), 1);
		lcd_set_cursor(1, 0);

		lcd_send_command(_dec_to_bcd_high(aux[3]), 1);
		lcd_send_command(_dec_to_bcd_low(aux[3]), 1);
		lcd_send_command(47, 1);
		lcd_send_command(_dec_to_bcd_high(aux[4]), 1);
		lcd_send_command(_dec_to_bcd_low(aux[4]), 1);
		lcd_send_command(47, 1);
		lcd_send_command(_dec_to_bcd_high(aux[6]), 1);
		lcd_send_command(_dec_to_bcd_low(aux[6]), 1);
		set_date_structure(current_date, aux[0], aux[1], aux[2], aux[3], aux[4],
				aux[5], aux[6]);
		_delay_ms(1000);
		return 1;
	}
}

