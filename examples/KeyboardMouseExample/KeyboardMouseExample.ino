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
