#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix(size_t rows, size_t cols) {
    Matrix *matrix;
    matrix->num_rows = rows;
    matrix->num_cols = cols;
    matrix->value = malloc(matrix->num_rows * matrix->num_cols * sizeof(double));
    for (int i=0; i < matrix->num_rows; i++) {
                for (int j=0; j < matrix->num_cols; j++) {
                    matrix->value[i][j] = 0;
            }
        }
    return matrix;
}
