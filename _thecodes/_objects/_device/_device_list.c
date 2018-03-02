/*
 * _device_list.c
 *
 *  Created on: Apr 29, 2017
 *      Author: maike_rodrigo
 */
#include "../../includes/_device_list.h"

uint8_t DEVICE_LIST_SIZE;

static struct Device_list_node *first_device = NULL;
static struct Device_list_node *last_device = NULL;
static struct Device_list_node *previous_device = NULL;

struct Device_list_node {
	struct Device *node_device;
	struct Device_list_node *next_node;
};
struct Device_list_node *new_device_list_node(struct Device* device) {

	if (device == NULL)
		return NULL;

	struct Device_list_node *new_node_device = calloc(1,
			sizeof(struct Device_list_node));

	if (new_node_device == NULL)
		return NULL;

	new_node_device->node_device = device;
	new_node_device->next_node = NULL;
	return new_node_device;

}
int delete_device_list_node(struct Device_list_node *device_list_node) {

	if (device_list_node == NULL)
		return 0;

	if (device_list_node->node_device == NULL)
		return 0;

	free(device_list_node->node_device);
	free(device_list_node);
	return 1;

}
_Bool begin_device_list(struct Device *device) {

	if (first_device != NULL || device == NULL)
		return 0;

	first_device = new_device_list_node(device);
	last_device = first_device;
	DEVICE_LIST_SIZE = 1;
	return 1;

}
_Bool append_device(struct Device *device) {
	;
	if (first_device == NULL || device == NULL)
		return 0;

	struct Device_list_node *device_to_append = new_device_list_node(device);

	if (device_to_append == NULL
			|| search_device(get_device_sensor_id(device),
					get_device_control_id(device)) != NULL)
		return 0;

	last_device->next_node = device_to_append;
	last_device = device_to_append;
	DEVICE_LIST_SIZE++;
	return 1;

}
_Bool remove_device(struct Device *device) {

	if (device == NULL)
		return 0;

	struct Device_list_node *device_to_remove = search_device(
			get_device_sensor_id(device), get_device_control_id(device));

	if (device_to_remove == NULL) {

		return 0;

	} else if (first_device == device_to_remove) {

		struct Device_list_node *old_first = first_device->next_node;
		first_device->next_node = old_first->next_node;

		if (!delete_device_list_node(first_device))
			return 0;

		first_device = old_first;
		return 1;

	} else if (last_device == device_to_remove) {

		if (!delete_device_list_node(previous_device->next_node))
			return 0;

		previous_device->next_node = NULL;
		return 1;

	} else {

		previous_device->next_node = device_to_remove->next_node;
		return 1;
	}

}

struct Device_list_node *search_device(uint8_t sensor, uint8_t control) {

	if ((first_device == NULL) || (sensor < 0) || (control < 0))
		return NULL;

	struct Device_list_node *aux_device_node = first_device;
	previous_device = first_device;

	uint8_t counter = 0;

	while ((counter <= DEVICE_LIST_SIZE) && (aux_device_node != NULL)) {

		if (get_device_sensor_id(aux_device_node->node_device) == sensor
				&& get_device_control_id(aux_device_node->node_device)
						== control) {
			counter = 0;
			return aux_device_node;

		} else {

			previous_device = aux_device_node;
			aux_device_node = aux_device_node->next_node;

		}
		counter++;
	}

	return NULL;

}
struct Device *get_node_device(struct Device_list_node *node) {

	if (node == NULL)
		return NULL;

	struct Device *aux_node = search_device(
			get_device_sensor_id(node->node_device),
			get_device_control_id(node->node_device))->node_device;

	if (aux_node == NULL)
		return NULL;

	return aux_node;

}
