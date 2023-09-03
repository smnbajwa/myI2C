#include <avr/io.h>
#include "myI2C.h"


void initI2C(void) {
	TWBR = BIT_RATE_REGISTER;

	TWCR |= 1 << TWEN;
}

void i2cWaitForComplete(void) {
	loop_until_bit_is_set(TWCR, TWINT);
}

void i2cStart(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTA);
	i2cWaitForComplete();
}

void i2cStop(void) {
	TWCR = ((1 << TWEN) | (1 << TWINT) | (1 << TWSTO));
}

void i2cSend(uint8_t data) {
	TWDR = data;
	TWCR = (1 << TWEN) | (1 << TWINT);
	i2cWaitForComplete();
}

uint8_t i2cReadAck(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	i2cWaitForComplete();
	return (TWDR);
}

uint8_t i2cReadNoAck(void) {
	TWCR = (1 << TWEN) | (1 << TWINT);
	i2cWaitForComplete();
	return (TWDR);
}

uint8_t readStatus(void) {
	return (TWSR & 0xF8);
}
