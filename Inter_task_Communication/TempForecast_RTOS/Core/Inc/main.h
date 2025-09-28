/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "cmsis_os2.h" /* CMSIS-V2 */
#include <stdio.h>
#include <string.h>

/* USER CODE BEGIN Includes */
/* (Don't put BMP280_Data_t here — define it in bmp280.h) */
/* USER CODE END Includes */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/* Exported variables (visible to other modules) -----------------------------*/
/* HAL handles declared in main.c */
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart2;

/* RTOS objects (created in main.c) */
extern osThreadId_t defaultTaskHandle;
extern osThreadId_t Task_BMP280Handle;
extern osThreadId_t Task_LCDHandle;

extern osMutexId_t i2cMutexHandle;
extern osMessageQueueId_t bmpQueueHandle;

/* Queue size definition (shared) */
#define QUEUE_SIZE 5U

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
