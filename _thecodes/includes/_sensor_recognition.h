/*
 * _sensor_recognition.h
 *
 *  Created on: 15 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef THECODES_INCLUDES__SENSOR_RECOGNITION_H_
#define THECODES_INCLUDES__SENSOR_RECOGNITION_H_

#include "../includes/_twi.h"
#include "_main_routine.h"

ISR(INT0_vect);
void sens_int_setup(uint8_t mode);
void sens_int_status(uint8_t status);



#endif /* THECODES_INCLUDES__SENSOR_RECOGNITION_H_ */
