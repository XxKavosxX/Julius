/*
 * _matrix_.h
 *
 *  Created on: Apr 29, 2017
 *      Author: maike_rodrigo
 */

#ifndef MATRIX__H_
#define MATRIX__H_
#include "_device.h"
#include "../_micro_library/_usart.h"
struct Element {
	struct Device *content;
	struct Element *_next_element;
};
struct Element* element_get_first();
struct Element* new_element(struct Device* content);
_Bool element_list_begin(struct Device* content);
_Bool element_append(struct Device* content);
_Bool element_delete(struct Device* content);
struct Element* element_search(uint8_t sensor,
		uint8_t control);
void element_print_list();
void element_print(struct Element* element);
#endif /* MATRIX__H_ */
