/*
 * _task.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef OBJECTS__TASK_H_
#define OBJECTS__TASK_H_

#include <stdlib.h>
#include <inttypes.h>
#include "_matrix_.h"


#define INSTANCIADO   PSTR("IDLE")
#define REMOVIDO      PSTR("REMOVED")
#define INQEUE        1
#define OUTQEUE       0
#define CONECTED     3

struct Task;
struct Task* new_task(struct Device* device, uint8_t init_time);
int del_task(struct Task* task);

//-----------------------------------------------------------------------------//
//Setters functions                                               		//     	|
_Bool task_set_timeout(struct Task* task, uint8_t timeout);				//		|
//-----------------------------------------------------------------------------//
//Getters functions                                               		//     	|
const uint8_t task_get_init_time(struct Task* task);					//		|
const uint8_t task_get_timeout(struct Task* task);						//		|
const uint8_t task_get_control_tag(struct Task* task);					//		|
const uint8_t task_get_sensor_tag(struct Task* task);					//		|
const char* task_get_name(struct Task* task);							//		|
const uint8_t task_get_status(struct Task* task);						//		|
//																				|
//------------------------------------------------------------------------------//




#endif /* OBJECTS__TASK_H_ */
