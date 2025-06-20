/**
 * @file UltrasonicA02YYUW.cpp
 * @author Elvandry Ghiffary (elvandry13@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-06-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "UltrasonicA02YYUW.h"

void UltrasonicA02YYUW::begin(unsigned long baudrate) {
  _serial.begin(baudrate, SERIAL_8N1, _rx, _tx);
}

void UltrasonicA02YYUW::update() {
  while (_serial.available()) {
    uint8_t byteIn = _serial.read();

    switch (_index) {
      case 0:
        if (byteIn == 0xFF) {
          _buffer[0] = byteIn;
          _index = 1;
        }
        break;
      case 1: case 2: case 3:
        _buffer[_index++] = byteIn;
        if (_index > 3) {
          processPacket();
          _index = 0;
        }
        break;
      default:
        _index = 0;
    }
  }
}

float UltrasonicA02YYUW::getDistance() {
  return _distanceCm;
}

void UltrasonicA02YYUW::processPacket() {
  uint8_t h = _buffer[1];
  uint8_t l = _buffer[2];
  uint8_t sum = _buffer[3];
  if (((0xFF + h + l) & 0xFF) == sum) {
    int mm = (h << 8) + l;
    float cm = mm / 10.0;
    if (cm >= 3.0 && cm <= 750.0) {
      _distanceCm = cm;
    }
  }
}
