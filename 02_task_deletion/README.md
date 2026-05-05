| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 | Linux |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | ----- |

# Task Deletion Example

Demonstrates creating and deleting FreeRTOS tasks on ESP32. The example
creates a task and then shows how to safely delete it from another context.

(See the README.md file in the upper level 'examples' directory for more information about examples.)

## How to use example

Follow detailed instructions provided specifically for this example.

Select the instructions depending on Espressif chip installed on your development board:

- [ESP32 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/stable/get-started/index.html)
- [ESP32-S2 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/get-started/index.html)


## Example folder contents

The project **task_deletion** contains one source file in C language [task_deletion.c](main/task_deletion.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt` files that provide set of directives and instructions describing the project's source files and targets (executable, library, or both).

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── task_deletion.c
└── README.md                  This is the file you are currently reading
```

For more information on structure and contents of ESP-IDF projects, please refer to Section [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) of the ESP-IDF Programming Guide.

## Run on ESP32

Follow these steps to build, flash, and monitor the `task_deletion` example on an ESP32 board.

Prerequisites:

- Install ESP-IDF and set up the environment (see the Getting Started guides linked above). Then run:

```
source $IDF_PATH/export.sh
```

- Connect your ESP32 board and determine the serial port (for example `/dev/ttyUSB0`).

Build, flash and monitor:

```
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
```

Replace `/dev/ttyUSB0` with your board's serial port. Use `idf.py menuconfig` to change flash baud rate or other settings if needed. To exit the monitor, press Ctrl-].

## What this example shows

- Creation of tasks with `xTaskCreate` and obtaining a `TaskHandle_t` for a task.
- A task (`hello_task`) that self-deletes using `vTaskDelete(NULL)` after a fixed number of iterations.
- A controller task (`control_task`) that demonstrates deleting another task by its handle via `vTaskDelete(task_handle)`.

This demonstrates both self-deletion and inter-task deletion using FreeRTOS APIs on ESP32.

## Expected serial output

When running on the board you should see something like:

```
Hello Task running, counter = 0
Control Task running...
Hello Task running, counter = 1
Hello Task running, counter = 2
Control Task deleting Hello Task...
Hello Task deleting itself...   # may or may not appear depending on timing
```

Depending on timing, the `control_task` may delete `hello_task` before it reaches its self-delete count, illustrating both patterns.

## Notes

- The example uses `TaskHandle_t` to reference the created task. When deleting another task ensure the handle is valid (non-NULL).
- Deleting tasks frees their stack and resources; ensure any shared resources are protected or cleaned up if needed before deletion.


## Troubleshooting

* Program upload failure

    * Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
    * The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.

---

## Author
```bash
Suman Kafle
ESP32 | FreeRTOS | Embedded Systems
