/*
 * _shutdown_queue.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../../includes/_shutdown_queue.h"

uint8_t QUEUE_MAX_SIZE = 0;

static struct Shutdown_task *first_task = NULL;
static struct Shutdown_task *last_task = NULL;
static struct Shutdown_task *previous_task = NULL;

struct Shutdown_task {
	uint8_t time_to_shutdown_in_sec;
	struct Device_list_node *device;
	struct Shutdown_task *_next_element;
};
struct Shutdown_task *new_shutdown_task(
		struct Device_list_node *node_device_to_shutdown, uint8_t time_of_entry) {

	if (node_device_to_shutdown == NULL)
		return NULL;

	struct Shutdown_task* new_node_task = calloc(1,
			sizeof(struct Shutdown_task));

	if (new_node_task == NULL)
		return NULL;

	new_node_task->time_to_shutdown_in_sec = time_of_entry
			- get_device_shutdown_wait(
					get_node_device(node_device_to_shutdown));
	new_node_task->device = node_device_to_shutdown;
	new_node_task->_next_element = NULL;

	return new_node_task;

}
int delete_shutdown_task(struct Shutdown_task *task) {

	if (task == NULL)
		return 0;

	free(task);
	return 1;

}
_Bool begin_shutdown_queue(struct Device_list_node *device_to_shutdown,
		uint8_t time_of_entry) {

	if ((first_task != NULL) || (device_to_shutdown == NULL))
		return 0;

	first_task = new_shutdown_task(device_to_shutdown, time_of_entry);
	last_task = first_task;
	QUEUE_MAX_SIZE++;
	return 1;
}
/*_Bool task_append(struct Device* device_to_shutdown, uint8_t time_of_entry) {
 if (device_to_shutdown == 0)
 return 0;

 struct Shutdown_task *task_to_append = new_shutdown_task(device_to_shutdown,
 time_of_entry);

 if (task_to_append == NULL
 || task_search(get_device_sensor_id(device_to_shutdown),
 get_device_control_id(device_to_shutdown)) != NULL)
 return 0;

 //last_task-> continue...
 }
 _Bool task_remove(struct Device* device_to_shutdown) {
 return 0;
 }


 void sort_shutdown_qeue() {
 uint8_t i = 0, j = 0;
 for (i = 0; i < (QUEUE_MAX_SIZE - 1); i++) {
 for (j = i; j < QUEUE_MAX_SIZE; j++) {

 }

 }
 }
 struct Shutdown_task* task_search(uint8_t sensor, uint8_t control) {

 }*/

/*const uint8_t task_get_timeout(struct Shutdown_task* task) {
 return task->timeout_in_seconds;
 }
 const uint8_t task_get_control_id(struct Shutdown_task* task) {
 return task->control_id;
 }
 const uint8_t task_get_sensor_id(struct Shutdown_task* task) {
 return task->sensor_id;
 }
 const char* task_get_name(struct Shutdown_task* task) {
 return task->name;
 }*/
