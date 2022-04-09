
#include <stdio.h>
#include "matrix.h"

int get_rows(const Matrix* matrix, size_t* rows) {
    return matrix->num_rows;
}
int get_cols(const Matrix* matrix, size_t* cols) {
    return matrix->num_cols;
}
