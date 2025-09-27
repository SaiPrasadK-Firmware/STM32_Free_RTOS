# STM32_Free_RTOS
STM32 FreeRTOS  projects  showcasing task creation, synchronization (semaphores, mutex), and inter-task communication. Built with STM32CubeIDE and runs on STM32 Nucleo boards (tested on STM32F401RE).

---


---

## 📌 Table of Contents

1. Project Overview
2. Topics Overview
3. Project Structure
4. Getting Started
5. Usage
6. Contributing
7. License
8. Contact

---

## Project Overview

STM32 FreeRTOS Mastery is a curated set of embedded projects to teach real-time operating system fundamentals for STM32 microcontrollers.
Designed for embedded engineers, hobbyists, and students aiming to master FreeRTOS multitasking concepts.

---

## Topics Overview

| Topic                        | Project                             | Learning Outcome                                          |
| ---------------------------- | ----------------------------------- | --------------------------------------------------------- |
| **Task Management**          | `01_Task_Creation_Basics`           | Create tasks using `osThreadNew()` and blink LEDs         |
|                              | `02_Task_Delay_and_Timing`          | Use `osDelay()` and tick counts for periodic execution    |
|                              | `03_Task_Delete_and_Lifecycle`      | Learn dynamic task deletion with `osThreadTerminate()`    |
| **Mutex**                    | `04_Mutex_UARTLogging`              | Protect shared resources for safe communication           |
| **Semaphores**               | `05_BinarySemaphore_ButtonLED`      | Use binary semaphores for synchronization with interrupts |
|                              | `06_CountingSemaphore_ResourceMgmt` | Manage limited resources between tasks                    |
| **Inter-task Communication** | `07_Queue_Producer_Consumer`        | Safe data transfer between tasks using queues             |
|                              | `08_MessageBuffer_UART`             | Stream data using message buffers                         |
|                              | `09_EventGroups_MultiConditionSync` | Multi-condition task synchronization using event groups   |
| **Final Integration**        | `10_MultiTask_CompleteSystem`       | Combine all concepts into one complete STM32 system       |

---

## Project Structure

```
STM32_FreeRTOS/
├── README.md
├── Final_Integration/
├── Inter_task_Communication/
├── Mutex/
├── Semaphores/
├── Task_Management/
├── LICENSE
└── .gitignore
```

---

## Getting Started

### Prerequisites

* STM32CubeIDE (or equivalent IDE)
* STM32 development board
* Basic knowledge of C programming
* FreeRTOS library

### Setup

```bash
git clone https://github.com/<your-username>/STM32-FreeRTOS.git
cd STM32-FreeRTOS
```

Open desired project folder in STM32CubeIDE → Build → Flash to your STM32 board.

---

## Usage

Each topic folder contains:

* Source code
* README.md with specific setup and steps
* Example results

Open the relevant folder, follow the instructions in that folder’s README, and run the project.

---

## Contributing

We welcome contributions!

1. Fork the repository
2. Create a feature branch

```bash
git checkout -b feature/your-feature
```

3. Commit your changes

```bash
git commit -m "Add feature XYZ"
```

4. Push your branch

```bash
git push origin feature/your-feature
```

5. Open a pull request

---

## License

This project is licensed under the MIT License — see [LICENSE](LICENSE) for details.

---

## Contact
sai0404@outlook.in

