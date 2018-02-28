/*
 * _sensor_list.h
 *
 *  Created on: 24 de jun de 2017
 *      Author: mk
 */

#ifndef SENSOR_LIST_H_
#define SENSOR_LIST_H_
#include "_sensor.h"
#include "_usart.h"

#define NUM_SENSORS 15

struct Node_sens {
	struct Sensor *content;
	struct Node_sens *_next_unit;
};
struct Node_sens* node_get_first();
struct Node_sens* new_sens_node(struct Sensor* content);
_Bool sens_list_begin(struct Sensor* content);
_Bool sens_append(struct Sensor* content);
_Bool sens_delete(struct Sensor* content);
struct Node_sens* sens_search(uint8_t pin);

#endif /* SENSOR_MATRIX_H_ */
