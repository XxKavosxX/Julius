/*
 * _task.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef SHUTDOWN_QUEUE_H_
#define SHUTDOWN_QUEUE_H_

#include "_device_list.h"


#define INSTANCIADO   PSTR("IDLE")
#define REMOVIDO      PSTR("REMOVED")
#define INQEUE        1
#define OUTQEUE       0
#define CONECTED     3

struct Shuwtdown_queue;
struct Shuwtdown_queue* new_task(struct Device* device, uint8_t init_time);
int abort_task(struct Shuwtdown_queue* task);

//-----------------------------------------------------------------------------//
//Setters functions                                               		//     	|
_Bool task_set_timeout(struct Shuwtdown_queue* task, uint8_t timeout);				//		|
//-----------------------------------------------------------------------------//
//Getters functions                                               		//     	|
const uint8_t task_get_init_time(struct Shuwtdown_queue* task);					//		|
const uint8_t task_get_timeout(struct Shuwtdown_queue* task);						//		|
const uint8_t task_get_crtlID(struct Shuwtdown_queue* task);					//		|
const uint8_t task_get_sensID(struct Shuwtdown_queue* task);					//		|
const char* task_get_name(struct Shuwtdown_queue* task);							//		|
const uint8_t task_get_status(struct Shuwtdown_queue* task);						//		|
//																				|
//------------------------------------------------------------------------------//




#endif /* THECODES_INCLUDES__SHUTDOWN_QUEUE_H_ */
