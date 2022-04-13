#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


Matrix* adj(const Matrix* matrix) {
    if (check_for_exist(matrix))
        return NULL;
    if (matrix->num_rows != matrix->num_cols)
        return NULL;
    size_t n = matrix->num_rows;
    if (n < 1) {
        puts("uncountable det");
        return NULL;
    }
    Matrix* transp_matr = transp(matrix);
    Matrix* adject = create_matrix(n, n);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                delete_i_j(transp_matr, i, j);
                adject->value[i*n + j] = det(transp_matr, transp_matr->value);
            }
        }
    return adject;
}
