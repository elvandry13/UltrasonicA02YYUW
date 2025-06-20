# UltrasonicA02YYUW Arduino Library

Non-blocking driver for the DFRobot A02YYUW Waterproof Ultrasonic Sensor via UART (HardwareSerial).

## Features

- ✅ Non-blocking `update()` method — no delays
- ✅ Supports ESP32/ESP8266/Arduino with HardwareSerial
- ✅ Distance readout in centimeters
- ✅ Validates checksum and range (3–750 cm)
- ✅ Easy integration with other sensor loops

## Sensor Info

- **Model**: DFRobot A02YYUW (SKU: SEN0311)
- **Range**: 3 cm – 750 cm
- **Interface**: UART TTL 3.3–5V
- **Default baudrate**: 9600 bps
- **Data format**: 4 bytes: `0xFF HIGH LOW SUM`

## Wiring (ESP32 Example)

| Sensor Pin | ESP32 Pin   |
|------------|-------------|
| VCC        | 5V          |
| GND        | GND         |
| TX         | GPIO16 (RX) |
| RX         | (not used)  |

## Example Usage

```cpp
#include <UltrasonicA02YYUW.h>

UltrasonicA02YYUW sensor(Serial2, 16, 17); // RX, TX

void setup() {
  Serial.begin(115200);
  sensor.begin();  // defaults to 9600 baud
}

void loop() {
  sensor.update();  // non-blocking parser

  float distance = sensor.getDistance();
  if (distance > 0) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500);
}
```

## API Reference

### `void begin(unsigned long baudrate = 9600)`
Start the sensor with a baudrate. Default is 9600.

### `void update()`
Call this continuously in `loop()` to read serial data.

### `float getDistance()`
Returns the last valid distance in cm, or `-1.0` if invalid or unavailable.

## License

MIT © 2025 Elvandry Ghiffary
