/*
 * _task.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "_task.h"
struct Task {
	uint8_t initial_time;
	uint8_t timeout; //Initizialize with de timout of Device struct, this variable represents how many seconds remains until shutdown

	uint8_t control_tag;
	uint8_t sensor_tag;
	char* name;
	uint8_t status;
};
struct Task* new_task(struct Device* device, uint8_t init_time) {
	struct Task* task;
	task = malloc(sizeof(struct Task));

	if (task != NULL) {
		task->initial_time = init_time;
		task->control_tag = device_get_control_tag(device);
		task->sensor_tag = device_get_sensor_tag(device);
		task->name = device_get_name(device);
		task->status = OUTQEUE;
		task->timeout = device_get_timeout(device);
		return task;
	} else {
		return NULL;
	}
}
int del_task(struct Task* task) {
	if (task != NULL) {
		free(task);
		return 1;
	} else {
		return 0;
	}
}
//If necessary create a constructor
_Bool task_set_timeout(struct Task* task, uint8_t timeout) {
	task->timeout = timeout;
	return 1;
}
const uint8_t task_get_init_time(struct Task* task) {
	return task->initial_time;
}

const uint8_t task_get_timeout(struct Task* task) {
	return task->timeout;
}
const uint8_t task_get_control_tag(struct Task* task) {
	return task->control_tag;
}
const uint8_t task_get_sensor_tag(struct Task* task) {
	return task->sensor_tag;
}
const char* task_get_name(struct Task* task) {
	return task->name;
}
const uint8_t task_get_status(struct Task* task){
	return task->status;
}
