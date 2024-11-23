#ifndef MEMORY_GAME_H_
#define MEMORY_GAME_H_

#include "setup.h"
#include <stdint.h>

uint32_t random(uint32_t *seed);
void game_tick();

#endif
