#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

    Matrix* inv(const Matrix* matrix) {
    if (check_for_exist(matrix))
        return NULL;
    double determinant;
    int buff = det(matrix, &determinant);
    if ((determinant == 0 || buff)) {
        puts("error determinant");
        return NULL;
    }
    double value = 1/determinant;
    Matrix *adjected = adj(matrix);
    Matrix *invert_matr = mul_scalar(adjected, value);
    free_matrix(adjected);
    return invert_matr;
}
