#include "bmp280.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

static uint8_t BMP280_ReadReg(uint8_t reg, uint8_t *data, uint16_t len) {
    return HAL_I2C_Mem_Read(&hi2c1, BMP280_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, len, HAL_MAX_DELAY);
}

static uint8_t BMP280_WriteReg(uint8_t reg, uint8_t *data, uint16_t len) {
    return HAL_I2C_Mem_Write(&hi2c1, BMP280_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, len, HAL_MAX_DELAY);
}

void BMP280_Init(void) {
    uint8_t ctrl_meas[2];
    ctrl_meas[0] = 0x27; // Temperature oversampling x1, pressure oversampling x1, normal mode
    BMP280_WriteReg(0xF4, ctrl_meas, 1);
}

BMP280_Data_t BMP280_Read(void) {
    BMP280_Data_t data;
    uint8_t temp_raw[3] = {0};

    BMP280_ReadReg(0xFA, temp_raw, 3);

    int32_t adc_T = (temp_raw[0] << 12) | (temp_raw[1] << 4) | (temp_raw[2] >> 4);
    data.temperature = adc_T / 100.0; // Simplified conversion

    return data;
}
