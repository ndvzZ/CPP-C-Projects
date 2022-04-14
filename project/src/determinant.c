#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int det(const Matrix* matrix, double* val) {
    if (check_for_exist(matrix)) {
        fprintf(stderr, INPUT_ERR);
        return 1;
    }
    if ((matrix -> num_cols != matrix -> num_rows) || (matrix -> num_cols == 0)) {
        fprintf(stderr, "matrix isn`t square");
        return 1;
    }
    size_t n = matrix -> num_rows;
    if (n == 1) {
        *val = *(matrix -> value);
    } else if (n == 2) {
        *val = matrix -> value[0] * matrix -> value[3] - matrix -> value[2]*matrix -> value[1];
    } else {
        int minor_sign = 1;
        double determinant = 0;
        double minor_det;
        for (size_t i = 0; i < n; i++) {
            Matrix* minor = delete_i_j(matrix, 0, i);
            if ((minor != NULL) && !(det(minor, &minor_det))) {
                determinant += minor_sign * minor_det * matrix -> value[i];
                minor_sign *= -1;
            }
            free_matrix(minor);
        }
        *val = determinant;
    }
    return 0;
}

Matrix* delete_i_j(const Matrix* matrix, size_t row, size_t col) {
    if (!matrix) {
        return NULL;
    }
    Matrix* minor = create_matrix(matrix -> num_rows - 1, matrix -> num_cols - 1);
    if (minor -> value && matrix -> value) {
        size_t n = matrix -> num_rows;
        int pointer = 0;
        for (size_t i = 0; i < n; i++) {
            if (i != row) {
                for (size_t j = 0; j < n; j++) {
                    if (j != col) {
                        *(minor -> value + pointer) = matrix -> value[i * n + j];
                        pointer++;
                    }
                }
            }
        }
    }
    return minor;
}
