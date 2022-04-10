
#include <stdio.h>
#include "matrix.h"

int get_rows(const Matrix* matrix, size_t* rows) {
    *rows = matrix->num_rows;
    return *rows;
}
int get_cols(const Matrix* matrix, size_t* cols) {
    *cols = matrix->num_cols;
    return *cols;
}
