#include <stdio.h>
#include "matrix.h"

int check_for_exist(const Matrix *matrix) {
    if (!matrix || !(matrix->value)) {
        puts("matrix doesnt`t exist");
        return 1;
    }
    return 0;
}
