#ifndef BMP280_H
#define BMP280_H

#include "main.h"

#define BMP280_ADDR (0x76 << 1) // Default address

typedef struct {
    float temperature;
    float pressure;
} BMP280_Data_t;

void BMP280_Init(void);
BMP280_Data_t BMP280_Read(void);

#endif
