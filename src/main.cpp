#include <Arduino.h>
#include <ftb.h>

void setup() {
    initPCA9685();
}

void loop() {
    motorA(-20);
    motorB(-20);
    motorC(-20);
    motorD(-20);
    delay(2000);
}