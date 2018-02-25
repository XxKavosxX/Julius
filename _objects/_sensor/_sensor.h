/*
 * _sensor.h
 *
 *  Created on: 23 de jun de 2017
 *      Author: mk
 */

#ifndef OBJECTS__SENSOR_H_
#define OBJECTS__SENSOR_H_

#include "../../_routine/_main_routine.h"

#define INVALID_NAME PSTR("UNKNOW NAME")

struct Sensor;
struct Sensor* new_sensor(void);
int del_sensor(struct Sensor* sensor);
_Bool sensor_set_pin(struct Sensor* sensor, uint8_t pin);
_Bool sensor_set_status(struct Sensor* sensor, uint8_t status);
_Bool sensor_set_name(struct Sensor* sensor, char* name);
const uint8_t sensor_get_pin(struct Sensor* sensor);
const uint8_t sensor_get_status(struct Sensor* sensor);
const char* sensor_get_name(struct Sensor* sensor);


#endif /* OBJECTS__SENSOR_H_ */
