#include "BleComboMouse.h"


#define LSB(v) ((v >> 8) & 0xff)
#define MSB(v) (v & 0xff)
void BleComboMouse::click(uint8_t b)
{
  _buttons = b;
  move(0,0,0,0);
  _buttons = 0;
  move(0,0,0,0);
}

void BleComboMouse::move(signed char x, signed char y, signed char wheel, signed char hWheel)
{
  if (_keyboard->isConnected())
  {
    uint8_t m[5];
    m[0] = _buttons;
    m[1] = x;
    m[2] = y;
    m[3] = wheel;
    m[4] = hWheel;
    _keyboard->inputMouse->setValue(m, 5);
    _keyboard->inputMouse->notify();
  }
}

void BleComboMouse::send(int state, int16_t x, int16_t y)
{
  if (_keyboard->isConnected())
  {
    uint8_t m[5];
    m[0] = state;
    m[1] = MSB(x);
    m[2] = LSB(x);
    m[3] = MSB(y);
    m[4] = LSB(y);
    _keyboard->inputMouse->setValue(m, 5);
    _keyboard->inputMouse->notify();
  }
}


void BleComboMouse::buttons(uint8_t b)
{
  if (b != _buttons)
  {
    _buttons = b;
    move(0,0,0,0);
  }
}

void BleComboMouse::press(uint8_t b)
{
  buttons(_buttons | b);
}

void BleComboMouse::release(uint8_t b)
{
  buttons(_buttons & ~b);
}

bool BleComboMouse::isPressed(uint8_t b)
{
  if ((b & _buttons) > 0)
    return true;
  return false;
}
