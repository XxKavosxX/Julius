/*
 * _x_viewer.c
 *
 *  Created on: 25 de jun de 2017
 *      Author: mk
 */

#include "_x_viewer.h"

static uint8_t line = 0;
static uint8_t col = 0;

static uint8_t CONTEXT = MAIN_MENU;

static uint8_t max_line = 0;
static uint8_t max_col = 0;

const char verCons[9] PROGMEM = "Consumo\0";
const char disp[11] PROGMEM = "Gerenciar\0";
const char config[12] PROGMEM = "Configurar\0";
const char hora[6] PROGMEM = "Hora";

PGM_P const mat_menuprinc[4] PROGMEM =
{
	verCons,
	disp,
	config,
	hora
};

//down, up, right, left, center
static void (*menu_func[5])() = {down, up, NULL, NULL, center };

	void up() {
		usart_write_flash(PSTR("up - 64"));
		_incr_var(line, max_line);
	}

	void down() {
		usart_write_flash(PSTR("down - 8"));
		_decr_var(line, 0);
	}

	void right() {
		usart_write_flash(PSTR("right - 128"));
		_incr_var(col, max_col);
	}

	void left() {
		usart_write_flash(PSTR("left - 16"));
		_decr_var(col, 0);
	}

	void center() {
		usart_write_flash(PSTR("center - 32"));
	}

	void View() {

		key_type1(menu_func);
		line = 0;
		col = 0;
		max_line = 3;
		max_col = 0;
		Show(mat_menuprinc);
	}

	void Show(PGM_P const **bckgrnd) {
		switch (CONTEXT) {
		case 1:
			usart_write_flash(PSTR("Case 1:"));
			lcd_clear();

			if (line % 2 == 0) {
				if (max_line != 0) {
					if ((line == max_line)) {



					} else {




					}
				} else {

				}
			} else {
				//if line is equal to 0

			}
			break;
		}
	}

