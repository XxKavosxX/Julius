/*
 * _device_list.h
 *
 *  Created on: Apr 29, 2017
 *      Author: maike_rodrigo
 */

#ifndef DEVICE_LIST_H_
#define DEVICE_LIST_H_
#include "../includes/_device.h"
#include "../includes/_usart.h"

#define NUM_DEVICES 30

struct Node_device {
	struct Device *content;
	struct Node_device *_next_element;
};
struct Node_device* element_get_first();
struct Node_device* new_element(struct Device* content);
_Bool device_list_begin(struct Device* content);
_Bool device_append(struct Device* content);
_Bool device_delete(struct Device* content);
struct Node_device* device_search(uint8_t sensor,
		uint8_t control);
void element_print_list();
void element_print(struct Node_device* element);
#endif /* MATRIX__H_ */
