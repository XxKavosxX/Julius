/*
 * _EEPROM.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */

#include "../includes/_EEPROM.h"

static uint16_t next_free_mem_pos = 1;
static uint8_t num_devices = 0;
char aux_name_str[NAME_LENGTH];
char aux_status_str[ACK_RMV_STR_LEN];

/*	This function scans EEPROM searching the next free memory position
 by checking if each block of 29 bytes ( length of Device type data)
 contains a valid Device type data	*/

//ACK            8 bytes
//Shutdown_wait  1 byte
//Control_id	 1 byte
//Sensor_id		 1 byte
//Name			16 bytes
//consumption    2 bytes
void get_eeprom_next_free_address() {

	next_free_mem_pos = 1;
	num_devices = 0;

	eeprom_write_byte(FREE_MEM_POS_DATA_ADDR, 0x00); //Write the next free memory position as address 0x00

	eeprom_read_block(aux_name_str, (uint8_t*) (next_free_mem_pos),
	ACK_RMV_STR_LEN);

	while (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) == 0) {

		next_free_mem_pos += DEVICE_TYPE_LEN;
		num_devices++;
		eeprom_read_block(aux_name_str, (uint8_t*) (next_free_mem_pos),
		ACK_RMV_STR_LEN);

	}

	eeprom_write_byte(FREE_MEM_POS_DATA_ADDR, next_free_mem_pos);
}
int eeprom_save_device(struct Device* new_device) {

	if (new_device == NULL)
		return ERREEEPROM_DONT_SAVE;
	/* && (don't forget to check if sensor exist and if control pin is avaiable) */
	if (search_sensor(get_device_sensor_id(new_device)) == NULL)
		return ERREEEPROM_DONT_SAVE;

	get_eeprom_next_free_address();

	strncpy_P(aux_status_str, ACK_STRING, 13);

	eeprom_write_block(aux_status_str, (uint16_t*) next_free_mem_pos,
	ACK_RMV_STR_LEN);

	eeprom_write_byte((uint8_t*) (next_free_mem_pos + ACK_RMV_STR_LEN),
			get_device_shutdown_wait(new_device));

	eeprom_write_byte((uint8_t*) next_free_mem_pos + 9,
			get_device_control_id(new_device));

	eeprom_write_byte((uint8_t*) next_free_mem_pos + 10,
			get_device_sensor_id(new_device));

	eeprom_write_block(device_get_name(new_device),
			(uint8_t*) next_free_mem_pos + 11, 16);

	eeprom_write_word((uint16_t*) (next_free_mem_pos + 27), 0x0000);

	next_free_mem_pos = next_free_mem_pos + DEVICE_TYPE_LEN;
	eeprom_write_byte(FREE_MEM_POS_DATA_ADDR, next_free_mem_pos);
	return true;
}
int eeprom_del_device(const char* device_name) {

	/*uint16_t aux_data_addr = 0x01;
	 char aux_name_str[NAME_LENGTH];
	 char aux_vect[DEVICE_TYPE_LEN] = { 0 };
	 char aux_rmv_str[ACK_RMV_STR_LEN];*/

	eeprom_read_block(aux_name_str, (FREE_MEM_POS_DATA_ADDR),
	ACK_RMV_STR_LEN);

	while (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) == 0) {

		eeprom_read_block(aux_name_str,
				(const void*) (next_free_mem_pos + ACK_RMV_STR_LEN),
				NAME_LENGTH);

		if (strncmp(aux_name_str, device_name, NAME_LENGTH) == 0) {

			eeprom_write_block(0, (void*) next_free_mem_pos,
			DEVICE_TYPE_LEN);

			strncpy_P(aux_status_str, RMV_STRING, NAME_LENGTH);

			eeprom_write_block(aux_status_str, (void*) next_free_mem_pos,
			ACK_RMV_STR_LEN);

			get_eeprom_next_free_address();

			return true;
		}
		next_free_mem_pos += DEVICE_TYPE_LEN;
		eeprom_read_block(aux_name_str, (const void*) (next_free_mem_pos),
		ACK_RMV_STR_LEN);
	}
	return false;
}
int eeprom_update_device(const char* device_name, struct Device* device_updated) {

	uint16_t aux_data_addr = 1;
	char aux_name_str[NAME_LENGTH];

	eeprom_read_block(aux_name_str, (uint16_t*) (aux_data_addr),
	ACK_RMV_STR_LEN);

	while (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) == 0) {

		eeprom_read_block(aux_name_str,
				(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN), NAME_LENGTH);

		if (strncmp(aux_name_str, device_name, NAME_LENGTH) == 0) {

			eeprom_update_byte((uint8_t*) aux_data_addr + ACK_RMV_STR_LEN + 1,
					get_device_shutdown_wait(device_updated));
			eeprom_update_byte((uint8_t*) aux_data_addr + ACK_RMV_STR_LEN + 2,
					get_device_control_id(device_updated));
			eeprom_update_byte((uint8_t*) aux_data_addr + ACK_RMV_STR_LEN + 3,
					get_device_sensor_id(device_updated));
			eeprom_update_block(device_get_name(device_updated),
					(uint8_t*) aux_data_addr + ACK_RMV_STR_LEN + 4,
					NAME_LENGTH);
			eeprom_update_word((uint16_t*) (next_free_mem_pos + 30), 0x0000);
			return true;
		}
		aux_data_addr += DEVICE_TYPE_LEN;
		eeprom_read_block(aux_name_str, (uint8_t*) (aux_data_addr),
		ACK_RMV_STR_LEN);
	}
	return false;

}
void eeprom_update_device_consumption(uint16_t device_addr,
		uint8_t device_consumption) {
	eeprom_update_word((uint16_t*) (device_addr + 27), device_consumption);
}
void eeprom_clear_device_consumption(uint16_t device_addr) {
	eeprom_write_word((uint16_t*) (device_addr + 27), 0x0000); // limpa o consumo de um dispositivo
}
struct Device* eeprom_find_by_name(const char* name) {
	uint16_t aux_data_addr = 1;
	char aux_name_str[NAME_LENGTH];

