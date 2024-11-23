#ifndef SETUP_H_
#define SETUP_H_

#include "main.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>

void LED(uint16_t Pin, GPIO_PinState state);
void LED_Blink(uint32_t ledBit);
GPIO_PinState Button(uint16_t Pin);
void Buzzer();

#endif
