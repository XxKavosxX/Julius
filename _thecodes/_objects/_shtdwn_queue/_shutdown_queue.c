/*
 * _shutdown_queue.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../../includes/_shutdown_queue.h"

uint8_t QUEUE_LIST_SIZE = 0;

static struct Shutdown_task *first_task = NULL;
static struct Shutdown_task *last_task = NULL;
static struct Shutdown_task *previous_task = NULL;

struct Shutdown_task {
	struct Date *date_of_entry;
	struct Device_list_node *device;
	struct Shutdown_task *next_task;
};
struct Shutdown_task *new_shutdown_task(
		struct Device_list_node *node_device_to_shutdown) {

	if (node_device_to_shutdown == NULL)
		return NULL;

	struct Shutdown_task* new_node_task = calloc(1,
			sizeof(struct Shutdown_task));

	if (new_node_task == NULL)
		return NULL;

	new_node_task->date_of_entry = get_current_date();
	new_node_task->device = node_device_to_shutdown;
	new_node_task->next_task = NULL;

	return new_node_task;

}
int delete_shutdown_task(struct Shutdown_task *task) {

	if (task == NULL)
		return 0;

	free(task);
	return 1;

}
_Bool begin_shutdown_queue(struct Device_list_node *device_to_shutdown) {

	if ((first_task != NULL) || (device_to_shutdown == NULL))
		return 0;

	first_task = new_shutdown_task(device_to_shutdown);
	last_task = first_task;
	QUEUE_LIST_SIZE++;
	return 1;
}
_Bool append_task(struct Device_list_node *device_to_shutdown) {

	if (device_to_shutdown == 0)
		return 0;

	struct Shutdown_task *task_to_append = new_shutdown_task(device_to_shutdown);

	if (task_to_append == NULL || search_task(device_to_shutdown) != NULL)
		return 0;

	last_task->next_task = task_to_append;
	last_task = task_to_append;
	QUEUE_LIST_SIZE++;
	return 1;
}
struct Shutdown_task *search_task(struct Device_list_node *task) {

	if ((first_task == NULL) || (task == NULL))
		return NULL;

	struct Shutdown_task *aux_task = first_task;
	previous_task = first_task;

	uint8_t counter = 0;

	while ((counter <= QUEUE_LIST_SIZE) && (aux_task != NULL)) {

		if ((get_device_sensor_id(get_node_device(task))
				== get_device_sensor_id(get_node_device(first_task->device)))
				&& (get_device_control_id(get_node_device(task))
						== get_device_control_id(
								get_node_device(first_task->device)))) {
			counter = 0;
			return aux_task;

		} else {

			previous_task = aux_task;
			aux_task = aux_task->next_task;

		}
		counter++;
	}

	return NULL;
}
_Bool task_remove(struct Device_list_node *task) {

	if (task == NULL)
		return 0;

	struct Shutdown_task *task_to_remove = search_task(task);

	if (task_to_remove == NULL) {

		return 0;

	} else if (first_task == task_to_remove) {

		struct Shutdown_task *old_first = first_task->next_task;
		first_task->next_task = old_first->next_task;

		if (!delete_shutdown_task(first_task->next_task))
			return 0;

		first_task = old_first;
		return 1;

	} else if (last_task == task_to_remove) {

		if (!delete_shutdown_task(previous_task->next_task))
			return 0;

		previous_task->next_task = NULL;
		return 1;

	} else {

		previous_task->next_task = task_to_remove->next_task;
		return 1;
	}
}

void sort_shutdown_qeue() {
	uint8_t i = 0, j = 0;
	for (i = 0; i < (QUEUE_LIST_SIZE - 1); i++) {
		for (j = i; j < QUEUE_LIST_SIZE; j++) {

		}

	}
}

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

/*get_device_shutdown_wait(
 get_node_device(node_device_to_shutdown));*/

