#include <stdio.h>
#include "matrix.h"
#include "if_exist_matr.h"

Matrix* transp(const Matrix* matrix) {
    if (!(check_for_exist(matrix))) {
        puts("can`t transp non-existing matrix");
        return NULL;
    }
    Matrix* transp_matrix = create_matrix(matrix -> num_rows, matrix -> num_cols);                       
        for (size_t i=0; i <transp_matrix->num_rows; i++) {
            for (size_t j=0; j < transp_matrix->num_rows; j++) {
                get_elem(matrix, i, j, &matrix->value[i][j]);
            }
        }
    return transp_matrix;
}
