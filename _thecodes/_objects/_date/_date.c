/*
 * _date.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../../includes/_date.h"

uint8_t atual_data[8] = { 0 };

struct Date {
	//First byte
	uint8_t seconds_low :4;
	uint8_t seconds_high :3;
	uint8_t clock_halt_frag :1;
	//Second byte
	uint8_t minutes_low :4;
	uint8_t minutes_high :3;
	uint8_t unnused1 :1;
	//Third byte
	uint8_t hour_low :4;
	uint8_t hour_high :2;
	uint8_t unnused2 :2;
	//Fourth byte
	uint8_t day_low :4;
	uint8_t day_high :2;
	uint8_t unnused3 :2;
	//Fifth byte
	uint8_t month_low :4;
	uint8_t month_high :1;
	uint8_t unnused4 :3;
	//Sixth byte
	uint8_t week_day :3;
	uint8_t unnused5 :5;
	//Seventh byte
	uint8_t year_low :4;
	uint8_t year_high :4;
	//Eighth byte
	uint8_t unnused6 :7;
	uint8_t write_protect_bit :1;
};
struct Date* new_date(void) {

	struct Date *date = calloc(1, sizeof(struct Date));
	return date;

}
int delete_date(struct Date *date) {

	if (date == NULL)
		return 0;

	free(date);
	return 1;

}
void setup_date(struct Date *date, uint8_t seconds, uint8_t minutes, uint8_t hour,
		uint8_t day, uint8_t month, uint8_t week_day, uint8_t year) {

		//First byte
		date->seconds_low = _bin_to_bcd_low(seconds);
		date->seconds_high = _bin_to_bcd_high(seconds);
		date->clock_halt_frag = 0;
		//Second byteuint8_t current_time
		date->minutes_low = _bin_to_bcd_low(minutes);
		date->minutes_high = _bin_to_bcd_high(minutes);

		//Third
		date->hour_low = _bin_to_bcd_low(hour);
		date->hour_high = _bin_to_bcd_high(hour);

		//Fourth
		date->day_low = _bin_to_bcd_low(day);
		date->day_high = _bin_to_bcd_high(day);

		//Fifth
		date->month_low = _bin_to_bcd_low(month);
		date->month_high = _bin_to_bcd_high(month);

		//Sixthuint8_t current_time
		date->week_day = _bin_to_bcd_low(week_day);

		//Seventh
		date->year_high = _bin_to_bcd_high(year);
		date->year_low = _bin_to_bcd_low(year);

		//Eighth
		date->write_protect_bit = 0;

}
uint8_t* date_to_array(struct Date *date) {
	memset(atual_data, 0, 8);
	memcpy(atual_data, date, 8);
	return atual_data;
}
