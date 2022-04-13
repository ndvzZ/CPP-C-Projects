#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int det(const Matrix* matrix, double* val) {
    if (check_for_exist(matrix) || !val)
        return -1;
    if (matrix->num_rows != matrix->num_cols) {
        puts("uncountable det");
        return -1;
    }
    size_t n = matrix->num_rows;
    if (n < 1) {
        puts("uncountable det");
        return -1;
    }
    int determinant = 0;
    if (n == 2) {
        determinant = matrix->value[0] * matrix->value[4] - matrix->value[3] * matrix->value[2];
        return determinant;
    }
    if (n > 2) {
        int k = 1;
        for (size_t i = 0; i < matrix -> num_rows; i++) {
            delete_i_j(matrix, i, 0);
            determinant = determinant + k * matrix->value[i*matrix->num_rows] * det(matrix, matrix->value);
        }
        return determinant;
    }
    return -1;
}

Matrix* delete_i_j(const Matrix* matrix, size_t row, size_t col) {
    if (check_for_exist(matrix))
        return NULL;
    Matrix* new_matrix = create_matrix(matrix -> num_rows - 1, matrix -> num_cols - 1);
        size_t i1 = 0;
        size_t j1 = 0;
        double *buf = malloc(sizeof(double));
        for (size_t i = 0; i <  matrix -> num_rows; i++) {
            if (i != row) {
                for (size_t j = 0; j < matrix -> num_cols; j++) {
                    if (j != col) {
                        while (j1 < matrix -> num_cols - 1) {
                        get_elem(matrix, i, j, buf);
                        set_elem(new_matrix, i1, j1, *buf);
                        j1++;
                        }
                    }
                }
                i1++;
            }
        }
        free(buf);
    return new_matrix;
}
