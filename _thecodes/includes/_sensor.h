/*
 * _sensor.h
 *
 *  Created on: 23 de jun de 2017
 *      Author: mk
 */

#ifndef OBJECTS__SENSOR_H_
#define OBJECTS__SENSOR_H_

#include "_main_routine.h"

struct Sensor;
struct Sensor *new_sensor(void);
int delete_sensor(struct Sensor *sensor);
_Bool set_sensor_plugged_pin(struct Sensor *sensor, uint8_t pin);
_Bool set_sensor_status(struct Sensor *sensor, uint8_t status);
_Bool set_sensor_name(struct Sensor *sensor, char *name);
const uint8_t get_sensor_plugged_pin(struct Sensor *sensor);
const uint8_t get_sensor_status(struct Sensor *sensor);
const char *get_sensor_name(struct Sensor *sensor);


#endif /* OBJECTS__SENSOR_H_ */
