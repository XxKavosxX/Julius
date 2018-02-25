/*
 * _sensor_recognition.h
 *
 *  Created on: 15 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef PARALLEL_ROUTINE__SENSOR_RECOGNITION_H_
#define PARALLEL_ROUTINE__SENSOR_RECOGNITION_H_

#include "../_routine/_main_routine.h"
#include "../_micro_library/_twi.h"

ISR(INT0_vect);
void sens_int_setup(uint8_t mode);
void sens_int_status(uint8_t status);



#endif /* PARALLEL_ROUTINE__SENSOR_RECOGNITION_H_ */
