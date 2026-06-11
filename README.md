# AVR ATmega328P Embedded Systems Assignment Collection

A comprehensive collection of embedded systems assignments and projects for the **ATmega328P microcontroller** (used in Arduino Uno). This repository contains hands-on implementations covering fundamental to advanced microcontroller concepts including GPIO, timing, ADC, PWM, interrupts, and communication protocols.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Microcontroller Specifications](#microcontroller-specifications)
- [Assignment Categories](#assignment-categories)
  - [LED Control & Blinking](#1-led-control--blinking)
  - [Switch & Input Control](#2-switch--input-control)
  - [Delay & Timing](#3-delay--timing)
  - [PWM & Motor Control](#4-pwm--motor-control)
  - [ADC & Sensor Interfacing](#5-adc--sensor-interfacing)
  - [Interrupts](#6-interrupts)
  - [Communication Protocols](#7-communication-protocols)
  - [Advanced Projects](#8-advanced-projects)
- [Project Structure](#project-structure)
- [Tools & IDE](#tools--ide)
- [Getting Started](#getting-started)
- [How to Use](#how-to-use)

---

## 📌 Overview

This assignment collection focuses on practical embedded systems development using the **ATmega328P microcontroller**. Each project demonstrates specific microcontroller capabilities through real-world applications, from basic GPIO operations to complex peripheral control.

### Key Learning Objectives:
- ✓ GPIO (General Purpose Input/Output) operations
- ✓ Timer and counter configurations
- ✓ Pulse Width Modulation (PWM) techniques
- ✓ Analog-to-Digital Conversion (ADC)
- ✓ External and timer interrupts
- ✓ Serial communication (UART)
- ✓ SPI and I2C protocols
- ✓ LCD/OLED display interfacing
- ✓ Sensor integration and data processing
- ✓ Motor and actuator control

---

## 🔧 Microcontroller Specifications

| Property | Value |
|----------|-------|
| **Microcontroller** | ATmega328P |
| **Architecture** | 8-bit RISC |
| **Clock Frequency** | 16 MHz (typical) |
| **Flash Memory** | 32 KB |
| **SRAM** | 2 KB |
| **EEPROM** | 1 KB |
| **GPIO Pins** | 23 (PORTB, PORTC, PORTD) |
| **ADC Channels** | 6 (10-bit resolution) |
| **Timers** | 3 (Timer0, Timer1, Timer2) |
| **PWM Outputs** | 6 channels |
| **UART** | 1 channel |
| **SPI** | 1 channel |
| **I2C (TWI)** | 1 channel |

---

## 📚 Assignment Categories

### 1. LED Control & Blinking

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **1_PORTD_5_LED** | Toggle LED on PORTD Pin 5 with 3s ON / 5s OFF timing | GPIO, Software Delay, Loop Control |
| **PD3_BLINK_LED** | Basic LED blinking on PD3 pin | GPIO, Delay Functions |
| **BLINK_TWO_LED_HW** | Control two LEDs with hardware configuration | GPIO, Port Operations |
| **BLINK_5LED_USING_HEADER_FILE** | Control five LEDs using modular header files | Modular Programming, Bit Operations |
| **FADING_LED_PWM** | LED brightness control using PWM for fading effect | PWM, Timer0, Duty Cycle Modulation |

### 2. Switch & Input Control

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **ACTIVE_HIGH_SWITCH** | LED control via active-high switch on PC0 | GPIO Input, Debouncing, Logic Control |
| **ACTIVE_LOW_SWITCH** | LED control via active-low switch (pull-up configuration) | GPIO Input, Pull-up Resistors, Inverted Logic |
| **DC_MOTOR_SWITCH1** | DC motor speed control with switch input | GPIO, Motor Driver Interface, Control Logic |

### 3. Delay & Timing

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **DELAY_1024** | Software delay implementation using prescaler 1024 | Timer Configuration, Prescaler Settings |
| **DELAY_TIMER0** | Delay implementation using Timer0 | Timer0 Overflow, Polling Method |
| **timer0_CTM** | Timer0 in CTC (Clear Timer on Compare) mode | CTC Mode, Precision Timing |
| **TIMER0_OVERFLOW_INTERRUPT** | Timer0 overflow interrupt for precise timing | Interrupts, ISR (Interrupt Service Routine) |

### 4. PWM & Motor Control

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **fast_pwm_timer_0** | Fast PWM mode on Timer0 | Fast PWM, Duty Cycle, Frequency Control |
| **DC_Motor_pwm** | DC motor speed regulation via potentiometer and PWM | ADC, PWM, Motor Driver, Analog Input Mapping |
| **MOTOR_FUNC** | Motor control using dedicated functions | Function Implementation, Motor Driver Control |
| **MOTOR_FUNC_DELAY** | Motor control with customizable delay between operations | Timing Control, Motor Sequencing |

### 5. ADC & Sensor Interfacing

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **ADC** | Basic ADC configuration and 10-bit analog reading | ADC Initialization, Channel Selection, Polling |
| **LM35** | Temperature sensor (LM35) interfacing and reading | Temperature Sensing, Analog Scaling, LCD Display |
| **BM280_pressure_sensing** | Barometric pressure sensor (BM280) via I2C | I2C Protocol, Sensor Integration, Data Processing |

### 6. Interrupts

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **EXT_INTRRUPT** | External interrupt handling (INT0, INT1) | External Interrupts, ISR Implementation, Debouncing |

### 7. Communication Protocols

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **UART_TXT/SERIAL_CNTRL_LED_UART** | UART communication for LED control via serial commands | UART Configuration, Baud Rate, Serial Communication |
| **SPI** | Serial Peripheral Interface protocol implementation | SPI Master/Slave, Clock, Data Transfer |
| **SPI_BM280** | Barometric sensor interfacing via SPI | SPI Protocol, Sensor Data Reading |

### 8. Advanced Projects

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **162_lcd** | 16x2 LCD display interfacing and control | LCD 4-bit Mode, Display Routines, Character Display |
| **modular_1** | Modular project structure with reusable components | Code Organization, Header Files, Modularity |

---

## 📁 Project Structure

Each assignment follows a standardized Atmel Studio project structure:

```
ProjectName/
├── ProjectName.atsln              # Atmel Studio solution file
├── question.md/question.txt        # Assignment requirements and objectives
├── vedio.md                        # Video reference (if applicable)
├── Simulation_*.sim1               # Proteus simulation file (if available)
├── ProjectName/
│   ├── ProjectName.cproj          # Atmel Studio C project file
│   ├── main.c                     # Main source code
│   ├── *.c / *.h                  # Additional source/header files
│   └── Debug/                     # Compiled output and debug info
└── README.md / Documentation      # Project-specific documentation
```

---

## 🛠️ Tools & IDE

- **IDE**: Atmel Studio 7 / Microchip Studio
- **Compiler**: AVR-GCC (GNU C Compiler for AVR)
- **Simulator**: Proteus Design Suite (for circuit simulation)
- **Programmer**: AVR ISP/USBASP (for hardware programming)
- **Programming Language**: C/C++

---

## 🚀 Getting Started

### Prerequisites
1. **Atmel Studio 7** or **Microchip Studio** installed
2. **AVR-GCC** toolchain (usually included with studio)
3. **ATmega328P** microcontroller or Arduino Uno board
4. **AVR Programmer** (optional, for hardware deployment)
5. **Proteus** (optional, for simulation)

### Setup Instructions

#### Option 1: Using Atmel Studio
1. Open the desired `.atsln` (solution) file in Atmel Studio
2. Build the project: `Build → Build Solution` (Ctrl+Shift+B)
3. Simulate or flash to hardware

#### Option 2: Command Line Build
```bash
# Navigate to project directory
cd ProjectName/ProjectName

# Build using avr-gcc
avr-gcc -mmcu=atmega328p -O2 -c main.c -o main.o
avr-gcc -mmcu=atmega328p -O2 main.o -o main.elf

# Create hex file for programming
avr-objcopy -O ihex main.elf main.hex
```

---

## 📖 How to Use

### For Learning:
1. **Start with basics**: Begin with `1_PORTD_5_LED` to understand GPIO operations
2. **Progress systematically**: Follow the category order (LED → Switch → Timer → etc.)
3. **Study documentation**: Read `question.md` files to understand requirements
4. **Analyze code**: Review implementation patterns and commenting
5. **Experiment**: Modify code and observe behavioral changes

### For Each Project:
1. Open the `.atsln` file in Atmel Studio
2. Review the `question.md` file for requirements
3. Examine `main.c` for implementation details
4. Build the project (F7 or Ctrl+Shift+B)
5. **Simulate** in Proteus (if `.sim1` file exists) or **Program** to hardware
6. Verify functionality against requirements

### Pin Configuration Reference

**Common Pin Assignments Used:**

| Pin | Function | Projects |
|-----|----------|----------|
| PD5 | LED Output | 1_PORTD_5_LED, BLINK_5LED... |
| PD3 | LED/Motor Output | PD3_BLINK_LED, DC_Motor... |
| PD6 | PWM (OC0A) | DC_Motor_pwm, FADING_LED_PWM |
| PC0 | Switch Input | ACTIVE_HIGH/LOW_SWITCH |
| ADC0 (PC0) | Analog Input | ADC, LM35, DC_Motor_pwm |
| TX (PD1) / RX (PD0) | UART | SERIAL_CNTRL_LED_UART |
| SCL (PC5) / SDA (PC4) | I2C (TWI) | BM280_pressure_sensing |
| MOSI (PB3) / MISO (PB4) / SCK (PB5) | SPI | SPI, SPI_BM280 |

---

## 📝 Compilation & Build Notes

- **F_CPU Definition**: Set to 16MHz in all projects: `#define F_CPU 16000000UL`
- **Optimization**: Compiled with `-O2` optimization for production
- **Warnings**: Enable all warnings during development with `-Wall`
- **Includes**: Standard AVR libraries (`<avr/io.h>`, `<avr/interrupt.h>`, `<util/delay.h>`)

---

## 🎓 Educational Resources

- **AVR Instruction Set**: [Microchip AVR Documentation](https://www.microchip.com/)
- **ATmega328P Datasheet**: Complete register definitions and pin configurations
- **Embedded C Programming**: Best practices for microcontroller development

---

## 📄 License & Attribution

These assignments are educational resources for learning embedded systems development. Author: Athul

---

## 🤝 Contributing

To add improvements or corrections:
1. Verify the implementation works correctly
2. Ensure code is well-commented
3. Include comprehensive `question.md` documentation
4. Test with appropriate simulation/hardware

---

**Last Updated**: 2026-06-11  
**Target Platform**: ATmega328P (Arduino Uno Compatible)  
**Development Environment**: Atmel Studio 7 / Microchip Studio