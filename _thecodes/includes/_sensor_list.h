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

struct Sensor_list_node;
struct Sensor_list_node *new_sensor_list_node(struct Sensor *sensor);
int delete_sensor_list_node(struct Sensor_list_node *sensor_list_node);
_Bool begin_sensor(struct Sensor *sensor);
_Bool append_sensor(struct Sensor *sensor);
_Bool remove_sensor(struct Sensor *sensor);
struct Sensor_list_node *search_sensor(uint8_t pin);

#endif /* SENSOR_MATRIX_H_ */
