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
void AtivarAnalog(uint8_t modo, uint8_t canal, uint8_t prescaler);
char IniciarLeituraAnalog();
_Bool getEstado();
/*    const char* ADgetInfo();*/

//     uint8_t ADmodo;
//     uint8_t ADcanal;
//     uint8_t ADprescaler;
_Bool ModoReferencia(uint8_t modo);
_Bool SelecionarCanal(uint8_t canal);
_Bool SelecionarFreqClock(uint8_t prescaler);




#endif /* THECODES_INCLUDES__ADC_CONVERTER_H_ */
