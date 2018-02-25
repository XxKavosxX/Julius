/*
 * _device.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */

//This struct define the devices,
//wich are the eletrodomestics
//that are part of julius network

#include "_device.h"

struct Device {
	uint8_t timeout;
	uint8_t control_tag;
	uint8_t sensor_tag;
	const char* name;
	unsigned int consumption;
};
struct Device* new_device(void) {
	struct Device* device;
	device = malloc(sizeof(struct Device));
	return device;
}
int del_device(struct Device* device) {
	if (device != NULL) {
		free(device);
		return 1;
	} else {
		return 0;
	}
}
//If necessary create a constructor
//_Bool device_constructor(uint8_t timeout, uint8_t control_tag, uint8_t sensor_tag, const char* name, int consumption){
//
//}

_Bool device_set_timeout(struct Device* device, uint8_t timeout) {
	if (device != NULL) {
		device->timeout = timeout;
		return 1;
	} else {
		return 0;
	}
}
_Bool device_set_control_tag(struct Device* device, uint8_t control_tag) {
	if (device != NULL) {
		device->control_tag = control_tag;
		return 1;
	} else {
		return 0;
	}
}
_Bool device_set_sensor_tag(struct Device* device, uint8_t sensor_tag) {
	if (device != NULL) {
		device->sensor_tag = sensor_tag;
		return 1;
	} else {
		return 0;
	}
}
//Make sure string name is less than 13
_Bool device_set_name(struct Device* device, char* name) {
	if (device != NULL && name != NULL) {
		device->name = name;
		return 1;
	} else {
		return 0;
	}
}
_Bool device_set_consumption(struct Device* device, unsigned int consumption) {
	if (device != NULL) {
		device->consumption = consumption;
		return 1;
	} else {
		return 0;
	}
}
const uint8_t device_get_timeout(struct Device* device) {
	if (device != NULL) {
		return device->timeout;
	} else {
		return 0;
	}
}
const uint8_t device_get_control_tag(struct Device* device) {
	if (device != NULL) {
		return device->control_tag;
	} else {
		return INVALID_CRTL_TAG;
	}
}
const uint8_t device_get_sensor_tag(struct Device* device) {
	if (device != NULL) {
		return device->sensor_tag;
	} else {
		return INVALID_SENS_TAG;
	}
}
const char* device_get_name(struct Device* device) {
	if (device != NULL) {
		return device->name;
	} else {
		return INVALID_NAME;
	}
}
const unsigned int device_get_consumption(struct Device* device) {
	if (device != NULL) {
		return device->consumption;
	} else {
		return 0;
	}
}

