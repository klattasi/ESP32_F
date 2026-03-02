
# ESP32 Hardware Configuration

## Overview
Document for ESP32 hardware setup and configuration details.

## Microcontroller
- **Model**: ESP32
- **Core**: Dual-core Xtensa 32-bit LX6
- **Clock Speed**: 160 MHz (configurable to 80 MHz)
- **RAM**: 520 KB SRAM

## Pinout
| Function | GPIO |
|----------|------|
| UART TX  | GPIO1 |
| UART RX  | GPIO3 |
| SPI MOSI | GPIO23 |
| SPI MISO | GPIO19 |
| SPI CLK  | GPIO18 |

## Power Specifications
- **Operating Voltage**: 2.7V - 3.6V
- **Typical Current**: 80 mA (active)
- **Sleep Mode**: 10 μA

## Connectivity
- WiFi 802.11 b/g/n
- Bluetooth 4.2 (BLE)

## Storage
- **Flash**: 4 MB (configurable)
- **EEPROM**: Emulated via NVS


## Relay Configuration
| Relay | GPIO | Trigger Logic |
|-------|------|---------------|
| Relay1 | GPIO4 | Active LOW |
| Relay2 | GPIO16 | Active LOW |
| Relay3 | GPIO17 | Active LOW |
| LED Status | GPIO2 | Active HIGH |
## Switch Configuration
| Switch | GPIO | Trigger Logic |
|--------|------|---------------|
| SW1 | GPIO34 | Active LOW |
| SW2 | GPIO35 | Active LOW |
| SW3 | GPIO32 | Active LOW |

## Isolated Input Configuration
| Isolated Input | GPIO | Trigger Logic | Voltage Range |
|---|---|---|---|
| ISO1 | GPIO33 | Active LOW | 12-24 VDC |
| ISO2 | GPIO27 | Active LOW | 12-24 VDC |

## OLED Display Configuration
| Component | Specification |
|-----------|---|
| Model | 0.96" OLED Display |
| Interface | I2C Bus |
| Resolution | 128 x 64 pixels |
| I2C Address | 0x3C (default) |
| SDA GPIO | GPIO21 |
| SCL GPIO | GPIO22 |
| Operating Voltage | 3.3V |

## RS485 Communication Configuration
| Component | Specification |
|-----------|---|
| IC Module | MAX13487 |
| Interface | Serial0 (UART) |
| Direction Control | Auto Direction (DE/RE pins) |
| DE GPIO | GPIO5 |
| RE GPIO | GPIO6 |
| Operating Voltage | 3.3V |
| Mode Switch | Board-mounted switch for RS232/RS485 selection |
| Baud Rate | Configurable (default 9600) |
| Termination | 120Ω (optional) |
