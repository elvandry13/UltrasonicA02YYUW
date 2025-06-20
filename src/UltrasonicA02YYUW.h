/**
 * @file UltrasonicA02YYUW.h
 * @author Elvandry Ghiffary (elvandry13@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-06-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef ULTRASONIC_A02YYUW_H
#define ULTRASONIC_A02YYUW_H

#include <Arduino.h>

class UltrasonicA02YYUW {
  public:
    UltrasonicA02YYUW(HardwareSerial& serialPort, uint8_t rxPin, uint8_t txPin)
      : _serial(serialPort), _rx(rxPin), _tx(txPin) {}

    void begin(unsigned long baudrate = 9600);
    void update();
    float getDistance();

  private:
    HardwareSerial& _serial;
    uint8_t _rx, _tx;
    uint8_t _buffer[4];
    uint8_t _index = 0;
    float _distanceCm = -1.0;

    void processPacket();
};

#endif
