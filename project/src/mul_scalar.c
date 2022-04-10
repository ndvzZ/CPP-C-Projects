
#include <stdio.h>
#include "matrix.h"

Matrix* mul_scalar(const Matrix* matrix, double val) {
    size_t *rows, *cols;
    double *elem;
    if (!check_for_exist(matrix))
        puts("can`t scalar multiply non-existing matrix");
    for (int i=0; i < get_rows(matrix, rows); i++) {
        for (int j=0; j < get_cols(matrix, cols); j++) {
            *elem = get_elem(matrix, i, j, elem);
            *elem =*elem*val;
        }
    }
    return matrix;
}
