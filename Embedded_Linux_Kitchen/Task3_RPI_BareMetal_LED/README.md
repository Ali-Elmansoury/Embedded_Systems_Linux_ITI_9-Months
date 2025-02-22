# Bare-Metal LED Control for Raspberry Pi 3B+  

**Task**: Control GPIO pins to blink LEDs using direct register access on the BCM2837 (RPi 3B+), compiled as a bare-metal binary and loaded via U-Boot.  

---

## 📝 Description  
This project demonstrates bare-metal programming for the Raspberry Pi 3B+ (BCM2837 SoC) to toggle GPIO pins connected to LEDs. The code runs without an OS and interacts directly with hardware registers. U-Boot is used to load and execute the compiled binary (`gpio.img`).  

---

## 🛠️ Toolchain Setup  
The cross-compiler used in this project is **custom-built for the Raspberry Pi 3B+** using `crosstool-NG` with the following configuration:  

- **Target**: `aarch64-rpi3b-linux-uclibc`  
- **C Library**: `uClibc` (lightweight libc for embedded systems)  
- **Architecture**: ARMv8-A (64-bit), optimized for the BCM2837 SoC  

---

## 🎯 Features  
- Controls **GPIO 4, 17, and 27** (configurable in `main.c`)  
- Blinks LEDs with a **1-second delay** using the system timer  
- Bare-metal compilation workflow (no OS dependencies)  
- U-Boot integration for loading and execution  

---

## ⚙️ Requirements  

### 🖥️ Hardware  
- Raspberry Pi 3B+ (BCM2837 SoC)  
- LEDs with resistors (connected to GPIO 4, 17, and 27)  
- Micro-SD card (for booting)  

### 💻 Software  
- **Custom ARM Cross-Compiler**: Built with `crosstool-NG` for `aarch64-rpi3b-linux-uclibc`  
- U-Boot installed on the SD card  

---

## 🔧 Build Instructions  

1. **Cross-Compile**:  
   ```bash
   # Use the crosstool-NG-generated compiler 
   aarch64-rpi3b-linux-uclibc-gcc -nostdlib -T linkerScript.ld startup.S main.c -o gpio.elf
   ```

2. **Generate Binary**:  
   ```bash
   aarch64-rpi3b-linux-uclibc-objcopy -O binary gpio.elf gpio.img
   ```

    <img src="./compilation.png">

3. **Copy to SD Card**:  
   Place `gpio.img` on the SD card’s FAT32 partition.  

---

## 🚀 Usage  

1. Insert the SD card and boot the Raspberry Pi.  
2. In the U-Boot console, enter the following commands:  

   ```bash
   fatload mmc 0:1 0x00080000 gpio.img  # Load binary into memory
   go 0x00080000                        # Execute the code
   ```

   <img src="./run.png">

3. The LEDs connected to GPIO 4, 17, and 27 will blink at 1-second intervals.

<img src="./leds.jpeg">

---

## 🔍 Technical Details  

- **Memory Address**: Code is loaded at `0x00080000` (standard RPi kernel load address).  
- **GPIO Configuration**:  
  - `GPFSEL0`, `GPFSEL1`, and `GPFSEL2` registers configure pins as outputs.  
  - `GPSET0` and `GPCLR0` toggle pin states.  
- **Delays**: Implemented using the BCM2837 system timer (`SYSTIMERCLO`).  
- **U-Boot**: Handles binary loading and execution.  
