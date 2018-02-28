/*
 * _shutdown_queue.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../../includes/_shutdown_queue.h"

struct Shuwtdown_queue {

	uint8_t initial_time;
	uint8_t timeout;
	uint8_t control_ID;
	uint8_t sensor_ID;
	char* name;
	/*uint8_t status;*/
};
struct Shuwtdown_queue* new_task(struct Device* device, uint8_t init_time) {

	struct Shuwtdown_queue* task;
	task = malloc(sizeof(struct Shuwtdown_queue));

	if (task == NULL)
		return NULL;

	task->initial_time = init_time;
	task->timeout = device_get_timeout(device);

	task->control_ID = device_get_control_tag(device);
	task->sensor_ID = device_get_sensor_tag(device);

	task->name = device_get_name(device);
	//task->status = OUTQEUE;

	return task;

}



int abort_task(struct Shuwtdown_queue* task) {

	if (task == NULL)
		return 0;

	free(task);
	return 1;

}

const uint8_t task_get_init_time(struct Shuwtdown_queue* task) {
	return task->initial_time;
}

const uint8_t task_get_timeout(struct Shuwtdown_queue* task) {
	return task->timeout;
}
const uint8_t task_get_crtlID(struct Shuwtdown_queue* task) {
	return task->control_ID;
}
const uint8_t task_get_sensID(struct Shuwtdown_queue* task) {
	return task->sensor_ID;
}
const char* task_get_name(struct Shuwtdown_queue* task) {
	return task->name;
}
