/*
 * _views.c
 *
 *  Created on: 25 de jun de 2017
 *      Author: mk
 */

#include "../includes/_views.h"

char str2[13];

struct View {
	//ponteiro para funções
	void (**func)();
	//y position
	uint8_t type:2;
	uint8_t l_lin :2;
	//x position
	uint8_t h_col :4;
	//background text
	PGM_P const *background_P;
};

struct View* new_view(void) {
	struct View* view;
	view = calloc(1, sizeof(struct View));
	return view;
}
int del_view(struct View* view) {
	if (view != NULL) {
		free(view);
		return 1;
	} else {
		return 0;
	}
}
_Bool view_auto_print(struct View* view, uint8_t print_style) {
	if (view != NULL) {
		_window_setup(view->type, view->l_lin, view->h_col, view->background_P);
		return 1;
	} else {
		return 0;
	}

}

_Bool view_set_function(struct View* view, void (**function)()) {
	if (view != NULL) {
		view->func = function;
		return 1;
	} else {
		return 0;
	}
}
_Bool view_set_pos_and_type(struct View* view, uint8_t pos_type) {
	if (view != NULL) {
		view->type = 0x03 & pos_type;
		view->l_lin = (0x0C & pos_type)>>2;
		view->h_col = (0xF0 & pos_type)>>4;
		return 1;
	} else {
		return 0;
	}
}
_Bool view_set_backgroung(struct View* view, PGM_P const *bckgrnd) {
	if(view!= NULL) {
		view->background_P = bckgrnd;
		return 1;
	} else {
		return 0;
	}
}

