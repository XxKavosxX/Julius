/*
 * _sensor_matrix.c
 *
 *  Created on: 24 de jun de 2017
 *      Author: mk
 */

#include "_sensor_matrix.h"

uint8_t LIST_SIZE;
uint8_t ATTEMPTS = 0;
static struct Unit* _first_unit = NULL;
static struct Unit* _last_unit = NULL;
static struct Unit* _previous_unit = NULL;
struct Unit* new_unit(struct Sensor* content) {
	if (content != NULL) {
		struct Unit* unit;
		unit = calloc(1, sizeof(struct Unit));
		unit->content = content;
		unit->_next_unit = NULL;
		return unit;
	} else {
		return NULL;
	}
}
int del_unit(struct Unit* unit) {
	if (unit != NULL) {
		if (unit->content != NULL) {
			free(unit->content);
		}
		free(unit);
		return 1;
	} else {
		return 0;
	}
}
struct Unit* unit_get_first() {
	return _first_unit;
}
_Bool unit_list_begin(struct Sensor* content) {
	usart_write_flash(PSTR("Function - list begin\n"));
	unit_print(_first_unit);
	if ((content != NULL) && (_first_unit == NULL)) {
		_first_unit = new_unit(content);
		if (_first_unit != NULL) {
			usart_write_flash(PSTR("\t   list begin - stating list\n"));
			//printf("\t   list begin - started list\n");
			_last_unit = _first_unit;
			LIST_SIZE = 1;
			return 1;
		} else {
			usart_write_flash(PSTR("\t   list begin - has begun list\n"));
			return 0;
		}
	} else {
		return 0;
	}

}
_Bool unit_append(struct Sensor* content) {
	usart_write_flash(PSTR("Function - append unit\n"));

	if ((content != NULL) && (_first_unit != NULL)) {
		usart_write_flash(PSTR("           append unit - appended\n"));
		struct Unit* unit_to_append = new_unit(content);
		if ((unit_to_append != NULL)&&(unit_search(sensor_get_pin(content))==NULL)) {
			//printf("\t   append_unit - appended\n");
			//The old last unit in list point to the new last unit(appendend)
			_last_unit->_next_unit = unit_to_append;
			//The new last unit is unit_to_append
			_last_unit = unit_to_append;
			//unit_print(unit_to_append);
			LIST_SIZE++;
			return 1;
		}
	} else {
		usart_write_flash(PSTR("Function - append unit - not appended"));
		return 0;
	}
	return 0;
}
_Bool unit_delete(struct Sensor* content) {
	usart_write_flash(PSTR("Function - delete unit\n"));
	if (content != NULL) {
//Search for unit
		struct Unit* to_delete = unit_search(sensor_get_pin(content));
//If found, check validity
		if (to_delete == NULL) {
			usart_write_flash(PSTR("\t   delete unit - invalid unit\n"));
			return 0;
//If is the first
		} else if (_first_unit == to_delete) {
			usart_write_flash(PSTR("\t   delete unit - first unit\n"));
			struct Unit* old_first = _first_unit->_next_unit;
			_first_unit->_next_unit = old_first->_next_unit;

			if (del_unit(_first_unit)) {
				_first_unit = old_first;
				return 1;
			} else {
				return 0;
			}
//If is the last
		} else if (_last_unit == to_delete) {
			usart_write_flash(PSTR("\t   delete unit - last unit\n"));
			if (del_unit(_previous_unit->_next_unit)) {
				_previous_unit->_next_unit = NULL;
				return 1;
			} else {
				return 0;
			}
//If is in the middle
		} else {
			usart_write_flash(PSTR("\t   delete unit - middle unit\n"));
			_previous_unit->_next_unit = to_delete->_next_unit;
			return 1;
		}
	}
	return 0;

}

struct Unit* unit_search(uint8_t pin) {

//printf("Function - search unit\n");
	if ((pin >= 0) && (_first_unit != NULL) && (ATTEMPTS <= 15)) {

		struct Unit* aux = _first_unit;
		_previous_unit = _first_unit;
		while ((ATTEMPTS <= 15)&&(aux!=NULL)) {

			if (sensor_get_pin(aux->content) == pin) {
				usart_write_flash(PSTR("\t   search unit - unit found\n"));
				ATTEMPTS = 0;
				return aux;

			} else {
				_previous_unit = aux;
				aux = aux->_next_unit;
				usart_write_flash(PSTR("\t   search unit - unit unfound\n"));

			}
			ATTEMPTS++;
		}
	}
	return NULL;
}
void unit_print_list() {
	struct Unit* aux = _first_unit;
	while (aux != NULL) {
		if (aux != NULL) {
			usart_write_flash(PSTR("Function - print list "));
			usart_write_flash(PSTR("{   "));

			usart_write_flash(PSTR("Pin = "));
			usart_send(sensor_get_pin(aux->content) + 48);
			usart_write_flash(PSTR(" "));
			usart_write_flash(PSTR("Status = "));
			usart_send(sensor_get_status(aux->content) + 48);
			usart_write_flash(PSTR(" "));
			usart_write_flash(PSTR("Name = "));
			usart_write(sensor_get_name(aux->content));
			usart_write_flash(PSTR("   }"));
			usart_send('\n');
			aux = aux->_next_unit;
		}
	}
}
void unit_print(struct Unit* unit) {

	if (unit != NULL) {
		usart_write_flash(PSTR("Function - print unit "));
					usart_write_flash(PSTR("{   "));

					usart_write_flash(PSTR("Pin = "));
					usart_send(sensor_get_pin(unit->content) + 48);
					usart_write_flash(PSTR(" "));
					usart_write_flash(PSTR("Status = "));
					usart_send(sensor_get_status(unit->content) + 48);
					usart_write_flash(PSTR(" "));
					usart_write_flash(PSTR("Name = "));
					usart_write(sensor_get_name(unit->content));
					usart_write_flash(PSTR("   }"));
					usart_send('\n');
	}
}
