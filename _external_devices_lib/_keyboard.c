/*
 * _keyboard.c
 *
 *  Created on: 11 de jun de 2017
 *      Author: mk
 */
#include "_keyboard.h"

volatile uint8_t keyboard_data;

//pointer to btn functions
void (**key_func)() = {NULL};

ISR( INT1_vect) {
	key_int_status(0);
	sei();
	keyboard_data = twi_read(_I2C_KEY_ADDR);
	if (keyboard_data != _I2C_INVALID_RETURN) {
		usart_write_flash(PSTR("INT - "));
		usart_send(keyboard_data + 48);
		usart_write_flash(PSTR("\n"));
		uint8_t _btn_data = keyboard_data;
		key_data(_btn_data);
		//EIFR = (1 << INTF1);
	}
	key_int_status(1);
}
void key_data(uint8_t data) {

	switch (keyboard_data) {
	case 1:
		usart_write_flash(PSTR("undefined - 1"));
		break;
	case 2:
		usart_write_flash(PSTR("back - 2"));
		break;
	case 4:
		usart_write_flash(PSTR("undefined - 4"));
		break;
	case 8:
		key_func[0]();
		//usart_write_flash(PSTR("down - 8"));
		//_decr_var(COUNT_LIN, 0);
		break;
	case 16:
		key_func[3]();
		//usart_write_flash(PSTR("left - 16"));
		//_decr_var(COUNT_COL, 0);
		break;
	case 32:
		key_func[4]();
		//usart_write_flash(PSTR("center - 32"));
		break;
	case 64:
		key_func[1]();
		//usart_write_flash(PSTR("up - 64"));
		//_incr_var(COUNT_LIN, MAX_COL);
		break;
	case 128:
		key_func[2]();
		//usart_write_flash(PSTR("right - 128"));
		//_incr_var(COUNT_COL, MAX_LIN);
		break;
	}
	usart_write_flash(PSTR("\n"));
}
void key_type1(void (**func)()) {
	key_func = func;
}

void key_int_setup(uint8_t mode) {
	//disable RX-TX
	//UCSR0B = 0x00;
	//Clear  EIFR (External Interrupt Flag Register)
	EIFR = (1 << INTF1) /*| (1 << INTF0)*/;              //   |	ISC11 ISC10 |
	//Select INT type	        //   |	 0		0   |  LOW -> INT
	EICRA = 0b00001000;		              	//   |	 0      1   |  ANY -> INT
	EIMSK = (1 << INT1) /*| (1 << INT0)*/;	//   |	 1      0   |  RISING ->INT
	sei();
	//   |   1      1   |  FALLING ->INT

}
void key_int_status(uint8_t status) {
	//enable new interrupt
	if (status) {
		EIMSK |= (1 << INT1)/*|(1<<INT0)*/;
		//disable new interrupt
	} else {
		EIMSK &= ~(1 << INT1)/*|(1<<INT0)*/;
	}
}
/*void set_key_max_lin(uint8_t lin){
 MAX_LIN = lin;
 }
 void set_key_max_col(uint8_t col){
 MAX_COL = col;
 }

 uint8_t get_key_lin(){
 return COUNT_LIN;
 }
 uint8_t get_key_col(){
 return COUNT_COL;
 }
 void key_clear(){
 COUNT_COL = 0;
 COUNT_LIN = 0;
 }*/
