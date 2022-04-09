#include <stdio.h>
#include "file_openers.h"

FILE *file_opener_read(const char *filename) {
    FILE *ptr = fopen(filename, "r");
    if (ptr == NULL)
        puts("Not acess");
    return ptr;
}

FILE *file_opener_read_plus(const char *filename) {
    FILE *ptr = fopen(filename, "r+");
    if (ptr == NULL)
        puts("Not acess");
    return ptr;
}

FILE *file_opener_add(const char *filename) {
    FILE *ptr = fopen(filename, "a+");
    if (ptr == NULL)
        puts("Not acess");
    return ptr;
}
