#include <avr/io.h>

#define I2C_W 				0x00
#define I2C_R				0x01
#define BIT_RATE_REGISTER 	32			//p.222 datasheet

void initI2C(void);

void i2cWaitForComplete(void);

void i2cStart(void);

void i2cStop(void);

void i2cSend(uint8_t data);

uint8_t i2cReadAck(void);

uint8_t i2cReadNoAck(void);

uint8_t readStatus(void);
