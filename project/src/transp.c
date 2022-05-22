#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


Matrix* transp(const Matrix* matrix) {
    if (check_for_exist(matrix)) {
        puts("can`t transp non-existing matrix");
        return NULL;
    }
    Matrix* transp_matrix = create_matrix(matrix -> num_cols, matrix -> num_rows);
    double *buf = malloc(sizeof(double));
        for (size_t i=0; i < matrix->num_rows; i++) {
            for (size_t j=0; j < matrix->num_cols; j++) {
                get_elem(matrix, i, j, buf);
                set_elem(transp_matrix, j, i, *buf);
            }
        }
    free(buf);
    return transp_matrix;
}
