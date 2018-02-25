/*
 * _sensor_matrix.h
 *
 *  Created on: 24 de jun de 2017
 *      Author: mk
 */

#ifndef SENSOR_MATRIX_H_
#define SENSOR_MATRIX_H_
#include "_sensor.h"
#include "../../_micro_library/_usart.h"
struct Unit {
	struct Sensor *content;
	struct Unit *_next_unit;
};
struct Unit* unit_get_first();
struct Unit* new_unit(struct Sensor* content);
_Bool unit_list_begin(struct Sensor* content);
_Bool unit_append(struct Sensor* content);
_Bool unit_delete(struct Sensor* content);
struct Unit* unit_search(uint8_t pin);
void unit_print(struct Unit* unit);
void unit_print_list();

#endif /* SENSOR_MATRIX_H_ */
