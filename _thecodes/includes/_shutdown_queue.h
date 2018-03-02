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


struct Shutdown_task;
struct Shutdown_task *new_shutdown_task(struct Device_list_node *device_to_shutdown,
		uint8_t time_of_entry);
int delete_shutdown_task(struct Shutdown_task *task);

_Bool begin_shutdown_queue(struct Device_list_node *device_to_shutdown, uint8_t time_of_entry);

_Bool task_append(struct Device *device_to_shutdown, uint8_t time_of_entry);
_Bool task_remove(struct Device *device_to_shutdown);
struct Shutdown_task *task_search(uint8_t sensor, uint8_t control);
void sort_shutdown_qeue();
const uint8_t task_get_timeout(struct Shutdown_task *task);
const uint8_t task_get_control_id(struct Shutdown_task *task);
const uint8_t task_get_sensor_id(struct Shutdown_task *task);
const char *task_get_name(struct Shutdown_task *task);
struct Device *get_node_device(struct Device_list_node *node);



#endif /* THECODES_INCLUDES__SHUTDOWN_QUEUE_H_ */
