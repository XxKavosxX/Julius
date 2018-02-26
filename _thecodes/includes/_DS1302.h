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

#define pulse_clock_rising() _delay_us(1); _clr_bit(PORTD, CLOCK_PIN); _delay_us(1);
#define pulse_clock_falling() _delay_us(1); _set_bit(PORTD, CLOCK_PIN); _delay_us(1);

#define REG_SEGUNDOS 0
#define REG_MINUTOS 2
#define REG_HORAS 4
#define REG_DATA 6
#define REG_MES 8
#define REG_DIA_SEMANA 10
#define REG_ANO 12
#define REG_BURST_M_WRITE 62

void initialize_DS1302();
void stop_DS1302();

uint8_t read_date_from_rtc();
void write_date_to_rtc(const uint8_t byte);

uint8_t read_from_register(const uint8_t registrador);
void write_to_register(const uint8_t registrador, uint8_t valor);

void date_write(uint8_t *date);
void enable_write();
void date_read(uint8_t *date);

_Bool init_RTC(uint8_t seconds, uint8_t minutes, uint8_t hour, uint8_t day, uint8_t month, uint8_t week_day, uint8_t year);
_Bool read_RTC();

void print_date();






#endif /* EXTERNAL_DEVICES_LIB__DS1302_H_ */
