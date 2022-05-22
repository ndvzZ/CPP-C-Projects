
#include <stdio.h>
#include "matrix.h"


int get_rows(const Matrix* matrix, size_t* rows) {
    if (check_for_exist(matrix)) {
        return -1;
    }
    *rows = matrix->num_rows;
    return 0;
}

int get_cols(const Matrix* matrix, size_t* cols) {
    if (check_for_exist(matrix)) {
        return -1;
    }
    *cols = matrix->num_cols;
    return 0;
}
