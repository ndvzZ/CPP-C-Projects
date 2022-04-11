
#include <stdio.h>
#include "matrix.h"
#include "if_exist_matr.h"

int get_rows(const Matrix* matrix, size_t* rows) {
    if (!check_for_exist(matrix)){
        *rows = matrix->num_rows;
        return 0;
    }
    return -1;
}

int get_cols(const Matrix* matrix, size_t* cols) {
    if (!check_for_exist(matrix)){
        *cols = matrix->num_cols;
        return 0;
    }
    return -1;
}
