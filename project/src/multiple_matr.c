#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


    Matrix* mul(const Matrix* left, const Matrix* right) {
    if (check_for_exist(left) || check_for_exist(right)) {
        fprintf(stderr, INPUT_ERR);
        return NULL;
    }
    if (left -> num_cols != right -> num_rows) {
        fprintf(stderr, MULTIPLY_ERR);
        return NULL;
    }
    Matrix * multiply = create_matrix(left -> num_rows, right -> num_cols);
    size_t mid = left -> num_cols;
    size_t n = multiply -> num_rows;
    size_t m = multiply -> num_cols;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            double buf = 0;
            for (size_t k = 0; k < mid; k++) {
                buf += left -> value[i * left -> num_cols + k] * right -> value[k * right -> num_cols + j];
            }
        multiply -> value[i * multiply -> num_cols + j]= buf;
        }
    }
    return multiply;
}
