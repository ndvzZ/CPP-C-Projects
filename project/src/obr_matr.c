#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

_Bool is_equal(double a, double b);

Matrix* inv(const Matrix* matrix) {
    if (check_for_exist(matrix))
        return NULL;
    double determinant;
    int buff = det(matrix, &determinant);
    if (is_equal(determinant, 0.0) || buff) {
        puts("error determinant");
        return NULL;
    }
    double value = 1/determinant;
    Matrix *adjected = adj(matrix);
    Matrix *invert_matr = mul_scalar(adjected, value);
    free_matrix(adjected);
    return invert_matr;
}

_Bool is_equal(double a, double b) {
    double epsilon = 0.00000000001;
    return (fabs(a-b) < epsilon);
}
