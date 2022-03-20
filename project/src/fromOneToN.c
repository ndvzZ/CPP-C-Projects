#include <stdio.h>

void oneToN(int num) {
    if (num == 1) {
        printf("%d", num);
    } else {
            if (num > 0) {
                oneToN(num - 1);
                printf(" ");
                printf("%d", num);
            } else {
                oneToN(num + 1);
                printf(" ");
                printf("%d", num);
            }
        }
}
