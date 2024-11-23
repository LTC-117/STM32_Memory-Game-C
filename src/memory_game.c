#include "memory_game.h"
#include "setup.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"


//Random Number Generator
uint32_t random(uint32_t *seed){
    const uint32_t a = 1664525;
    const uint32_t c = 1013904223;
    const uint32_t m = 4294967295;

    *seed = (a * (*seed) + c) % m;

    return *seed;
}


void game_tick(){
    static uint32_t seed = 10387;
    uint32_t ledAction[6] = {0};
//    uint32_t buttonResponse[6] = {0};

    //LED Action:
    for(int a = 0; a<6; a++){
        //Generates a random sequence of 13, 14, and 15
        ledAction[a] = (random(&seed) % 3) + 13;
    }

    for(int i = 0; i<6; i++){
        //Displays the sequence created to the user
        LED_Blink(ledAction[i]);
        HAL_Delay(500);
    }

    //Read User Answer
    for(int b=0; b<6; ){
        if(Button(13) == GPIO_PIN_SET || Button(14) == GPIO_PIN_SET || Button(15) == GPIO_PIN_SET){
            HAL_Delay(10); //Debounce
            if(Button(ledAction[b]) == GPIO_PIN_SET){
                b++;
            }
            else{
                Buzzer();
                HAL_Delay(500);
                game_tick();
            }
        }
    }

    //Feedback:
    for(int c=0; c<3; c++){
        //Displays correct answer sequence
        LED(13, GPIO_PIN_SET);
        LED(14, GPIO_PIN_SET);
        LED(15, GPIO_PIN_SET);
        HAL_Delay(1000);
        LED(13, GPIO_PIN_RESET);
        LED(14, GPIO_PIN_RESET);
        LED(15, GPIO_PIN_RESET);
        HAL_Delay(500);
    }

    seed += 5;
}


