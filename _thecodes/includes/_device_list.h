/*
 * _device_list.h
 *
 *  Created on: Apr 29, 2017
 *      Author: maike_rodrigo
 */

#ifndef DEVICE_LIST_H_
#define DEVICE_LIST_H_
#include "../includes/_device.h"

struct Device_list_node;
struct Device_list_node *new_device_list_node(struct Device *device);
int delete_device_list_node(struct Device_list_node *device_list_node);
_Bool begin_device_list(struct Device *device);
_Bool append_device(struct Device *device);
_Bool remove_device(struct Device *device);
struct Device_list_node *search_device(uint8_t sensor,
		uint8_t control);
#endif /* MATRIX__H_ */
