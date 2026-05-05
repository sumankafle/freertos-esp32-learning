
# 🧠 ESP32 FreeRTOS Core Affinity Demo

This is a small learning project where I explore how FreeRTOS tasks run on the dual-core ESP32.

The goal is simple: understand how tasks behave when they are **pinned to a core** vs when they are **free to run anywhere**

---

## What this project shows

- A task that can run on **any core**
- A task that is **locked to Core 1**
- How to check which core a task is running on
- Basic FreeRTOS scheduling behavior on ESP32

---

## Requirements

- ESP32 board  
- ESP-IDF installed  
- USB connection  

---

## How to run

### 1. Go to your project folder
```bash
cd freertos-esp32-learning
````

---

### 2. Set the target

```bash
idf.py set-target esp32
```

---

### 3. Build + flash + monitor (all in one)

```bash
idf.py -p /dev/ttyUSB0 build flash monitor
```

👉 If your port is different, check:

```bash
ls /dev/ttyUSB*
```

---

## What you should see

```text
Unpinned Task running on Core 0
Pinned Task running on Core 1
Unpinned Task running on Core 1
Pinned Task running on Core 1
```

### What this means:

* **Unpinned task** → jumps between cores
* **Pinned task** → always stays on Core 1

---

## Key idea (very important)

ESP32 has 2 cores:

* **Core 0** → mostly used by system (WiFi, Bluetooth)
* **Core 1** → where your application usually runs

---

## Why this matters

In real projects, you use core affinity to:

* avoid interference from WiFi tasks
* improve timing stability
* separate workloads

---

## Author
```bash
Suman Kafle
ESP32 | FreeRTOS | Embedded Systems

```


