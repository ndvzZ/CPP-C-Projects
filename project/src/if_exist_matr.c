#include <stdio.h>
#include "matrix.h"

int check_for_exist(const Matrix *matrix) {
    if (!matrix || !matrix->value || matrix->num_rows == 0 || matrix->num_cols == 0) {
        puts("matrix doesnt`t exist");
        return 1;
    }
    return 0;
}
