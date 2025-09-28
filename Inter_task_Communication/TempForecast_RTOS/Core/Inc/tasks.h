#ifndef TASKS_H
#define TASKS_H

#include "main.h"
#include "bmp280.h"
#include "lcd.h"

void Task_BMP280(void *argument);
void Task_LCD(void *argument);

#endif
