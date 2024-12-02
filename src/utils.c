#include "../include/utils.h"

#include <stdlib.h>

int StringLength(char *str) {
    int count = 0;
    while(str[count]) ++count;
    return count+1;
}

#define NEWTONS_METHOD_ITERATIONS 25

float SquareRoot(float x) {
    float approx = x/2;
    // f(a)  = a*a - x      -> sqrt(x) is a root of this polynomial
    // f'(a) = 2a
    for (int i = 0; i < NEWTONS_METHOD_ITERATIONS; ++i) {
        approx = approx - ((approx*approx - x)/(2*approx));
    }
    return approx;
}

