/*
 * _views.h
 *
 *  Created on: 25 de jun de 2017
 *      Author: mk
 */

#ifndef THECODES_INCLUDES__VIEWS_H_
#define THECODES_INCLUDES__VIEWS_H_

#include "../includes/_EEPROM.h"
#include "../includes/_view_printer.h"

struct View;
struct View* new_view(void);
int del_view(struct View* view);

_Bool view_auto_print(struct View* view, uint8_t print_style);
_Bool view_set_function(struct View* view, void (**function)());
_Bool view_set_pos_and_type(struct View* view, uint8_t pos_type);
_Bool view_set_backgroung(struct View* view, PGM_P const *bckgrnd);


#endif /* THECODES_INCLUDES__VIEWS_H_ */
