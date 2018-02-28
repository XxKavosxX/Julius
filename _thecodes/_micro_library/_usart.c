/*
 * _usart.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../includes/_usart.h"

void usart_enable(uint16_t ubrr) {

	UBRR0H = (unsigned char) (ubrr >> 8);     //take ATmega328P datasheet
	UBRR0L = (unsigned char) ubrr;

	UCSR0A = 0;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << USBS0) | (3 << UCSZ00);

}
void usart_send(unsigned char dado) {

	while (!(UCSR0A & (1 << UDRE0)))
		;
	UDR0 = dado;
}
unsigned char usart_receive() {

	while (!(UCSR0A & (1 << RXC0)))
		;
	return UDR0;
}
void usart_write(char *c) {

	for (; *c != 0; c++)
		usart_send(*c);

}
void usart_write_flash(const char *c) {

	for (; pgm_read_byte(&(*c)) != 0; c++)
		usart_send(pgm_read_byte(&(*c)));

}
/*void number_indentify(uint8_t valor, unsigned char *disp) {
	
	unsigned char n;
	for (n = 0; n < tam_vetor; n++)
		disp[n] = 0 + conv_ascii;
	do {
		*disp = (valor % 10) + conv_ascii;
		valor /= 10;
		disp++;
	} while (valor != 0);
}*/

