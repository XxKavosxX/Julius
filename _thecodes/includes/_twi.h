/*
 * _twi.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef THECODES_INCLUDES__TWI_H_
#define THECODES_INCLUDES__TWI_H_

#include <avr/interrupt.h>
//#include <avr/iom328p.h>
#include <stdbool.h>
#include <stdint.h>
#include <util/delay.h>
#include <util/twi.h>

#define FREQ_SCL 100000UL
#define _send_start_cond()		TWCR |= (1<<TWSTA);
#define _send_stop_cond()		TWCR |= (1<<TWSTO);
#define _clr_start_bit()		TWCR &= ~(1<<TWSTA);
#define _next_step()			TWCR |= (1<<TWINT);
#define ISREADY 1
#define UNREADY 0

#define _I2C_MAX_ATTEMPTS 20
#define _I2C_LCD_ADDR 32
#define _I2C_SENS_ADDR 33
#define _I2C_KEY_ADDR 34
#define _I2C_INVALID_RETURN -12

ISR(TWI_vect);

_Bool twi_status();
void twi_enable(void);
void twi_disable(void);
void twi_enable_pull_ups();
void twi_disable_pull_ups(void);
_Bool twi_write(unsigned char i2c_address,unsigned char data);
unsigned char twi_read(unsigned char i2c_address);




#endif /* THECODES_INCLUDES__TWI_H_ */
