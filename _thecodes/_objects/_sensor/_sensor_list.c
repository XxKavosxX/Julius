/*
 * _sensor_list.c
 *
 *  Created on: 24 de jun de 2017
 *      Author: mk
 */

#include "../../includes/_sensor_list.h"

uint8_t SENSOR_LIST_SIZE;

static struct Sensor_list_node *first_sensor = NULL;
static struct Sensor_list_node *last_sensor = NULL;
static struct Sensor_list_node *previous_sensor = NULL;

struct Sensor_list_node {
	struct Sensor *node_sensor;
	struct Sensor_list_node *next_node;
};
struct Sensor_list_node *new_sensor_list_node(struct Sensor *sensor) {

	if (sensor == NULL)
		return NULL;

	struct Sensor_list_node *new_node_sensor = calloc(1, sizeof(struct Sensor_list_node));

	if (new_node_sensor == NULL)
		return NULL;

	new_node_sensor->node_sensor = sensor;
	new_node_sensor->next_node = NULL;
	return new_node_sensor;

}
int delete_sensor_list_node(struct Sensor_list_node *sensor_list_node) {

	if (sensor_list_node == NULL)
		return 0;

	if (sensor_list_node->node_sensor == NULL)
		return 0;

	free(sensor_list_node->node_sensor);
	free(sensor_list_node);
	return 1;

}

_Bool begin_sensor(struct Sensor *sensor) {

	if (first_sensor != NULL || sensor == NULL)
		return 0;

	first_sensor = new_sensor_list_node(sensor);
	last_sensor = first_sensor;
	SENSOR_LIST_SIZE = 1;
	return 1;

}
_Bool append_sensor(struct Sensor *sensor) {

	if (first_sensor == NULL || sensor == NULL)
		return 0;

	struct Sensor_list_node *sensor_to_append = new_sensor_list_node(sensor);

	if (sensor_to_append == NULL || search_sensor(get_sensor_plugged_pin(sensor)) != NULL)
		return 0;

	last_sensor->next_node = sensor_to_append;
	last_sensor = sensor_to_append;
	SENSOR_LIST_SIZE++;
	return 1;

}
_Bool remove_sensor(struct Sensor *sensor) {

	if (sensor == NULL)
		return 0;

	struct Sensor_list_node *sensor_to_remove = search_sensor(get_sensor_plugged_pin(sensor));
	if (sensor_to_remove == NULL) {

		return 0;

	} else if (first_sensor == sensor_to_remove) {

		struct Sensor_list_node *old_first = first_sensor->next_node;
		first_sensor->next_node = old_first->next_node;

		if (!delete_sensor_list_node(first_sensor))
			return 0;

		first_sensor = old_first;
		return 1;

	} else if (last_sensor == sensor_to_remove) {

		if (!delete_sensor_list_node(previous_sensor->next_node))
			return 0;

		previous_sensor->next_node = NULL;
		return 1;

	} else {

		previous_sensor->next_node = sensor_to_remove->next_node;
		return 1;
	}

}

struct Sensor_list_node *search_sensor(uint8_t pin) {

	if ((first_sensor == NULL) && (pin < 0))
		return NULL;

	struct Sensor_list_node *aux_sensor_node = first_sensor;
	previous_sensor = first_sensor;

	uint8_t counter=0;

	while ((counter <= SENSOR_LIST_SIZE) && (aux_sensor_node != NULL)) {

		if (get_sensor_plugged_pin(aux_sensor_node->node_sensor) == pin) {

			counter = 0;
			return aux_sensor_node;

		} else {

			previous_sensor = aux_sensor_node;
			aux_sensor_node = aux_sensor_node->next_node;


		}

		counter++;
	}

	return NULL;
}

