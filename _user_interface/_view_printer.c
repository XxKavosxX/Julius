/*
 * _view_printer.c
 *
 *  Created on: 25 de jun de 2017
 *      Author: mk
 */

#include "_view_printer.h"

uint8_t count_lin;
uint8_t count_col;
uint8_t MAX_LIN;
uint8_t MAX_COL;
char str[13];

const char verCons2[9] PROGMEM = "Consumo\0";
const char disp2[11] PROGMEM = "Gerenciar\0";
const char config2[12] PROGMEM = "Configurar\0";
const char hora2[6] PROGMEM = "Hora";
//void (*p_menu_princ[4])() = {Construtor_VerConsumo, Construtor_Dispositivos, Construtor_Configurar, Construtor_Hora};

PGM_P const mat_menuprinc2[4] PROGMEM = {
    verCons2,
    disp2,
    config2,
    hora2
};


void _window_setup(uint8_t mode, uint8_t y_pos, uint8_t x_pos, PGM_P const *bckgrnd) {
			switch (mode) {
				case 0:
				//single space
				if (count_lin%2 == 0) {
					PGM_P progmem_P;
					memcpy_P( &progmem_P, &bckgrnd[1], sizeof(PGM_P));
					strncpy_P(str, progmem_P, 13);
					lcd_set_cursor(y_pos, x_pos);
					lcd_write(str);
				}
				break;
			}
		}
