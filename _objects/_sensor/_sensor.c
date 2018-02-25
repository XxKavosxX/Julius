/*
 * _sensor.c
 *
 *  Created on: 23 de jun de 2017
 *      Author: mk
 */

#include "_sensor.h"

struct Sensor {
	uint8_t pin :7;
	uint8_t status :1;
	const char* name;
};

struct Sensor* new_sensor(void) {
	struct Sensor* sensor;
	sensor = malloc(sizeof(struct Sensor));
	return sensor;
}
int del_sensor(struct Sensor* sensor) {
	if (sensor != NULL) {
		free(sensor);
		return 1;
	} else {
		return 0;
	}
}
_Bool sensor_set_pin(struct Sensor* sensor, uint8_t pin) {
	if (sensor != NULL) {
		sensor->pin = pin;
		return 1;
	} else {
		return 0;
	}
}
_Bool sensor_set_status(struct Sensor* sensor, uint8_t status) {
	if (sensor != NULL) {
		sensor->status = status;
		return 1;
	} else {
		return 0;
	}
}
_Bool sensor_set_name(struct Sensor* sensor, char* name) {
	if (sensor != NULL) {
		sensor->name = name;
		return 1;
	} else {
		return 0;
	}
}
const uint8_t sensor_get_pin(struct Sensor* sensor) {
	if (sensor != NULL) {
		return sensor->pin;
	} else {
		return 0;
	}
}
const uint8_t sensor_get_status(struct Sensor* sensor) {
	if (sensor != NULL) {
		return sensor->status;
	} else {
		return 0;
	}
}
const char* sensor_get_name(struct Sensor* sensor) {
	if (sensor != NULL) {
		return sensor->name;
	} else {
		return INVALID_NAME;
	}
}

