#include "lcd.h"
#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

extern I2C_HandleTypeDef hi2c1;

#define LCD_ADDR (0x27 << 1) // Change if your LCD address is different

static void lcd_send_cmd(uint8_t cmd) {
    uint8_t data[2];
    data[0] = 0x00; // Control byte for command
    data[1] = cmd;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, data, 2, HAL_MAX_DELAY);
}

static void lcd_send_data(uint8_t data_val) {
    uint8_t data[2];
    data[0] = 0x40; // Control byte for data
    data[1] = data_val;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, data, 2, HAL_MAX_DELAY);
}

void LCD_Init(void) {
    HAL_Delay(50); // Wait for LCD to power up

    lcd_send_cmd(0x38); // Function set: 8-bit, 2 line, 5x7 dots
    HAL_Delay(5);
    lcd_send_cmd(0x0C); // Display on, cursor off
    HAL_Delay(5);
    lcd_send_cmd(0x01); // Clear display
    HAL_Delay(5);
}

void LCD_Print(char* str, uint8_t line) {
    uint8_t addr;

    if (line == 1) addr = 0x80; // First line
    else addr = 0xC0;           // Second line

    lcd_send_cmd(addr);

    for (uint8_t i = 0; i < strlen(str); i++) {
        lcd_send_data(str[i]);
    }
}
