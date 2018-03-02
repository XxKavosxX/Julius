/*
 * _EEPROM.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */
#ifndef THECODES_INCLUDES__EEPROM_H_
#define THECODES_INCLUDES__EEPROM_H_


#include "_device.h"
#include "_main_routine.h"
#include "_sensor_list.h"

#define ACK_STRING PSTR("V4L1D_#$\0")
#define RMV_STRING PSTR("X%*DkS_2\0")
#define ACK_RMV_STR_LEN 8
#define NAME_LENGTH 16
#define DEVICE_TYPE_LEN 29

#define FREE_MEM_POS_DATA_ADDR 0x00
#define ERREEEPROM_DONT_SAVE -15
#define CLEAN_BLOC 0x000000000000000000000000000000
/*
 The first EEPROM memory address(0x00) is dedicated to save the next free memory position
*/

/*-----------------------------------------------------------------------------//
 This arrangement defines how Device type data will be saved in the EEPROM		|
 Defining device's data format                                  		    	|
 --- 8 bytes -------------														|
 uint8_t V																		|
 uint8_t 4																		|
 uint8_t L																		|
 uint8_t 1							Eight bytes for valid identifier string		|
 uint8_t D																		|
 uint8_t _																		|
 uint8_t #																		|
 uint8_t $																		|
 --- 3 bytes -------------														|
 uint8_t for timer																|
 uint8_t for control_tag			Tree bytes for time, control and sensor		|
 uint8_t for sensor_tag			 	information									|
 --- 16 bytes ------------														|
 uint8_t N																		|
 uint8_t A																		|
 uint8_t M																		|
 uint8_t E																		|
 uint8_t SPACE																	|
 uint8_t O																		|
 uint8_t F																		|
 uint8_t SPACE																	|
 uint8_t A							Twenty	bytes for name						|
 uint8_t SPACE																	|
 uint8_t D																		|
 uint8_t E																		|
 uint8_t V																		|
 uint8_t I																		|
 uint8_t C																		|
 --- 2 bytes -------------														|
 uint8_t for..				        And finally, 2 bytes for consumption		|
 uint8_t consumption															|
 --- Total of 29 Bytes ---														|
//-----------------------------------------------------------------------------*/



void get_eeprom_next_free_address();

int eeprom_save_device(struct Device* new_device);
int eeprom_del_device(const char* device_name);
int eeprom_update_device(const char* device_last_name, struct Device* update_device);

void eeprom_update_device_consumption(uint16_t device_address, uint8_t device_consumption);
void eeprom_clear_device_consumption(uint16_t device_address);

struct Device* eeprom_find_by_name(const char* device_name);
struct Device* eeprom_find_by_address(uint16_t device_address);



#endif /* THECODES_INCLUDES__EEPROM_H_ */
