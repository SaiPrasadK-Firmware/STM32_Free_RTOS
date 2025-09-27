# STM32_Free_RTOS
STM32 FreeRTOS  projects  showcasing task creation, synchronization (semaphores, mutex), and inter-task communication. Built with STM32CubeIDE and runs on STM32 Nucleo boards (tested on STM32F401RE).

---

## 📌 Table of Contents
1. [Project Overview](#project-overview)
2. [Topics Overview](#topics-overview)
3. [Project Structure](#project-structure)
4. [Getting Started](#getting-started)
5. [Usage](#usage)
6. [Contributing](#contributing)
7. [License](#license)
8. [Contact](#contact)

---



## Topics Overview

| Topic | Project | Learning Outcome |
|-------|---------|-------------------|
| **Task Management** | `01_Task_Creation_Basics` | Create tasks using `osThreadNew()` and blink LEDs |
| | `02_Task_Delay_and_Timing` | Use `osDelay()` and tick counts for periodic execution |
| | `03_Task_Delete_and_Lifecycle` | Learn dynamic task deletion with `osThreadTerminate()` |
| **Mutex** | `04_Mutex_UARTLogging` | Protect shared resources for safe communication |
| **Semaphores** | `05_BinarySemaphore_ButtonLED` | Use binary semaphores for synchronization with interrupts |
| | `06_CountingSemaphore_ResourceMgmt` | Manage limited resources between tasks |
| **Inter-task Communication** | `07_Queue_Producer_Consumer` | Safe data transfer between tasks using queues |
| | `08_MessageBuffer_UART` | Stream data using message buffers |
| | `09_EventGroups_MultiConditionSync` | Multi-condition task synchronization using event groups |
| **Final Integration** | `10_MultiTask_CompleteSystem` | Combine all concepts into one complete STM32 system |

---

## Project Structure

STM32_FreeRTOS/
├── README.md
├── Final_Integration/
├── Inter_task_Communication/
├── Mutex/
├── Semaphores/
├── Task_Management/
├── LICENSE
└── .gitignore



---

## Getting Started

### Prerequisites
- STM32CubeIDE (or equivalent IDE)
- STM32 development board
- Basic knowledge of C programming
- FreeRTOS library

### Setup
```bash
git clone https://github.com/<your-username>/STM32-FreeRTOS.git
cd STM32-FreeRTOS





