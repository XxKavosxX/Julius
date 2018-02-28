/*
 * _twi.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */

#include "../includes/_twi.h"

unsigned char new_data;
uint8_t new_address;
volatile uint8_t bus_availability = ISREADY;
volatile uint8_t iterations = 0;
volatile uint8_t step = 0;

_Bool twi_status() {
	return bus_availability;
}
void twi_enable_pull_ups(void) {

	DDRC &= ~((1 << 4) | (1 << 5));
	PORTC = (1 << 4) | (1 << 5);

}
void twi_disable_pull_ups(void) {

	DDRC &= ~((1 << 4) | (1 << 5));
	PORTC &= ~(1 << 4) | (1 << 5);
}
void twi_enable(void) {

	sei();
	TWBR = ((F_CPU / FREQ_SCL) - 16) / 2;
	TWSR |= 0x00;
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWIE) | (1 << TWEA);

}
void twi_disable(void) {

	TWCR &= ~((1 << TWINT) | (1 << TWEN) | (1 << TWIE));

}

_Bool twi_write(unsigned char i2c_address, unsigned char data) {

	iterations = 0;
	new_data = data;
	new_address = (i2c_address << 1);
	_send_start_cond()
	;
	step = 1;

	do {

		_delay_us(25);
	} while ((bus_availability == UNREADY) || (step < 2));

	if (step == 4) {
		return true;
	}
	return false;
}
unsigned char twi_read(unsigned char i2c_address) {

	if (bus_availability != ISREADY)
		return _I2C_INVALID_RETURN;

	iterations = 0;
	new_data = 0x00;
	new_address = (i2c_address << 1) + 1;
	_send_start_cond()
	;
	step = 1;

	do {
		_delay_us(25);
	} while ((bus_availability == UNREADY) || (step < 2));

	if (step == 4) {

		return new_data;

	} else {

		return _I2C_INVALID_RETURN;
	}
}
ISR(TWI_vect) {
	switch (TWSR & 0xF8) {
	case TW_START:

		bus_availability = UNREADY;
		iterations++;
		step = 2;
		TWDR = new_address;
		_clr_start_bit()
		;
		break;

	case TW_MT_SLA_ACK:

		iterations++;
		step = 3;
		TWDR = new_data;
		break;

	case TW_MT_SLA_NACK:

		if (iterations < _I2C_MAX_ATTEMPTS) {
			iterations++;
			_send_start_cond()
			;
		} else {
			_send_stop_cond()
			;
			bus_availability = ISREADY;
		}
		break;

	case TW_MT_DATA_ACK:

		iterations++;
		step = 4;
		_send_stop_cond()
		;
		bus_availability = ISREADY;
		break;

	case TW_MT_DATA_NACK:

		iterations++;
		TWDR = new_data;
		step = 3;
		break;

	case TW_MR_SLA_ACK:

		iterations++;
		step = 3;
		TWCR &= ~(1 << TWEA);
		break;

	case TW_MR_DATA_NACK:

		iterations++;
		new_data = TWDR;
		step = 4;
		_send_stop_cond()
		;
		_delay_ms(100);
		bus_availability = ISREADY;
		break;

	case TW_MR_SLA_NACK:

		if (iterations < _I2C_MAX_ATTEMPTS) {
			iterations++;
			_send_start_cond()
			;
		} else {
			_send_stop_cond()
			;
			bus_availability = ISREADY;
		}
		break;

	case TW_MR_DATA_ACK:

		if (iterations < _I2C_MAX_ATTEMPTS) {
			iterations++;
			_send_start_cond()
			;
		} else {
			_send_start_cond()
			;
			bus_availability = ISREADY;
		}
		break;

	case TW_BUS_ERROR:

		iterations++;
		_send_start_cond()
		;
		break;

	case TW_REP_START:

		iterations++;
		_clr_start_bit()
		;
		break;
	}
	_next_step()
	;
}

