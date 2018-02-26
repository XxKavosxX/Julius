/*
 * _keyboard.h
 *
 *  Created on: 11 de jun de 2017
 *      Author: mk
 */

#ifndef THECODES_INCLUDES__KEYBOARD_H_
#define THECODES_INCLUDES__KEYBOARD_H_
#include "_twi.h"
#include "_I2C_LCD16x2.h"
#include "_main_routine.h"

#define _incr_var(VAR, MAX)         if(VAR<MAX)VAR++;
#define _decr_var(VAR, MIN)         if(VAR>0 && VAR !=0) VAR--;


ISR(INT1_vect);

void key_data(uint8_t data);

void key_type1(void (**func)());

void key_int_setup(uint8_t mode);
void key_int_status(uint8_t status);
void set_key_max_col(uint8_t col);
void set_key_max_lin(uint8_t lin);
uint8_t get_key_lin();
uint8_t get_key_col();
void key_clear();

#endif /* THECODES_INCLUDES__KEYBOARD_H_ */
