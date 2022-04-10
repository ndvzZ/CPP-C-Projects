#include <stdio.h>
#include "matrix.h"

Matrix* transp(const Matrix* matrix) {
    size_t *rows, *cols;
    double *elem, *switch_elem, buffer;
    if (!(check_for_exist(matrix))
        puts("can`t transp non-existing matrix");
    for (int i=0; i < get_rows(matrix, rows); i++) {
        for (int j=0; j < get_cols(matrix, cols); j++) {
            *elem = get_elem(matrix, i, j, elem);
            *switch_elem = get_elem(matrix, j, i, switch_elem);
            buffer = *elem;
            *elem = *switch_elem;
            *switch_elem = buffer;
        }
    }
    return matrix;
}
