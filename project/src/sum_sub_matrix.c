#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* arifmetic(const Matrix* left, const Matrix* right, arifmetic_func fn) {
    if (check_for_exist(left) || check_for_exist(right)) {
        fprintf(stderr, INPUT_ERR);
        return NULL;
    }
    if (left -> num_cols != right -> num_cols || left -> num_rows != right -> num_rows) {
        fprintf(stderr, DIMENTION_ERR);
        return NULL;
    }
    size_t n = left -> num_rows;
    size_t m = left -> num_cols;
    Matrix * arifmetic_matrix = create_matrix(left -> num_rows, right -> num_cols);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            arifmetic_matrix -> value[i * m + j] = fn(left -> value[i * m + j], right -> value[i * m + j]);
        }
    }
    return arifmetic_matrix;
}

double summary(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

Matrix* sum(const Matrix* left, const Matrix* right) {
    return arifmetic(left, right, summary);
}

Matrix* sub(const Matrix* left, const Matrix* right) {
    return arifmetic(left, right, subtract);
}

