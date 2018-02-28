/*
 * _sensor_list.c
 *
 *  Created on: 24 de jun de 2017
 *      Author: mk
 */

#include "../../includes/_sensor_list.h"

uint8_t LIST_SIZE;
uint8_t ATTEMPTS = 0;

static struct Node_sens* first_sens = NULL;
static struct Node_sens* last_sens = NULL;
static struct Node_sens* previous_sens = NULL;

struct Node_sens* new_sens_node(struct Sensor* sens) {

	if (sens == NULL)
		return NULL;

	struct Node_sens* new_node_sens = calloc(1, sizeof(struct Node_sens));

	if (new_node_sens == NULL)
		return NULL;

	new_node_sens->content = sens;
	new_node_sens->_next_unit = NULL;
	return new_node_sens;

}
int del_sens_node(struct Node_sens* sens) {

	if (sens == NULL)
		return 0;

	if (sens->content == NULL)
		return 0;

	free(sens->content);
	free(sens);
	return 1;

}

_Bool sens_list_begin(struct Sensor* sens) {

	if (first_sens != NULL || sens == NULL)
		return 0;

	first_sens = new_sens_node(sens);
	last_sens = first_sens;
	LIST_SIZE = 1;
	return 1;

}
_Bool sens_append(struct Sensor* sens) {

	if (first_sens == NULL || sens == NULL)
		return 0;

	struct Node_sens* sens_to_append = new_sens_node(sens);

	if (sens_to_append == NULL || sens_search(sensor_get_pin(sens)) != NULL)
		return 0;

	last_sens->_next_unit = sens_to_append;
	last_sens = sens_to_append;
	LIST_SIZE++;
	return 1;

}
_Bool sens_delete(struct Sensor* sens) {

	if (sens == NULL)
		return 0;

	struct Node_sens* sens_to_delete = sens_search(sensor_get_pin(sens));
	if (sens_to_delete == NULL) {

		return 0;

	} else if (first_sens == sens_to_delete) {

		struct Node_sens* old_first = first_sens->_next_unit;
		first_sens->_next_unit = old_first->_next_unit;

		if (!del_sens_node(first_sens))
			return 0;

		first_sens = old_first;
		return 1;

	} else if (last_sens == sens_to_delete) {

		if (!del_sens_node(previous_sens->_next_unit))
			return 0;

		previous_sens->_next_unit = NULL;
		return 1;

	} else {

		previous_sens->_next_unit = sens_to_delete->_next_unit;
		return 1;
	}

}

struct Node_sens* sens_search(uint8_t pin) {

	if ((first_sens == NULL) && (pin < 0))
		return 0;

	struct Node_sens* aux = first_sens;
	previous_sens = first_sens;

	ATTEMPTS = 0;

	while ((ATTEMPTS <= NUM_SENSORS) && (aux != NULL)) {

		if (sensor_get_pin(aux->content) == pin) {

			ATTEMPTS = 0;
			return aux;

		} else {

			previous_sens = aux;
			aux = aux->_next_unit;


		}

		ATTEMPTS++;
	}

	return NULL;
}

