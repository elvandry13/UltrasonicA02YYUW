/**
 * @file BasicRead.ino
 * @author Elvandry Ghiffary (elvandry13@gmail.com)
 * @brief Basic read ultrasonic A02YYUW
 * @version 0.1
 * @date 2025-06-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <UltrasonicA02YYUW.h>

UltrasonicA02YYUW sensor(Serial2, 16, 17); // RX, TX

void setup() {
  Serial.begin(115200);
  sensor.begin();
}

void loop() {
  sensor.update();  // panggil rutin di loop

  float d = sensor.getDistance();
  if (d > 0) {
    Serial.print("Jarak: ");
    Serial.print(d);
    Serial.println(" cm");
  }

  delay(500);
}
