#include <stdio.h>
#include "if_exist_matr.h"
#include "matrix.h"

int check_for_exist(const Matrix *matrix) {
    if ((matrix = NULL) || (matrix->value != NULL)) {
        puts("matrix doesnt`t exist");
        return 0;
    }
    return 1;
}
