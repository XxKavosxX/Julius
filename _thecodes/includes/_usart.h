/*
 * _usart.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef THECODES_INCLUDES__USART_H_
#define THECODES_INCLUDES__USART_H_
#include "_main_routine.h"
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#define tam_vetor 5
#define conv_ascii 48

void usart_enable(uint16_t ubrr);
void usart_send(unsigned char dado);
unsigned char usart_receive();
void usart_write(char *c);
void usart_write_flash(const char *c);
/*void number_indentify(uint8_t valor, unsigned char *disp);*/




#endif /* THECODES_INCLUDES__USART_H_ */