	eeprom_read_block(aux_name_str, (uint16_t*) (aux_data_addr),
	ACK_RMV_STR_LEN);

	while (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) == 0) {

		eeprom_read_block(aux_name_str,
				(uint16_t*) (aux_data_addr + ACK_RMV_STR_LEN), NAME_LENGTH);

		if (strncmp(aux_name_str, name, NAME_LENGTH) == 0) {

			struct Device* found_device;
			found_device = new_device();

			set_device_shutdown_wait(found_device,
					eeprom_read_byte(
							(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN) + 1));
			set_device_control_id(found_device,
					eeprom_read_byte(
							(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN + 2)));
			set_device_sensor_id(found_device,
					eeprom_read_byte(
							(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN + 3)));

			eeprom_read_block(aux_name_str,
					(const void*) (aux_data_addr + ACK_RMV_STR_LEN + 4),
					NAME_LENGTH);
			set_device_name(found_device, (uint8_t*) aux_name_str);

			set_device_consumption(found_device,
					eeprom_read_byte(
							(const uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN
									+ NAME_LENGTH)));

			return found_device;
		}
		aux_data_addr += DEVICE_TYPE_LEN;
	}
	return NULL;
}
struct Device* eeprom_find_by_address(uint16_t device_addr) {

	char aux_name_str[NAME_LENGTH];

	eeprom_read_block(aux_name_str, (uint16_t*) (device_addr), ACK_RMV_STR_LEN);

	if (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) != 0)
		return NULL;

	struct Device* found_device;
	found_device = new_device();

	set_device_shutdown_wait(found_device,
			eeprom_read_byte((uint8_t*) (device_addr + ACK_RMV_STR_LEN) + 1));
	set_device_control_id(found_device,
			eeprom_read_byte((uint8_t*) (device_addr + ACK_RMV_STR_LEN + 2)));
	set_device_sensor_id(found_device,
			eeprom_read_byte((uint8_t*) (device_addr + ACK_RMV_STR_LEN + 3)));

	eeprom_read_block(aux_name_str,
			(const void*) (device_addr + ACK_RMV_STR_LEN + 4), NAME_LENGTH);
	set_device_name(found_device, (uint8_t*) aux_name_str);

	set_device_consumption(found_device,
			eeprom_read_byte(
					(const uint8_t*) (device_addr + ACK_RMV_STR_LEN
							+ NAME_LENGTH)));
	set_device_consumption(found_device,
			eeprom_read_byte(
					(const uint8_t*) (device_addr + ACK_RMV_STR_LEN
							+ NAME_LENGTH)));

	return found_device;

}

