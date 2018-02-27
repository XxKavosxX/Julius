/*
 * _adc_converter.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../includes/_adc_converter.h"

uint8_t state = 0;

void adc_enable(uint8_t mode, uint8_t channel, uint8_t prescaler){
    if (setup_mode(mode) & select_channel(channel) & select_clk_freq(prescaler))
    state = 1;
}
_Bool adc_status(){
    return state;
}
_Bool setup_mode(uint8_t modo){

		// 0 0  AREF, internal reference voltage off
	    // 0 1  AVCC, need to employ a capacitor between GND and AREFF
	    // 1 0  RESERVED
	    // 1 1  1.1v internal voltage as reference. Need to employ a capacitor between GND and AREFF

    ADMUX = 0x00;
    if (!(modo>=0 && modo<=3 && modo != 2))
    	return false;

    ADMUX |= (modo<<6) & AD_REF_MASK;
    return true;
}
_Bool select_channel(uint8_t canal){

    if (!(canal>=0 && canal <= 6))
    	return false;

    ADMUX &= (0xF0 | canal);
    return true;

}
_Bool select_clk_freq(uint8_t prescaler){

    if (!(prescaler>=0 && prescaler <= 7))
    	return false;

    ADCSRA = 0x00;
    ADCSRA = (1<<ADEN)|(prescaler);
    return true;

}
char adc_read_pin(){

    if (!adc_status())
    	return '0';

    ADCSRA |= (1<<ADSC);
    while(_tst_bit(ADCSRA, ADSC));
    return (ADCH);

}


