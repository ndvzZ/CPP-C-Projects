#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* adj(const Matrix* matrix) {
    if (check_for_exist(matrix))
        return NULL;
    if ((matrix->num_rows != matrix->num_cols) || (matrix ->num_cols == 0))
        return NULL;
    size_t n = matrix->num_rows;
    if (n < 1) {
        puts("uncountable det");
        return NULL;
    }
    Matrix* adject = create_matrix(n, n);
    if (n == 1) {
        adject -> value[0] = 1;
        return adject;
    }
    double minor_det;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                Matrix* minor = delete_i_j(matrix, j, i);
                if ((minor != NULL) && !(det(minor, &minor_det))) {
                    int minor_sign = ((i + j) % 2)? -1: 1;
                adject -> value[i * n + j] = minor_sign * minor_det;
            }
            free_matrix(minor);
        }
    }
    return adject;
}
