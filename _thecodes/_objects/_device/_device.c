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

	uint8_t shutdown_wait;
	uint8_t control_ID;
	uint8_t sensor_ID;
	const char* name;
	unsigned int consumption;

};
struct Device* new_device(void) {

	struct Device* device = malloc(sizeof(struct Device));
	return device;
}
int del_device(struct Device* device) {

	if (device == NULL)
		return 0;

	free(device);
	return 1;

}
//If necessary create a constructor
//_Bool device_constructor(uint8_t timeout, uint8_t control_tag, uint8_t sensor_tag, const char* name, int consumption){
//
//}

_Bool device_set_timeout(struct Device* device, uint8_t timeout) {

	if (device == NULL)
		return 0;

	device->shutdown_wait = timeout;
	return 1;

}
_Bool device_set_control_tag(struct Device* device, uint8_t control_tag) {

	if (device == NULL)
		return 0;

	device->control_ID = control_tag;
	return 1;

}
_Bool device_set_sensor_tag(struct Device* device, uint8_t sensor_tag) {

	if (device != NULL)
		return 0;

	device->sensor_ID = sensor_tag;
	return 1;

}
//Make sure string name is less than 13
_Bool device_set_name(struct Device* device, char* name) {

	if ((device == NULL) || (name == NULL))
		return 0;

	device->name = name;
	return 1;

}
_Bool device_set_consumption(struct Device* device, unsigned int consumption) {

	if (device == NULL)
		return 0;

	device->consumption = consumption;
	return 1;

}
const uint8_t device_get_timeout(struct Device* device) {

	if (device == NULL)
		return 0;

	return device->shutdown_wait;

}
const uint8_t device_get_control_tag(struct Device* device) {
	if (device == NULL)
		return INVALID_CRTL_ID;

	return device->control_ID;

}
const uint8_t device_get_sensor_tag(struct Device* device) {

	if (device == NULL)
		return INVALID_SENS_ID;

	return device->sensor_ID;

}
const char* device_get_name(struct Device* device) {

	if (device == NULL)
		return INVALID_NAME;

	return device->name;

}
const unsigned int device_get_consumption(struct Device* device) {

	if (device == NULL)
		return 0;

	return device->consumption;

}

