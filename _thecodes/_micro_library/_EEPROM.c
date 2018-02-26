/*
 * _EEPROM.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */

#include "../includes/_EEPROM.h"
/*	This variable is responsible for storing the
 address of the last free memory position	*/
static uint16_t _next_free_mem_pos = 1;
static uint8_t _num_of_devices_counter = 0;

/*	This function scans EEPROM searching the next free memory position
 by checking if each block of 29 bytes ( length of Device type data)
 contains a valid Device type data	*/
void eeprom_check_next_free_address() {

	_next_free_mem_pos = 1;	//Make sure that while will start from address 0x01

	_num_of_devices_counter = 0;			//Make sure that no have any devices

	char aux_name_str[NAME_LENGTH];

	eeprom_write_byte((uint8_t*) 0x00, 0x00);//Write the next free memory position as address 0x00

	eeprom_read_block(aux_name_str, (uint8_t*) (_next_free_mem_pos),
	ACK_RMV_STR_LEN);	//Read the first (ACK_RMV_STR_LENGTH)° bytes

	while (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) == 0) {
		_next_free_mem_pos += DEVICE_TYPE_LEN;
		_num_of_devices_counter++;
		eeprom_read_block(aux_name_str, (uint8_t*) (_next_free_mem_pos),
		ACK_RMV_STR_LEN);
	}
	eeprom_write_byte((uint8_t*) 0x00, _next_free_mem_pos); //Finally write the address of next free position at EEPROM
}
_Bool eeprom_save_device(struct Device* new_device) {

	if ((new_device != NULL) /* && (check if sensor exist and if control pin is avaiable) */) {

		eeprom_check_next_free_address();

		char aux_ack_str[ACK_RMV_STR_LEN];
		strncpy_P(aux_ack_str, ACK_STRING, 13);

		eeprom_write_block(aux_ack_str, (uint16_t*) _next_free_mem_pos,
		ACK_RMV_STR_LEN); 					//First write ACK in EEPROM

		eeprom_write_byte((uint8_t*) (_next_free_mem_pos + ACK_RMV_STR_LEN),
				device_get_timeout(new_device)); //timeout : (uint16_t*) (example + 30) In this case don't forget to use parentheses

		eeprom_write_byte((uint8_t*) _next_free_mem_pos + 9,
				device_get_control_tag(new_device));			//control_tag

		eeprom_write_byte((uint8_t*) _next_free_mem_pos + 10,
				device_get_sensor_tag(new_device));				//sensor_tag

		eeprom_write_block(device_get_name(new_device),
				(uint8_t*) _next_free_mem_pos + 11, 16);

		eeprom_write_word((uint16_t*) (_next_free_mem_pos + 27), 0x0000);

//		information of busy control pins update

		_next_free_mem_pos = _next_free_mem_pos + DEVICE_TYPE_LEN;
		eeprom_write_byte(0x00, _next_free_mem_pos);
		return true;
	} else {
		return false;
	}
}
_Bool eeprom_del_device(const char* device_name) {

	uint16_t aux_data_addr = 0x01;
	char aux_name_str[NAME_LENGTH];
	char aux_vect[DEVICE_TYPE_LEN] = { 0 };
	char aux_rmv_str[ACK_RMV_STR_LEN];

	eeprom_read_block(aux_name_str, (uint16_t*) (aux_data_addr),
	ACK_RMV_STR_LEN);

	while (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) == 0) {

		eeprom_read_block(aux_name_str,
				(uint16_t*) (aux_data_addr + ACK_RMV_STR_LEN), NAME_LENGTH);

		if (strncmp(aux_name_str, device_name, NAME_LENGTH) == 0) {

			eeprom_write_block(aux_vect, (uint16_t*) aux_data_addr,
			DEVICE_TYPE_LEN); //deleta full data block
			strncpy_P(aux_rmv_str, RMV_STRING, NAME_LENGTH);
			eeprom_write_block(aux_rmv_str, (uint16_t*) aux_data_addr,
			ACK_RMV_STR_LEN);
			eeprom_check_next_free_address();
			return true;
		}
		aux_data_addr += DEVICE_TYPE_LEN;
		eeprom_read_block(aux_name_str, (uint16_t*) (aux_data_addr),
		ACK_RMV_STR_LEN);
	}
	return false;
}
_Bool eeprom_update_device(const char* device_name,
		struct Device* device_updated) {

	uint16_t aux_data_addr = 1;
	char aux_name_str[NAME_LENGTH];

	eeprom_read_block(aux_name_str, (uint16_t*) (aux_data_addr),
	ACK_RMV_STR_LEN);

	while (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) == 0) {

		eeprom_read_block(aux_name_str,
				(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN), NAME_LENGTH);

		if (strncmp(aux_name_str, device_name, NAME_LENGTH) == 0) {

			eeprom_update_byte((uint8_t*) aux_data_addr + ACK_RMV_STR_LEN + 1,
					device_get_timeout(device_updated));
			eeprom_update_byte((uint8_t*) aux_data_addr + ACK_RMV_STR_LEN + 2,
					device_get_control_tag(device_updated));
			eeprom_update_byte((uint8_t*) aux_data_addr + ACK_RMV_STR_LEN + 3,
					device_get_sensor_tag(device_updated));
			eeprom_update_block(device_get_name(device_updated),
					(uint8_t*) aux_data_addr + ACK_RMV_STR_LEN + 4,
					NAME_LENGTH);
			eeprom_update_word((uint16_t*) (_next_free_mem_pos + 30), 0x0000);
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

			device_set_timeout(found_device,
					eeprom_read_byte(
							(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN) + 1));
			device_set_control_tag(found_device,
					eeprom_read_byte(
							(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN + 2)));
			device_set_sensor_tag(found_device,
					eeprom_read_byte(
							(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN + 3)));
			device_set_name(found_device,
					eeprom_read_byte(
							(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN + 4)));
			device_set_consumption(found_device,
					eeprom_read_byte(
							(uint8_t*) (aux_data_addr + ACK_RMV_STR_LEN
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

	if (strncmp_P(aux_name_str, ACK_STRING, ACK_RMV_STR_LEN) == 0) {

		struct Device* found_device;
		found_device = new_device();

		device_set_timeout(found_device,
				eeprom_read_byte(
						(uint8_t*) (device_addr + ACK_RMV_STR_LEN) + 1));
		device_set_control_tag(found_device,
				eeprom_read_byte(
						(uint8_t*) (device_addr + ACK_RMV_STR_LEN + 2)));
		device_set_sensor_tag(found_device,
				eeprom_read_byte(
						(uint8_t*) (device_addr + ACK_RMV_STR_LEN + 3)));
		device_set_name(found_device, (char*)
				eeprom_read_byte(
						(uint8_t*) (device_addr + ACK_RMV_STR_LEN + 4)));
		device_set_consumption(found_device,
				eeprom_read_byte(
						(uint8_t*) (device_addr + ACK_RMV_STR_LEN + NAME_LENGTH)));

		return found_device;
	} else {
		return NULL;
	}
}

