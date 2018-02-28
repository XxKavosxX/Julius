/*
 * _main_routine.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "../includes/_main_routine.h"

#include "../includes/_device_list.h"
#include "../includes/_DS1302.h"
#include "../includes/_I2C_LCD16x2.h"
#include "../includes/_keyboard.h"
#include "../includes/_sensor_list.h"
#include "../includes/_twi.h"
#include "../includes/_twi.h"
#include "../includes/_usart.h"
#include "../includes/_x_viewer.h"

#define INIT_MODULOS 0
#define CARR_DADOS 1
#define DADOS_CARREGADOS 2
#define PRONTO 3
#define OPERANDO 4
#define EXECUTAR_DESLIGAMENTO 5

char ESTADO_ATUAL = INIT_MODULOS;
int main() {
	start_tools();
	while (1) {

		_delay_ms(1000);
	}
}

/*void  _device_resizable_list_test(){

	struct Device* device = new_device();
	device_set_timeout(device, 5);
	device_set_control_tag(device, 5);
	device_set_sensor_tag(device, 5);
	device_set_name(device, "Ventilador do Quarto\0");
	device_set_consumption(device, 5);

	struct Device* device2 = new_device();
	device_set_timeout(device2, 6);
	device_set_control_tag(device2, 6);
	device_set_sensor_tag(device2, 6);
	device_set_name(device2, "TV sala\0");
	device_set_consumption(device2, 6);

	struct Device* device3 = new_device();
	device_set_timeout(device3, 7);
	device_set_control_tag(device3, 7);
	device_set_sensor_tag(device3, 7);
	device_set_name(device3, "TV quarto\0");
	device_set_consumption(device3, 7);

	struct Device* device4 = new_device();
	device_set_timeout(device4, 8);
	device_set_control_tag(device4, 8);
	device_set_sensor_tag(device4, 8);
	device_set_name(device4, "Ar Condicionado");
	device_set_consumption(device4, 8);

	element_list_begin(device);
	element_append(device2);
	element_append(device3);
	//element_delete(device4);
	element_append(device3);
	//append_element(device4);
	//search_element(element_get_first(), 5,5);
	//rint_list();
	//delete_element(device);
	//delete_element(device4);
	//delete_element(device4);
	//print_list();
	delete_element(device3);
	 delete_element(device2);
	 print_list();

	 delete_element(device);
	 delete_element(device);
	 delete_element(device2);
	//print_list(element_get_first());
	element_print_list();

}

void _sensor_resizable_list_test() {
	struct Sensor* sensor = new_sensor();
	sensor_set_pin(sensor, 1);
	sensor_set_name(sensor, "Sensor da Sala");
	sensor_set_status(sensor, 0);

	struct Sensor* sensor2 = new_sensor();
	sensor_set_pin(sensor2, 2);
	sensor_set_name(sensor2, "Sensor da Quarto");
	sensor_set_status(sensor2, 0);

	struct Sensor* sensor3 = new_sensor();
	sensor_set_pin(sensor3, 3);
	sensor_set_name(sensor3, "Sensor de Fora");
	sensor_set_status(sensor3, 0);

	usart_write_flash(PSTR("\nInit list\n"));

	unit_list_begin(sensor);


	unit_append(sensor);

	unit_append(sensor2);

	unit_append(sensor3);

	unit_print_list();


	unit_delete(sensor);
	unit_delete(sensor2);
	unit_delete(sensor3);
	usart_write_flash(PSTR("\n\n"));

	//unit_print_list();

}*/




void start_tools() {

	//	//ativando pull-ups nos pinos de interrupo
	DDRD = 0b11110011;
	PORTD = 0b00000000;
	usart_enable(MYUBRR);
	twi_enable_pull_ups();
	twi_enable();
	lcd_start();
	initialize_DS1302();
	key_int_setup(1);
	key_int_status(1);
	View();
	//init_RTC(50, 8, 20, 23, 06, 05, 17);
	//read_RTC();
}

void CalcularConsumo(char sensorCorrenteEnd) {

}
char *FloatParaChar(char *buffer, double d, int precision) {
	long wholePart = (long) d;
	itoa(wholePart, buffer, 10);
	if (precision > 0) {
		char *endOfString = buffer;
		while (*endOfString != '\0')
			endOfString++;
		*endOfString++ = '.';
		if (d < 0) {
			d *= -1;
			wholePart *= -1;
		}
		double fraction = d - wholePart;
		while (precision > 0) {
			fraction *= 10;
			wholePart = (long) fraction;
			*endOfString++ = '0' + wholePart;
			fraction -= wholePart;
			precision--;
		}
		*endOfString = '\0';
	}
	return buffer;
}
char* InteiroParaChar(int numero) {
	static char buffer[10];
	itoa(numero, buffer, 10);
	return buffer;
}
char* LongParaChar(uint32_t numero) {
	static char buffer[10];
	utoa(numero, buffer, 10);
	return buffer;
}

