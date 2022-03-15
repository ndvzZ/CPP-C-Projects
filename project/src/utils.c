#include "utils.h"
#include <stdio.h>
size_t timer_from(unsigned char from) {
    size_t counter=0;
    for (unsigned char i = from; i > 0; --i) {
        ++counter;
        printf("%d",i);
    }
    return counter;
}
