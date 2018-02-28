/*
 * _adc_converter.h
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef THECODES_INCLUDES__ADC_CONVERTER_H_
#define THECODES_INCLUDES__ADC_CONVERTER_H_
#include "_main_routine.h"
// #define AD_AREF_MODE
// #define AD_AVCC_MODE
// #define AD_TENS_INTER_MODE
#define AD_REF_MASK 0xC0
void adc_enable(uint8_t modo, uint8_t canal, uint8_t prescaler);
char adc_read_pin();
_Bool adc_state();
/*    const char* ADgetInfo();*/

//     uint8_t ADmodo;
//     uint8_t ADcanal;
//     uint8_t ADprescaler;
_Bool setup_mode(uint8_t modo);
_Bool select_channel(uint8_t canal);
_Bool select_clk_freq(uint8_t prescaler);




#endif /* THECODES_INCLUDES__ADC_CONVERTER_H_ */
