/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os2.h"
#include <stdint.h>

/* Flags */
#define BUTTON_FLAG_FAST   (1U << 0)
#define BUTTON_FLAG_SLOW   (1U << 1)

/* Thread handles */
osThreadId_t Button_taskHandle;
osThreadId_t LED_FastHandle;
osThreadId_t LED_SlowHandle;

/* Thread prototypes */
void Button_press(void *argument);
void Led_Fast(void *argument);
void Led_Slow(void *argument);

UART_HandleTypeDef huart2;

/* Thread attributes */
const osThreadAttr_t Button_task_attributes = {
  .name = "Button_task",
  .stack_size = 128 * 4,
  .priority = osPriorityNormal,
};
const osThreadAttr_t LED_Fast_attributes = {
  .name = "LED_Fast",
  .stack_size = 128 * 4,
  .priority = osPriorityNormal,
};
const osThreadAttr_t LED_Slow_attributes = {
  .name = "LED_Slow",
  .stack_size = 128 * 4,
  .priority = osPriorityNormal,
};

/* Function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

/* Main function */
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    osKernelInitialize();

    Button_taskHandle = osThreadNew(Button_press, NULL, &Button_task_attributes);
    LED_FastHandle = osThreadNew(Led_Fast, NULL, &LED_Fast_attributes);
    LED_SlowHandle = osThreadNew(Led_Slow, NULL, &LED_Slow_attributes);

    osKernelStart();

    while (1) {}
}

/* Button Task */
void Button_press(void *argument)
{
    uint8_t press_count = 0;
    uint32_t last_tick = 0;

    while (1)
    {
        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) // active low
        {
            press_count++;
            osDelay(200); // debounce delay
            last_tick = osKernelGetTickCount(); // reset timeout on press
        }

        // If pressed and no new press in 500 ms
        if (press_count > 0 && (osKernelGetTickCount() - last_tick) > 500)
        {
            if (press_count == 1)
            {
                osThreadFlagsSet(LED_FastHandle, BUTTON_FLAG_FAST);
            }
            else if (press_count == 2)
            {
                osThreadFlagsSet(LED_SlowHandle, BUTTON_FLAG_SLOW);
            }

            press_count = 0; // reset
        }

        osDelay(10);
    }
}



/* LED Fast Task */
void Led_Fast(void *argument)
{
    while (1)
    {
        osThreadFlagsWait(BUTTON_FLAG_FAST, osFlagsWaitAny, osWaitForever);

        for (int i = 0; i < 10; i++)
        {
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
            osDelay(250);
        }
    }
}

/* LED Slow Task */
void Led_Slow(void *argument)
{
    while (1)
    {
        osThreadFlagsWait(BUTTON_FLAG_SLOW, osFlagsWaitAny, osWaitForever);

        for (int i = 0; i < 10; i++)
        {
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
            osDelay(1000);
        }
    }
}

/* System Clock Config */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 16;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
    RCC_OscInitStruct.PLL.PLLQ = 7;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}

/* USART2 Init */
static void MX_USART2_UART_Init(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler();
    }
}

/* GPIO Init */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* Button */
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* LED */
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/* Error Handler */
void Error_Handler(void)
{
    __disable_irq();
    while (1) {}
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif
