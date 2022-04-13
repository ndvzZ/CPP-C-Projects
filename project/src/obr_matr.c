#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* inv(const Matrix* matrix) {
    if (check_for_exist(matrix))
        return NULL;
    if (matrix->num_rows != matrix->num_cols)
        return NULL;
    size_t n = matrix->num_rows;
    if (n < 1) {
        puts("uncountable det");
        return NULL;
    }
    Matrix *invert_matr = mul_scalar(adj(matrix), 1/det(matrix, matrix->value));
    return invert_matr;
}
