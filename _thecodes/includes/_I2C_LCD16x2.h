/*
 * _I2C_LCD16x2.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef THECODES_INCLUDES__I2C_LCD16X2_H_
#define THECODES_INCLUDES__I2C_LCD16X2_H_
#include "../includes/_main_routine.h"
#include "../includes/_twi.h"
#define RS 1
#define EN 0
//#define _I2C_LCD_ADDR 32
void lcd_pulse_enable();
void lcd_send_command(unsigned char command, char operation);
void lcd_start();
void lcd_write(char *c);
void lcd_move_text(unsigned char direction);
void lcd_write_flash(const char *c);
void identificar_numeros(unsigned int value, unsigned char *disp);
void lcd_set_cursor(unsigned char line, unsigned char colun);
void lcd_enable_cursor();
void lcd_disable_cursor();
void lcd_return_cursor();
void lcd_cursor_mv_left();
void lcd_cursor_mv_right();
void lcd_cursor_set_type(unsigned char type);
void lcd_clear();




#endif /* THECODES_INCLUDES__I2C_LCD16X2_H_ */
