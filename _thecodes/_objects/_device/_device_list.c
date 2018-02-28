/*
 * _device_list.c
 *
 *  Created on: Apr 29, 2017
 *      Author: maike_rodrigo
 */
#include "../../includes/_device_list.h"

uint8_t LIST_SIZE;
uint8_t COUNT = 0;

static struct Node_device* first_device = NULL;
static struct Node_device* last_device = NULL;
static struct Node_device* previous_device = NULL;

struct Node_device* new_element(struct Device* device) {

	if (device == NULL)
		return NULL;

	struct Node_device* new_node_device = calloc(1, sizeof(struct Node_device));

	if (new_node_device == NULL)
		return NULL;

	new_node_device->content = device;
	new_node_device->_next_element = NULL;
	return new_node_device;

}
int del_element(struct Node_device* element) {

	if (element == NULL)
		return 0;

	if (element->content == NULL)
		return 0;

	free(element->content);
	free(element);
	return 1;

}
_Bool device_list_begin(struct Device* device) {

	if (first_device != NULL || device == NULL)
		return 0;

	first_device = new_element(device);
	last_device = first_device;
	LIST_SIZE = 1;
	return 1;

}
_Bool device_append(struct Device* device) {

	if (first_device == NULL || device == NULL)
		return 0;

	struct Node_device* device_to_append = new_element(device);

	if (device_to_append == NULL
			|| device_search(device_get_sensor_tag(device),
					device_get_control_tag(device)) != NULL)
		return 0;

	last_device->_next_element = device_to_append;
	last_device = device_to_append;
	LIST_SIZE++;
	return 1;

}
_Bool device_delete(struct Device* device) {

	if (device == NULL)
		return 0;

	struct Node_device* to_delete = device_search(device_get_sensor_tag(device),
			device_get_control_tag(device));

	if (to_delete == NULL) {

		return 0;

	} else if (first_device == to_delete) {

		struct Node_device* old_first = first_device->_next_element;
		first_device->_next_element = old_first->_next_element;

		if (!del_element(first_device))
			return 0;

		first_device = old_first;
		return 1;

	} else if (last_device == to_delete) {

		if (!del_element(previous_device->_next_element))
			return 0;

		previous_device->_next_element = NULL;
		return 1;

	} else {

		previous_device->_next_element = to_delete->_next_element;
		return 1;
	}

}

struct Node_device* device_search(uint8_t sensor, uint8_t control) {

	if (first_device == NULL || sensor < 0 || control < 0)
		return 0;

	struct Node_device* aux = first_device;
	previous_device = first_device;
	COUNT = 0;

	while ((COUNT <= NUM_DEVICES) && (aux != NULL)) {

		if (device_get_sensor_tag(aux->content) == sensor
				&& device_get_control_tag(aux->content) == control) {
			COUNT = 0;
			return aux;

		} else {

			previous_device = aux;
			aux = aux->_next_element;

		}
		COUNT++;
	}

	return NULL;

}
