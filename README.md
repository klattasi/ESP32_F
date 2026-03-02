# ESP32 Vibe Farm Project

การตั้งค่าและข้อมูลการใช้งานบอร์ด ESP32 สำหรับโปรเจค Vibe Farm

## 📋 ข้อมูลโปรเจค

โปรเจค Vibe Farm ใช้บอร์ด ESP32 ในการควบคุมระบบต่างๆ รวมถึง Relay, Switch, Input แยกไป, จอแสดงผล OLED และการสื่อสาร RS485

---

## 🔧 ตัวระบุเฉพาะไมโครคอนโทรลเลอร์

| รายการ | ข้อมูล |
|--------|--------|
| **รุ่น** | ESP32 |
| **ประเภท Core** | Dual-core Xtensa 32-bit LX6 |
| **ความเร็ว Clock** | 160 MHz (ปรับได้เหลือ 80 MHz) |
| **RAM** | 520 KB SRAM |
| **Flash** | 4 MB (ปรับได้) |
| **Voltage ทำงาน** | 2.7V - 3.6V |
| **กระแสไฟ Active** | 80 mA |
| **Sleep Mode** | 10 μA |

---

## 📡 ความเชื่อมต่อและสื่อสาร

### WiFi & Bluetooth
- **WiFi**: 802.11 b/g/n
- **Bluetooth**: 4.2 (BLE)

### UART (Serial Communication)
| ฟังก์ชัน | GPIO |
|----------|------|
| TX | GPIO1 |
| RX | GPIO3 |

### SPI Interface
| ฟังก์ชัน | GPIO |
|----------|------|
| MOSI | GPIO23 |
| MISO | GPIO19 |
| CLK | GPIO18 |

---

## 🔌 การตั้งค่า Relay และ LED

| อุปกรณ์ | GPIO | Logic Trigger |
|--------|------|---------------|
| **Relay1** | GPIO4 | Active LOW |
| **Relay2** | GPIO16 | Active LOW |
| **Relay3** | GPIO17 | Active LOW |
| **LED Status** | GPIO2 | Active HIGH |

**หมายเหตุ**: Relay ทั้งหมดใช้ Active LOW ซึ่งหมายถึงการส่ง LOW signal เพื่อเปิด Relay

---

## 🔘 การตั้งค่า Switch

| Switch | GPIO | Logic Trigger |
|--------|------|---------------|
| **SW1** | GPIO34 | Active LOW |
| **SW2** | GPIO35 | Active LOW |
| **SW3** | GPIO32 | Active LOW |

**หมายเหตุ**: Switch ทั้งหมดใช้ Active LOW - กด Switch เพื่อสร้าง LOW signal

---

## 🔒 Isolated Input Configuration

| Isolated Input | GPIO | Logic Trigger | Voltage Range |
|---|---|---|---|
| **ISO1** | GPIO33 | Active LOW | 12-24 VDC |
| **ISO2** | GPIO27 | Active LOW | 12-24 VDC |

**ประโยชน์**: Isolated inputs ป้องกัน noise และ voltage spikes จากระบบภายนอก

---

## 🖥️ OLED Display (I2C)

| รายการ | ข้อมูล |
|--------|--------|
| **ขนาด** | 0.96 นิ้ว |
| **ความละเอียด** | 128 x 64 pixels |
| **อินเตอร์เฟส** | I2C Bus |
| **I2C Address** | 0x3C (ค่าเริ่มต้น) |
| **SDA GPIO** | GPIO21 |
| **SCL GPIO** | GPIO22 |
| **Voltage** | 3.3V |

**การใช้งาน**: เหมาะสำหรับแสดงสถานะระบบ, ข้อมูล, และเมนูการควบคุม

---

## 📶 RS485 Communication

| รายการ | ข้อมูล |
|--------|--------|
| **Module IC** | MAX13487 |
| **ทำงานผ่าน** | Serial0 (UART) |
| **Direction Control** | Auto Direction (DE/RE pins) |
| **DE GPIO** | GPIO5 |
| **RE GPIO** | GPIO6 |
| **Voltage** | 3.3V |
| **Baud Rate** | 9600 (ปรับได้) |
| **Termination** | 120Ω (ตัวเลือก) |
| **Mode Switch** | สวิตช์บนบอร์ดสำหรับเลือก RS232/RS485 |

**ประโยชน์**: สื่อสารระยะไกลกับอุปกรณ์อื่นๆ ผ่าน RS485

---

## 💡 Quick Reference - GPIO Summary

| GPIO | ฟังก์ชัน | ประเภท |
|------|----------|---------|
| GPIO1 | UART TX | Output |
| GPIO2 | LED Status | Output |
| GPIO3 | UART RX | Input |
| GPIO4 | Relay1 | Output |
| GPIO5 | RS485 DE | Output |
| GPIO6 | RS485 RE | Output |
| GPIO16 | Relay2 | Output |
| GPIO17 | Relay3 | Output |
| GPIO18 | SPI CLK | Output |
| GPIO19 | SPI MISO | Input |
| GPIO21 | I2C SDA | Bidirectional |
| GPIO22 | I2C SCL | Bidirectional |
| GPIO23 | SPI MOSI | Output |
| GPIO27 | Isolated Input 2 | Input |
| GPIO32 | Switch 3 | Input |
| GPIO33 | Isolated Input 1 | Input |
| GPIO34 | Switch 1 | Input |
| GPIO35 | Switch 2 | Input |

---

## 📋 Requirements & Dependencies

- **PlatformIO** - สำหรับการพัฒนาและอัปโหลด
- **ESP32 Board** - ESP32 Dev Board หรือบอร์ดที่เข้ากันได้
- **Libraries** - ดูที่ `platformio.ini` สำหรับ dependencies ของโปรเจค

---

## 🚀 การเริ่มต้น

1. **ตรวจสอบการเชื่อมต่อ**: ตรวจสอบให้แน่ใจว่า GPIO ทั้งหมดเชื่อมต่ออย่างถูกต้อง
2. **โหลด Firmware**: ใช้ PlatformIO ในการอัปโหลด code ไปยัง ESP32
3. **ทดสอบ**: ทดสอบแต่ละฟังก์ชัน (Relay, Switch, Display, RS485)
4. **ปรับแต่ง**: ตั้งค่า Baud rates, I2C address และการกำหนดค่าอื่นๆ ตามต้องการ

---

## 📝 หมายเหตุสำคัญ

- ⚠️ Relay และ Switch ใช้ **Active LOW** - ต้องส่ง LOW (0V) เพื่อเปิด/กด
- ⚠️ GPIO34, 35 ไม่มี pull-up internal - อาจต้องการ external pull-up resistors
- ⚠️ RS485 มีสวิตช์บนบอร์ดสำหรับเปลี่ยนระหว่าง RS232/RS485

---

## 📚 ข้อมูลเพิ่มเติม

สำหรับข้อมูลเทคนิคโดยละเอียด ดูที่:
- `test/Hardware_config.md` - ข้อมูลกำหนดค่า Hardware ทั้งหมด
- `platformio.ini` - การกำหนดค่าโปรเจค

