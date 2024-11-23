#include "setup.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>


void LED(uint16_t Pin, GPIO_PinState state){
    uint16_t ledPin =   Pin == 13 ? GPIO_PIN_13 :
                        Pin == 14 ? GPIO_PIN_14 :
                        Pin == 15 ? GPIO_PIN_15 :
                        0;

    if(state == GPIO_PIN_SET){
        HAL_GPIO_WritePin(GPIOC, ledPin, GPIO_PIN_SET);
    } else{
        HAL_GPIO_WritePin(GPIOC, ledPin, GPIO_PIN_RESET);
    }
}


void LED_Blink(uint32_t ledBit){
    LED(ledBit, GPIO_PIN_SET);
    HAL_Delay(500);
    LED(ledBit, GPIO_PIN_RESET);
}


GPIO_PinState Button(uint16_t Pin){
    uint16_t ledPin =       Pin == 13 ? GPIO_PIN_13 :
                            Pin == 14 ? GPIO_PIN_14 :
                            Pin == 15 ? GPIO_PIN_15 :
                            0;

    uint16_t buttonPin =    ledPin == GPIO_PIN_13 ? GPIO_PIN_4 :
                            ledPin == GPIO_PIN_14 ? GPIO_PIN_5 :
                            ledPin == GPIO_PIN_15 ? GPIO_PIN_6 :
                            0;

    if(HAL_GPIO_ReadPin(GPIOA, buttonPin) == GPIO_PIN_RESET){
        LED_Blink(Pin);
        return GPIO_PIN_SET;
    } else{
        return GPIO_PIN_RESET;
    }
}


void Buzzer(){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
}
