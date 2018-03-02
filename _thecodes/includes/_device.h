/*
 * _device.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef THECODES_INCLUDES__DEVICE_H_
#define THECODES_INCLUDES__DEVICE_H_

#include "_main_routine.h"

#define VOID PSTR("-------\0")
#define INVALID_SENS_ID 255
#define INVALID_CRTL_ID 255

struct Device;
struct Device *new_device(void);
int delete_device(struct Device *device);
_Bool set_device_shutdown_wait(struct Device *device, uint8_t timeout);
_Bool set_device_control_id(struct Device *device, uint8_t control_tag);
_Bool set_device_sensor_id(struct Device *device, uint8_t sensor_tag);
_Bool set_device_name(struct Device *device, uint8_t *name);
_Bool set_device_consumption(struct Device *device, unsigned int consumption);
const uint8_t get_device_shutdown_wait(struct Device *device);
const uint8_t get_device_control_id(struct Device *device);
const uint8_t get_device_sensor_id(struct Device *device);
const char *device_get_name(struct Device *device);
const unsigned int get_device_consumption(struct Device *device);





#endif /* THECODES_INCLUDES__DEVICE_H_ */
