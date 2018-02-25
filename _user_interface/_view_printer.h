/*
 * _view_printer.h
 *
 *  Created on: 25 de jun de 2017
 *      Author: mk
 */

#ifndef USER_INTERFACE__VIEW_PRINTER_H_
#define USER_INTERFACE__VIEW_PRINTER_H_

#include "../_external_devices_lib/_I2C_LCD16x2.h"

void _window_setup(uint8_t mode, uint8_t y_pos, uint8_t x_pos, PGM_P const *bckgrnd);

#endif /* USER_INTERFACE__VIEW_PRINTER_H_ */
