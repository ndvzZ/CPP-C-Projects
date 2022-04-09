
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix_from_file(const char* path_file){
    Matrix matrix;
    FILE *matrix_data = fopen(path_file, "r");
    if (matrix_data == NULL) {
        perror("Not file exist");
    } else {
        fscanf(matrix_data, "%d%d", matrix.num_rows, matrix.num_cols);
        matrix.value = malloc(matrix.num_rows*matrix.num_cols*sizeof(double));
        while (fscanf(matrix_data, "%lf", &matrix.value) != -1) {
            for (int i=0; i < matrix.num_rows; i++) {
                for (int j=0; j < matrix.num_cols; j++) {
                    fscanf(matrix_data, "%lf", &matrix.value[i][j]);
                }
            }
        }
    fclose(matrix_data);}
return &matrix;
}