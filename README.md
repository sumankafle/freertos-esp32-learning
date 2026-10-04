# freertos-esp32-learning

This repo demonstrates real-time task management on the ESP32 using FreeRTOS within the ESP-IDF framework.
It focuses on task scheduling, inter-task communication, and modular embedded software design.

## Ubuntu 26 setup

These instructions install ESP-IDF in `/opt/esp-idf` and configure the ESP32 toolchain.

### 1. Install host dependencies

```bash
sudo apt update
sudo apt install git cmake ninja-build python3.14-venv
```

If Ubuntu provides a different Python 3 version, install the matching `python3-venv` package instead.

### 2. Install ESP-IDF

```bash
sudo mkdir -p /opt
sudo chown "$USER":"$USER" /opt
git clone --recursive https://github.com/espressif/esp-idf.git /opt/esp-idf
cd /opt/esp-idf
./install.sh esp32
```

Activate ESP-IDF in each new terminal:

```bash
export PATH=/usr/local/bin:/usr/bin:/bin:$PATH
source /opt/esp-idf/export.sh
```

The PATH line keeps an older Xilinx CMake installation from being selected before the system CMake.

### 3. Allow serial-port access

Connect the ESP32 board and add your user to the serial-device group:

```bash
sudo usermod -aG dialout "$USER"
```

Log out and back in, or reboot. Confirm that `dialout` appears in the output of `id`:

```bash
id
ls /dev/ttyUSB* /dev/ttyACM*
```

If you cannot log out and back in yet, start a shell with the new group active:

```bash
sudo -n -g dialout bash -lc 'export PATH="/usr/local/bin:/usr/bin:/bin:$PATH"; source /opt/esp-idf/export.sh; exec bash'
```

### 4. Build and flash an example

```bash
cd /home/ske/work/repos/freertos-esp32-learning/00_hello_world
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash
```

Replace `/dev/ttyUSB0` with the port reported on your machine. To view output:

```bash
idf.py -p /dev/ttyUSB0 monitor
```

Press `Ctrl-]` to exit the monitor.

The other examples can be built in the same way from their directories:

```text
01_core_affinity_demo
02_task_deletion
```

## VS Code launcher

After ESP-IDF is installed, use the included launcher from any terminal:

```bash
/home/ske/work/repos/freertos-esp32-learning/vscode.sh
```

It activates ESP-IDF and opens this repository with `code .`. The environment is inherited by the VS Code process and its integrated terminals.
