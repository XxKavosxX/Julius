/*
 * _twi.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef MICRO_LIBRARY__TWI_H_
#define MICRO_LIBRARY__TWI_H_
#include "../_routine/_main_routine.h"
#include "../_micro_library/_usart.h"

#define FREQ_SCL 100000UL
#define _send_start_cond()		TWCR |= (1<<TWSTA);
#define _send_stop_cond()		TWCR |= (1<<TWSTO);
#define _clr_start_bit()		TWCR &= ~(1<<TWSTA);
#define _next_step()			TWCR |= (1<<TWINT);
#define ISREADY 1
#define UNREADY 0

#define _I2C_ATTEMPTS 20
#define _I2C_LCD_ADDR 32
#define _I2C_SENS_ADDR 33
#define _I2C_KEY_ADDR 34
#define _I2C_INVALID_RETURN -12

ISR(TWI_vect);

_Bool twi_get_status();
void twi_enable(void);
void twi_disable(void);
void twi_enable_pull_ups();
void twi_disable_pull_ups(void);
_Bool twi_write(unsigned char i2c_address,unsigned char data);
unsigned char twi_read(unsigned char i2c_address);




#endif /* MICRO_LIBRARY__TWI_H_ */