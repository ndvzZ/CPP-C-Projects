
#include <stdio.h>
#include "matrix.h"

Matrix* mul_scalar(const Matrix* matrix, double val) {
    if (check_for_exist(matrix)) {
        return NULL;
        } else {
        Matrix* mul_matrix = create_matrix(matrix -> num_rows, matrix -> num_cols);
        size_t M = matrix -> num_cols;
        for (size_t i = 0; i < matrix -> num_rows; i++) {
            for (size_t j = 0; j < matrix -> num_cols; j++) {
                mul_matrix -> value[i*M+j] = val * (matrix -> value[i*M+j]);
            }
        }
        return mul_matrix;
        }
}
