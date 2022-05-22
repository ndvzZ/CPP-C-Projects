
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define NUMBER_MATRIX_SIZE 2

#define ALLOCATE_ERR      "Can't allocate memory"
#define ACCESS_ERR        "No access"
#define INPUT_SIZE_ERR    "Uncorrect input(size)"
#define INPUT_ELEM_ERR    "Uncorrect input(elem)"

Matrix* create_matrix_from_file(const char* path_file) {
    FILE* matrix_file = fopen(path_file, "r");
    if (!matrix_file) {
        fprintf(stderr, ACCESS_ERR);
        return NULL;
    }
    size_t rows, cols;
    if (fscanf(matrix_file, "%zu%zu", &rows, &cols) != NUMBER_MATRIX_SIZE) {
        fprintf(stderr, INPUT_SIZE_ERR);
        fclose(matrix_file);
        return NULL;
    }
    Matrix* matrix = create_matrix(rows, cols);
    if (!check_for_exist(matrix)) {
    for (size_t i = 0; i <  matrix -> num_rows; i++) {
        for (size_t j = 0; j < matrix -> num_cols; j++) {
            int buf = fscanf(matrix_file, "%lf", &(matrix -> value[i * matrix -> num_cols + j]));
            if (buf != 1 && buf == EOF) {
                fprintf(stderr, INPUT_ELEM_ERR);
                free(matrix -> value);
                free(matrix);
                fclose(matrix_file);
                return NULL;
            }
        }
    }
    fclose(matrix_file);
    return matrix;
    }
    fclose(matrix_file);
    free_matrix(matrix);
    return NULL;
}
