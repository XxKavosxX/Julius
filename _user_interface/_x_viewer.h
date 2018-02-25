/*
 * _x_viewer.h
 *
 *  Created on: 25 de jun de 2017
 *      Author: mk
 */

#ifndef USER_INTERFACE__X_VIEWER_H_
#define USER_INTERFACE__X_VIEWER_H_

#define MAIN_MENU 1
#include "../_external_devices_lib/_keyboard.h"
void up();
void down();
void right();
void left();
void center();


void View();
void Show(PGM_P const **bckgrnd);
#endif /* USER_INTERFACE__X_VIEWER_H_ */
