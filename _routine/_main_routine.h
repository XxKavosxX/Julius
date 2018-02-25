/*
 * _main_routine.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef ROUTINE__MAIN_ROUTINE_H_
#define ROUTINE__MAIN_ROUTINE_H_
#define F_CPU 16000000UL
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include <stdio.h>


#define _set_bit(y, bit)         (y|= (1<<bit))
#define _clr_bit(y, bit)         (y&= ~(1<<bit))
#define _cpl_bit(y, bit)         (y^= (1<<bit))
#define _tst_bit(y, bit)         (y&(1<<bit))
#define _get_high_bits(y) ((y&0xF0)>>4)
#define _get_low_bits(y) (y&0x0F)


#define SENS_INPUT_ADDR 33
#define TCLD_INPUT_ADDR 34
#define REMOTE_OUTPUT_ADDR_1 35
#define REMOTE_OUTPUT_ADDR_2 36



void start_tools();
void  _device_resizable_list_test();

// void SelecionarDisp(char byte);
// void CalcularConsumo(char sensorCorrenteEnd);



char *FloatParaChar(char *buffer, double d, int precision);
char* InteiroParaChar(int numero);
char* LongParaChar(uint32_t numero);




#endif /* ROUTINE__MAIN_ROUTINE_H_ */
