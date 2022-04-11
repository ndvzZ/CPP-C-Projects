
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix_from_file(const char* path_file){
    FILE *matrix_data = fopen(path_file, "r");
    if (matrix_data == NULL)
        perror("Not file exist");
    Matrix matrix;
    fscanf(matrix_data, "%zu%zu", &matrix.num_rows, &matrix.num_cols);
        for (size_t i=0; i < matrix.num_rows; i++) {
            for (size_t j=0; j < matrix.num_cols; j++) {
                fscanf(matrix_data, "%lf", &matrix.value[i][j]);
            }
    }
    Matrix *ptr_matrix = NULL;
    ptr_matrix = malloc(matrix.num_rows * matrix.num_cols * sizeof(double)+ 2 * sizeof(size_t));
    ptr_matrix->num_rows = matrix.num_rows;
    ptr_matrix->num_cols = matrix.num_cols;
    for (size_t i = 0; i < matrix.num_rows; i++){
        for (size_t j=0; j < matrix.num_cols; j++) {
            ptr_matrix->value[i][j] = matrix.value [i][j];
        }
    }

    fclose(matrix_data);
    return ptr_matrix;
}
