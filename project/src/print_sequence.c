#include <stdio.h>

void print_sequence(int num) {
    if (num == 1)
        printf("%d", num);
    if (num > 1) {
        print_sequence(num - 1);
        printf(" ");
        printf("%d", num);
    }
    if (num < 1) {
        print_sequence(num + 1);
        printf(" ");
        printf("%d", num);
    }
}
