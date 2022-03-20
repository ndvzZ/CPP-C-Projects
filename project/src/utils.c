#include "utils.h"
#include <stdio.h>
size_t timer_from(int from) {
    size_t counter = 0;
    for (int i = from; i >= 0; --i) {
        if (i != 0) {
            ++counter;
            printf("%d ", i);
        } else {
            ++counter;
            printf("%d\n", i);
        }
    }
    return counter;
}

int custom_pow(int base, int power) {
    int x = 1;
    for (int i=1; i <= power; i++) {
        x*=base;
    }
    return x;
}
