/*
 * _device.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */

#ifndef THECODES_INCLUDES__DEVICE_H_
#define THECODES_INCLUDES__DEVICE_H_

#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <stdlib.h>

#define VOID PSTR("-------\0")
#define INVALID_SENS_ID 255
#define INVALID_CRTL_ID 255
#define INVALID_NAME PSTR("UNKNOW NAME")

struct Device;
struct Device* new_device(void);
int del_device(struct Device* device);

//-----------------------------------------------------------------------------//
//Setters functions                                               		//     	|
_Bool device_set_timeout(struct Device* device, uint8_t timeout);  		//		|
_Bool device_set_control_tag(struct Device* device, uint8_t control_tag); //		|
_Bool device_set_sensor_tag(struct Device* device, uint8_t sensor_tag);	//		|
_Bool device_set_name(struct Device* device, char* name);				// 		|
_Bool device_set_consumption(struct Device* device, unsigned int consumption);	//		|
//------------------------------------------------------------------------------//
//Getters functions										//						|
const uint8_t device_get_timeout(struct Device* device);		//						|
const uint8_t device_get_control_tag(struct Device* device);	//						|
const uint8_t device_get_sensor_tag(struct Device* device);		//						|
const char* device_get_name(struct Device* device);			//						|
const unsigned int device_get_consumption(struct Device* device);		//						|
//-----------------------------------------------------------------------------//




#endif /* THECODES_INCLUDES__DEVICE_H_ */
