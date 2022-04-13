#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix(size_t rows, size_t cols) {
    if (!rows || !cols)
       return NULL;
    Matrix* new_matrix = malloc(sizeof(Matrix));
    if (!new_matrix) {
        fprintf(stderr, "can`t allocate memory");
        return NULL;
    }
    new_matrix -> num_rows = rows;
    new_matrix -> num_cols = cols;
    new_matrix -> value = calloc(rows * cols, sizeof(double));
    if (!(new_matrix -> value)) {
        free(new_matrix);
        fprintf(stderr, "can`t allocate memory");
        return NULL;
    }
    return new_matrix;
}
