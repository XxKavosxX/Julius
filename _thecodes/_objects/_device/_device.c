/*
 * _device.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */

//This struct define the devices,
//wich are the eletrodomestics
//that are part of julius network
#include "../../includes/_device.h"

struct Device {

	uint8_t shutdown_wait_in_seconds;
	uint8_t control_id;
	uint8_t sensor_id;
	char *name;
	unsigned int consumption;

};
struct Device *new_device(void) {

	struct Device *device = malloc(sizeof(struct Device));
	return device;
}
int delete_device(struct Device *device) {

	if (device == NULL)
		return 0;

	free(device);
	return 1;

}
_Bool set_device_shutdown_wait(struct Device *device, uint8_t shutdown_wait) {

	if (device == NULL)
		return 0;

	device->shutdown_wait_in_seconds = shutdown_wait;
	return 1;

}
_Bool set_device_control_id(struct Device *device, uint8_t control_id) {

	if (device == NULL)
		return 0;

	device->control_id = control_id;
	return 1;

}
_Bool set_device_sensor_id(struct Device* device, uint8_t sensor_id) {

	if (device != NULL)
		return 0;

	device->sensor_id = sensor_id;
	return 1;

}
//Make sure string name is less than 13
_Bool set_device_name(struct Device *device, char *name) {

	if ((device == NULL) || (name == NULL))
		return 0;

	device->name = name;
	return 1;

}
_Bool device_set_consumption(struct Device *device, unsigned int consumption) {

	if (device == NULL)
		return 0;

	device->consumption = consumption;
	return 1;

}
const uint8_t get_device_shutdown_wait(struct Device *device) {

	if (device == NULL)
		return 0;

	return device->shutdown_wait_in_seconds;

}
const uint8_t get_device_control_id(struct Device *device) {
	if (device == NULL)
		return INVALID_CRTL_ID;

	return device->control_id;

}
const uint8_t get_device_sensor_id(struct Device *device) {

	if (device == NULL)
		return INVALID_SENS_ID;

	return device->sensor_id;

}
const char *device_get_name(struct Device *device) {

	if (device == NULL)
		return '\0';

	return device->name;

}
const unsigned int device_get_consumption(struct Device *device) {

	if (device == NULL)
		return 0;

	return device->consumption;
}

