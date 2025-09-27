#!/bin/bash

# -----------------------------
# folder.sh — STM32 FreeRTOS Project Creator
# -----------------------------

# Config — CHANGE THESE
BASE_DIR="stm32-freertos-projects"
GITHUB_USER="your-username"        # Replace with your GitHub username
GITHUB_REPO="your-repo"            # Replace with your GitHub repo name
GITHUB_URL="https://github.com/$GITHUB_USER/$GITHUB_REPO.git"

# Create base directory
mkdir -p "$BASE_DIR"

# ===== 1) Task Management =====
TASK_MANAGEMENT=(
  "01_Task_Creation_Basics"
  "02_Task_Delay_and_Timing"
  "03_Task_Delete_and_Lifecycle"
)

echo "Creating Task Management projects..."
for PROJ in "${TASK_MANAGEMENT[@]}"; do
  mkdir -p "$BASE_DIR/$PROJ/Core" "$BASE_DIR/$PROJ/Drivers" "$BASE_DIR/$PROJ/Middlewares" "$BASE_DIR/$PROJ/User"
done
echo "Task Management projects created."
echo "Topic: Task Management — Learn task creation, scheduling, timing, and lifecycle" > "$BASE_DIR/Task_Management_Info.txt"

# ===== 2) Mutex =====
MUTEX_PROJECTS=("04_Mutex_UARTLogging")

echo "Creating Mutex projects..."
for PROJ in "${MUTEX_PROJECTS[@]}"; do
  mkdir -p "$BASE_DIR/$PROJ/Core" "$BASE_DIR/$PROJ/Drivers" "$BASE_DIR/$PROJ/Middlewares" "$BASE_DIR/$PROJ/User"
done
echo "Mutex projects created."
echo "Topic: Mutex — Learn mutual exclusion to protect shared resources" > "$BASE_DIR/Mutex_Info.txt"

# ===== 3) Semaphores =====
SEMAPHORE_PROJECTS=(
  "05_BinarySemaphore_ButtonLED"
  "06_CountingSemaphore_ResourceMgmt"
)

echo "Creating Semaphore projects..."
for PROJ in "${SEMAPHORE_PROJECTS[@]}"; do
  mkdir -p "$BASE_DIR/$PROJ/Core" "$BASE_DIR/$PROJ/Drivers" "$BASE_DIR/$PROJ/Middlewares" "$BASE_DIR/$PROJ/User"
done
echo "Semaphore projects created."
echo "Topic: Semaphores — Learn binary and counting semaphores for synchronization" > "$BASE_DIR/Semaphores_Info.txt"

# ===== 4) Inter-task Communication =====
COMMUNICATION_PROJECTS=(
  "07_Queue_Producer_Consumer"
  "08_MessageBuffer_UART"
  "09_EventGroups_MultiConditionSync"
)

echo "Creating Inter-task Communication projects..."
for PROJ in "${COMMUNICATION_PROJECTS[@]}"; do
  mkdir -p "$BASE_DIR/$PROJ/Core" "$BASE_DIR/$PROJ/Drivers" "$BASE_DIR/$PROJ/Middlewares" "$BASE_DIR/$PROJ/User"
done
echo "Inter-task Communication projects created."
echo "Topic: Inter-task Communication — Learn queues, message buffers, and event groups" > "$BASE_DIR/Intertask_Communication_Info.txt"

# ===== 5) Final Integration =====
INTEGRATION_PROJECTS=("10_MultiTask_CompleteSystem")

echo "Creating Final Integration project..."
for PROJ in "${INTEGRATION_PROJECTS[@]}"; do
  mkdir -p "$BASE_DIR/$PROJ/Core" "$BASE_DIR/$PROJ/Drivers" "$BASE_DIR/$PROJ/Middlewares" "$BASE_DIR/$PROJ/User"
done
echo "Final Integration project created."
echo "Topic: Final Integration — Combine all RTOS features into one complete system" > "$BASE_DIR/Final_Integration_Info.txt"

echo "✅ All project folders for STM32 FreeRTOS created inside $BASE_DIR/"

# -----------------------------
# Git operations
# -----------------------------

cd "$BASE_DIR" || { echo "Cannot change directory to $BASE_DIR"; exit 1; }

# Initialize git if not already initialized
if [ ! -d ".git" ]; then
    git init
    git remote add origin "$GITHUB_URL"
fi

# Add all changes
git add .

# Commit changes
git commit -m "Initial STM32 FreeRTOS project structure"

# Push changes
git branch -M main
git push -u origin main

echo "✅ Project structure committed and pushed to GitHub."

