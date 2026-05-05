#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * @file core_affinity_demo.c
 * @brief Demonstrates FreeRTOS task core affinity on ESP32.
 *
 * This example shows two tasks:
 * - an unpinned task which the scheduler can run on any available core,
 * - a task pinned to core 1 using `xTaskCreatePinnedToCore`.
 */

/**
 * @brief Unpinned FreeRTOS task.
 *
 * This task is created with `xTaskCreate` (not pinned) so the scheduler
 * may run it on any CPU core.
 *
 * @param pvParameters Pointer to task parameters (unused, may be NULL).
 */
void task_unpinned(void *pvParameters) {
    (void) pvParameters;
    while (1) {
        printf("Task Unpinned: Running on core %d\n", xPortGetCoreID());
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/**
 * @brief Task pinned to core 1.
 *
 * This task is created with `xTaskCreatePinnedToCore` and will always
 * execute on core 1.
 *
 * @param pvParameters Pointer to task parameters (unused, may be NULL).
 */
void task_pinned_core1(void *pvParameters) {
    (void) pvParameters;
    while (1) {
        printf("Task Pinned to Core 1: Running on core %d\n", xPortGetCoreID());
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/**
 * @brief Application entry point.
 *
 * Creates the demo tasks. `xTaskCreate` is used for the unpinned task and
 * `xTaskCreatePinnedToCore` is used to pin the second task to core 1.
 */
void app_main(void){

    /* Create an unpinned task */
    xTaskCreate(task_unpinned,
                "Task Unpinned",
                 2048,
                  NULL,
                   5,
                    NULL );

    /* Create a task pinned to core 1 */
    xTaskCreatePinnedToCore(task_pinned_core1,
                            "Task Pinned to Core 1",
                             2048,
                              NULL,
                               5,
                                NULL, 1);
}