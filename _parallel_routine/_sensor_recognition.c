/*
 * _sensor_recognition.c
 *
 *  Created on: 15 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "_sensor_recognition.h"
uint8_t _sns_mask;
volatile uint8_t _last_sens_stt = 0x00;
volatile uint8_t _changed_to_up = 0x00;
volatile uint8_t _changed_to_down = 0x00;
ISR(INT0_vect){
	uint8_t _new_sens_stt = twi_read(_I2C_SENS_ADDR);

	if(_new_sens_stt != _I2C_INVALID_RETURN){
		_changed_to_up = _last_sens_stt & (~_new_sens_stt);
		_changed_to_down = (~_last_sens_stt) & (_new_sens_stt);
	}
}

/*ISR( INT0_vect) {
	sens_int_status(0);
	sei();

	uint8_t sensor_data = twi_read(_I2C_KEY_ADDR);

	if (sensor_data != _I2C_INVALID_RETURN) {
		usart_write_flash(PSTR("INT"));
		usart_send(sensor_data+48);
		usart_write_flash(PSTR("\n"));
		_sns_mask = sensor_data;
		//EIFR = (1 << INTF1);
	}
	//EIFR = (1 << INTF1);
	//_delay_ms(1000);
}*/
void sens_int_setup(uint8_t mode) {
	//disable RX-TX
	//UCSR0B = 0x00;
	//Clear  EIFR (External Interrupt Flag Register)
	EIFR = (1 << INTF0) /*| (1 << INTF0)*/;                  											//   |	ISC11 ISC10 |
										//Select INT type						                    //   |	 0		0   |  LOW -> INT
	EICRA = 0b00001111;		              															//   |	 0      1   |  ANY -> INT
	EIMSK = (1 << INT0) /*| (1 << INT0)*/;																//   |	 1      0   |  RISING ->INT
	sei();                                                                                          //   |   1      1   |  FALLING ->INT

}
void sens_int_status(uint8_t status) {
	//enable new interrupt
	if (status) {
		EIMSK |= (1 << INT0)/*|(1<<INT0)*/;
		//disable new interrupt
	} else {
		EIMSK &= ~(1 << INT0)/*|(1<<INT0)*/;
	}
}
