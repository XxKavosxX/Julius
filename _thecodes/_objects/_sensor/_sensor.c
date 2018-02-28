/*
 * _sensor.c
 *
 *  Created on: 23 de jun de 2017
 *      Author: mk
 */

#include "../../includes/_sensor.h"

struct Sensor {

	uint8_t pin :7;
	uint8_t status :1;
	const char* name;
};

struct Sensor* new_sensor(void) {

	struct Sensor* sensor = malloc(sizeof(struct Sensor));
	return sensor;

}
int del_sensor(struct Sensor* sensor) {

	if (sensor == NULL)
		return 0;

	free(sensor);
	return 1;

}
_Bool sensor_set_pin(struct Sensor* sensor, uint8_t pin) {

	if (sensor == NULL)
		return 0;

	sensor->pin = pin;
	return 1;

}
_Bool sensor_set_status(struct Sensor* sensor, uint8_t status) {

	if (sensor == NULL)
		return 0;

	sensor->status = status;
	return 1;
}
_Bool sensor_set_name(struct Sensor* sensor, char* name) {
	if (sensor == NULL)
		return 0;

	sensor->name = name;
	return 1;
}
const uint8_t sensor_get_pin(struct Sensor* sensor) {

	if (sensor == NULL)
		return 0;

	return sensor->pin;

}
const uint8_t sensor_get_status(struct Sensor* sensor) {

	if (sensor == NULL)
		return 0;

	return sensor->status;

}
const char* sensor_get_name(struct Sensor* sensor) {

	if (sensor == NULL)
		return INVALID_NAME;

	return sensor->name;

}

