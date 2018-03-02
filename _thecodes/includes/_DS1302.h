/*
 * _DS1302.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#include "_date.h"
#include "_main_routine.h"
#ifndef EXTERNAL_DEVICES_LIB__DS1302_H_
#define EXTERNAL_DEVICES_LIB__DS1302_H_
#define CLOCK_PIN 6
#define IO_PIN 7
#define CE_PIN 0

#define _pulse_clock_rising() { _delay_us(1); _clr_bit(PORTD, CLOCK_PIN); _delay_us(1); }
#define _pulse_clock_falling() { _delay_us(1); _set_bit(PORTD, CLOCK_PIN); _delay_us(1); }

#define CLOCK_BURST_READ_MODE 0xBF
#define BURST_BURST_WRITE_MODE 0xBE
#define WP_READ_MODE 0x8F
#define WP_WRITE_MODE 0x8E

#define FIRST_REG_ADDRESS_WRITE_MODE 0x80
#define FIRST_REG_ADDRESS_READ_MODE 0x81

#define REG_SEGUNDOS 0
#define REG_MINUTOS 2
#define REG_HORAS 4
#define REG_DATA 6
#define REG_MES 8
#define REG_DIA_SEMANA 10
#define REG_ANO 12
#define REG_BURST_M_WRITE 62

#define ERRRTC_INIT -1
#define ERRRTC_READ -2
void initalize_ds1302();
void enable_write();
void write_date(uint8_t *date);
void write_data_to_rtc(const uint8_t data);
void write_to_register(const uint8_t register_addr, uint8_t data);

void read_date(uint8_t *date);
uint8_t read_data_from_rtc();
uint8_t read_from_register(const uint8_t register_addr);

_Bool get_date_from_rtc();
void stop_data_transference();

struct Date *get_current_date();





_Bool set_date_on_rtc(uint8_t seconds, uint8_t minutes, uint8_t hour, uint8_t day,
		uint8_t month, uint8_t week_day, uint8_t year);


#endif /* EXTERNAL_DEVICES_LIB__DS1302_H_ */
