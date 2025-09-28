#include "tasks.h"

extern osMessageQueueId_t bmpQueueHandle;
extern osMutexId_t i2cMutexHandle;

void Task_BMP280(void *argument) {
    BMP280_Data_t data;

    for (;;) {
        osMutexAcquire(i2cMutexHandle, osWaitForever);

        data = BMP280_Read();

        osMutexRelease(i2cMutexHandle);

        osMessageQueuePut(bmpQueueHandle, &data, 0, 0);

        osDelay(1000); // Read every 1 second
    }
}

void Task_LCD(void *argument) {
    BMP280_Data_t data;
    char buffer[32];

    for (;;) {
        if (osMessageQueueGet(bmpQueueHandle, &data, NULL, osWaitForever) == osOK) {
            sprintf(buffer, "Temp: %.2f C", data.temperature);

            osMutexAcquire(i2cMutexHandle, osWaitForever);

            LCD_Print(buffer, 1);

            osMutexRelease(i2cMutexHandle);
        }
    }
}
