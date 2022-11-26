#pragma once
#include <stdint.h>
//#include "arm_math.h"

typedef struct coordinate{
    int8_t x, y;
} coordinate;

coordinate sumVector(coordinate vector_a, coordinate vector_b);