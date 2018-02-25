/*
 * _date.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */
#ifndef OBJECTS__DATE__DATE_H_
#define OBJECTS__DATE__DATE_H_

#include "inttypes.h"
#include "stdlib.h"
#include "../../_external_devices_lib/_I2C_LCD16x2.h"

#define _bcd_to_bin(high, low) (((high) * 10) + (low))
#define _bin_to_bcd_high(number) ((number) / 10)
#define _bin_to_bcd_low(number) ((number) % 10)
#define _dec_to_bcd_high(number) (((number & 0xF0)>>4)+48)
#define _dec_to_bcd_low(number) ((number & 0x0F)+48)

#define _dec_to_bcd(number) ((number/10 * 16) + (number % 10))
#define _bcd_to_dec(number)((number/16 * 10) + (number % 16))



struct Date;
struct Date* new_date_structure(void);
int del_date_structure(struct Date* date);
void set_date_structure(struct Date* date, uint8_t seconds, uint8_t minutes, uint8_t hour,
		uint8_t day, uint8_t month, uint8_t week_day, uint8_t year);
uint8_t* get_date_structure(struct Date* date);
void print();
#endif /* OBJECTS__DATE__DATE_H_ */
