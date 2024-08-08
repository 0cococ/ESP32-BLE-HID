# ESP32 BLE HID Keyboard, Abs Mouse, and Two-Way Communication Library
This library enables ESP32 development boards to function as Bluetooth HID devices, supporting features such as keyboard input, absolute mouse control, and two-way communication.

## Contact Me
- QQ群: 710985269
- QQ: 3560000009

## Installation
- In the Arduino IDE go to "Sketch" -> "Include Library" -> "Add .ZIP Library..." and select the file you just downloaded.
- You can now go to "File" -> "Examples" -> "ESP32 BLE HID" and select any of the examples to get started.

## Example
```
#include <BleCombo.h>
BleComboKeyboard keyboard("cheese-ble-hid", "Espressif", 100);
BleComboMouse mouse(&keyboard);
class MyCallbacks: public BLECharacteristicCallbacks {
	void onRead(BLECharacteristic* pCharacteristic) { }
	void onWrite(BLECharacteristic *pCharacteristic) { }
};
void setup() {
  Serial.begin(115200);
  Serial.println("Starting work!");
  MyCallbacks myCallbacks;
  keyboard.setCallbacks(&myCallbacks);
  keyboard.begin();
  mouse.begin(); 
}
void loop() {
  if(Keyboard.isConnected()) {
   mouse.click();
  }
  delay(2000);
}
```
- 本库仅供学习使用，请勿用于非法用途，否则后果自负。
- 用户明确理解并同意，任何违反法律法规、侵犯他人合法权益的行为，均与本项目及其开发者无关，后果由用户自行承担。

## Credits
This project is heavily based on their work:
- [ESP32-BLE-Mouse](https://github.com/T-vK/ESP32-BLE-Mouse)
- [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard)
- [ESP32-BLE-Abs-Mouse](https://github.com/sobrinho/ESP32-BLE-Abs-Mouse)
- [ESP32-BLE-Combo](https://github.com/blackketter/ESP32-BLE-Combo)
