#include <ftb.h>



void setPWM(uint8_t channel, uint16_t on, uint16_t off) {
    if (channel > 15) return;

    uint8_t reg = 6 + 4 * channel;

    Wire.beginTransmission(PCA9685_ADDR);
    Wire.write(reg);
    Wire.write(on & 0xFF);
    Wire.write((on >> 8) & 0xFF);
    Wire.write(off & 0xFF);
    Wire.write((off >> 8) & 0xFF);
    Wire.endTransmission();
}

void initPCA9685() {
    Wire.begin();

    // Reset MODE1
    Wire.beginTransmission(PCA9685_ADDR);
    Wire.write(0x00);
    Wire.write(0x10); // sleep
    Wire.endTransmission();

    // Set frequency to ~50Hz (good for motors/servos)
    Wire.beginTransmission(PCA9685_ADDR);
    Wire.write(0xFE);
    Wire.write(121);  // prescaler for ~50Hz
    Wire.endTransmission();

    // Wake up
    Wire.beginTransmission(PCA9685_ADDR);
    Wire.write(0x00);
    Wire.write(0x20);
    Wire.endTransmission();
}

void motorForwardA(int speed) {
    setPWM(3, 0, 0);     
    setPWM(2, 0, 4000);  
    setPWM(4, 0, speed * 40);  
}

void motorForwardB(int speed) {
    setPWM(6, 0, 0);     
    setPWM(7, 0, 4000);  
    setPWM(5, 0, speed * 40);  
}

void motorForwardC(int speed) {
    setPWM(12, 0, 0);     
    setPWM(13, 0, 4000);  
    setPWM(11, 0, speed * 40);  
}

void motorForwardD(int speed) {
    setPWM(9, 0, 0);     
    setPWM(8, 0, 4000);  
    setPWM(10, 0, speed * 40);  
}

void motorBackwardA(int speed)
{
    setPWM(10, 0, 0);     
    setPWM(8, 0, 4000);  
    setPWM(9, 0, speed * 40);  
}

void motorBackwardB(int speed)
{
    setPWM(11, 0, 0);     
    setPWM(13, 0, 4000);  
    setPWM(12, 0, speed * 40);  
}

void motorBackwardC(int speed)
{
    setPWM(5, 0, 0);     
    setPWM(7, 0, 4000);  
    setPWM(6, 0, speed * 40);  
}

void motorBackwardD(int speed)
{
    setPWM(4, 0, 0);     
    setPWM(2, 0, 4000);  
    setPWM(3, 0, speed * 40);  
}

void motorA(int speed)
{
    if(speed < 0)
    {
        motorBackwardA(speed*-1);
    }
    else
    {
        motorForwardA(speed);
    }
}

void motorB(int speed)
{
    if(speed < 0)
    {
        motorBackwardB(speed*-1);
    }
    else
    {
        motorForwardB(speed);
    }
}

void motorC(int speed)
{
    if(speed < 0)
    {
        motorBackwardC(speed*-1);
    }
    else
    {
        motorForwardC(speed);
    }
}

void motorD(int speed)
{
    if(speed < 0)
    {
        motorBackwardD(speed*-1);
    }
    else
    {
        motorForwardD(speed);
    }
}