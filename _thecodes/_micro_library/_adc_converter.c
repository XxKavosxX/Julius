/*
 * _adc_converter.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../includes/_adc_converter.h"
uint8_t estado; //N�o pronto
void AtivarAnalog(uint8_t modo, uint8_t canal, uint8_t prescaler){
    if (ModoReferencia(modo) & SelecionarCanal(canal) & SelecionarFreqClock(prescaler))
    estado = 1; //pronto
}
//  const char* Analog::ADgetInfo(){
//
//  }
_Bool getEstado(){
    return estado;
}
_Bool ModoReferencia(uint8_t modo){
    ADMUX = 0x00;
    if (modo>=0 && modo<=3 && modo != 2)
    {
        ADMUX |= (modo<<6) & AD_REF_MASK;
        return true;
    }
    return false;
    // 0 0  AREF, tens�o interna Vref desligada
    // 0 1 AVCC. Empregar capacitor de 100nF entre AREF e GND
    // 1 0 RESERVADO
    // 1 1 Tens�o interna de refer�ncia de 1.1V. Empregar um capacitor de 100nF entre AREF e GND
}
_Bool SelecionarCanal(uint8_t canal){
    if (canal>=0 && canal <= 6){
        ADMUX &= (0xF0 | canal);
        return true;
    }
    return false;
}
_Bool SelecionarFreqClock(uint8_t prescaler){
    if (prescaler>=0 && prescaler <= 7){
        ADCSRA = 0x00;
        ADCSRA = (1<<ADEN)|(prescaler);
        return true;
    }
    return false;
}
char IniciarLeituraAnalog(){
    //Verificar se o Canal, Clock e Modo setados s�o v�lidos
    if (getEstado()){
        ADCSRA |= (1<<ADSC);
        while(_tst_bit(ADCSRA, ADSC));
        return (ADCH);
    }
    return '0';
}


