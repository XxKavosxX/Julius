/*
 * _matrix_.c
 *
 *  Created on: Apr 29, 2017
 *      Author: maike_rodrigo
 */
#include "../includes/_matrix_.h"
uint8_t LIST_SIZE;
uint8_t COUNT = 0;
static struct Element* _first_element = NULL;
static struct Element* _last_element = NULL;
static struct Element* _previous_element = NULL;
struct Element* new_element(struct Device* content) {
	if (content != NULL) {
		struct Element* element;
		element = calloc(1, sizeof(struct Element));
		element->content = content;
		element->_next_element = NULL;
		return element;
	} else {
		return NULL;
	}
}
int del_element(struct Element* element) {
	if (element != NULL) {
		if (element->content != NULL) {
			free(element->content);
		}
		free(element);
		return 1;
	} else {
		return 0;
	}
}
struct Element* element_get_first() {
	return _first_element;
}
_Bool element_list_begin(struct Device* content) {
	//printf("Function - list begin\n");
	if (content != NULL && _first_element == NULL) {
		_first_element = new_element(content);
		if (_first_element != NULL) {
			//printf("\t   list begin - started list\n");
			_last_element = _first_element;
			LIST_SIZE = 1;
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}

}
_Bool element_append(struct Device* content) {
	printf("Function - append element\n");

	if (content != NULL && _first_element != NULL) {
		printf("           append element - appended\n");
		struct Element* element_to_append = new_element(content);
		if ((element_to_append != NULL)
				&& (element_search(device_get_sensor_tag(content),
						device_get_control_tag(content)) == NULL)) {
			//printf("\t   append_element - appended\n");
			//The old last element in list point to the new last element(appendend)
			_last_element->_next_element = element_to_append;
			//The new last element is element_to_append
			_last_element = element_to_append;
			LIST_SIZE++;
			return 1;
		}
	} else {
		printf("Function - append element - not appended");
		return 0;
	}
	return 0;
}
_Bool element_delete(struct Device* content) {
	printf("Function - delete element\n");
	if (content != NULL) {
//Search for element
		struct Element* to_delete = element_search(
				device_get_sensor_tag(content),
				device_get_control_tag(content));
//If found, check validity
		if (to_delete == NULL) {
			printf("\t   delete element - invalid element\n");
			return 0;
//If is the first
		} else if (_first_element == to_delete) {
			printf("\t   delete element - first element\n");
			struct Element* old_first = _first_element->_next_element;
			_first_element->_next_element = old_first->_next_element;

			if (del_element(_first_element)) {
				_first_element = old_first;
				return 1;
			} else {
				return 0;
			}
//If is the last
		} else if (_last_element == to_delete) {
			printf("\t   delete element - last element\n");
			if (del_element(_previous_element->_next_element)) {
				_previous_element->_next_element = NULL;
				return 1;
			} else {
				return 0;
			}
//If is in the middle
		} else {
			printf("\t   delete element - middle element\n");
			_previous_element->_next_element = to_delete->_next_element;
			return 1;
		}
	}
	return 0;

}

struct Element* element_search(uint8_t sensor, uint8_t control) {

//printf("Function - search element\n");
	if ((sensor >= 0) && (control >= 0) && (_first_element != NULL)
			&& (COUNT <= 15)) {

		struct Element* aux = _first_element;
		_previous_element = _first_element;
		while ((COUNT <= 15) && (aux != NULL)) {

			if (device_get_sensor_tag(aux->content) == sensor
					&& device_get_control_tag(aux->content) == control) {
				printf("\t   search element - element found\n");
				COUNT = 0;
				return aux;

			} else {
				_previous_element = aux;
				aux = aux->_next_element;
				printf("\t   search element - element unfound\n");

			}
			COUNT++;
		}
	}
	return NULL;
}
void element_print_list() {
	struct Element* aux = _first_element;
	usart_write_flash(PSTR("Function - print_list \n"));
	while (aux != NULL) {
		if (aux != NULL) {

					usart_write_flash(PSTR("{ "));

					usart_write_flash(PSTR("Control = "));
					usart_send(device_get_control_tag(aux->content) + 48);
					usart_write_flash(PSTR(" "));

					usart_write_flash(PSTR("Sensor = "));
					usart_send(device_get_sensor_tag(aux->content) + 48);
					usart_write_flash(PSTR(" "));

					usart_write_flash(PSTR("Timeout = "));
					usart_send(device_get_timeout(aux->content) + 48);
					usart_write_flash(PSTR(" "));

					usart_write_flash(PSTR("Consumption = "));
					usart_send(device_get_consumption(aux->content) + 48);
					usart_write_flash(PSTR(" "));

					usart_write_flash(PSTR("Name = "));
					usart_write(device_get_name(aux->content));
					usart_write_flash(PSTR(" }"));
					usart_send('\n');
			aux = aux->_next_element;
		}
	}
}
void element_print(struct Element* element) {
	usart_write_flash(PSTR("Function - print_element "));
	if (element != NULL) {

		usart_write_flash(PSTR("{ "));

		usart_write_flash(PSTR("Control = "));
		usart_send(device_get_control_tag(element->content) + 48);
		usart_write_flash(PSTR(" "));

		usart_write_flash(PSTR("Sensor = "));
		usart_send(device_get_sensor_tag(element->content) + 48);
		usart_write_flash(PSTR(" "));

		usart_write_flash(PSTR("Timeout = "));
		usart_send(device_get_timeout(element->content) + 48);
		usart_write_flash(PSTR(" "));
		usart_write_flash(PSTR("Consumption = "));
		usart_send(device_get_consumption(element->content) + 48);
		usart_write_flash(PSTR(" "));

		usart_write_flash(PSTR("Name = "));
		usart_write(device_get_name(element->content));
		usart_write_flash(PSTR(" }"));

		usart_send('\n');
	}
}
