
#include <stdio.h>
#include "matrix.h"

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (check_for_exist(row,col) != 0) {
    *val = matrix->value[row][col];
    return *val;
    } else {
        return -1;}
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (check_for_exist(row,col) != 0) {
    matrix->value[row][col] = scanf("lf", &matrix->value[row][col]);
    return 0;
    } else {
        return -1;
    }
}
