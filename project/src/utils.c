#include "utils.h"
#include <stdio.h>
size_t timer_from(int from) {
    size_t counter = 0;
    for (int i = from; i >= 0; --i) {
        if (i != 0) {
        ++counter;
        printf("%d ", i);} else {
        ++counter;
        printf("%d\n", i);
        }
    }
    return counter;
}
