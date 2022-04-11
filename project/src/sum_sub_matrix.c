#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "if_exist_matr.h"

Matrix* sum(const Matrix* left, const Matrix* right) {
    Matrix *result = malloc(sizeof(Matrix));
    if (!(check_for_exist(left) || check_for_exist(right))) {
        puts("can`t sum non-existing matrix");
        free(result);
        return NULL;
    }
    if ((left->num_cols == right->num_cols) && (left->num_rows == right->num_rows)) {
        for (size_t i = 0; left->num_rows; i++) {
            for (size_t j = 0; right->num_cols; j++) {
                double *summ = malloc(sizeof(double));
                *summ = left->value[i][j] + right->value[i][j];
                set_elem(result, i, j, *summ);
                free(summ);
            }
        }
    return result;
    } else {
        puts("error");
        free(result);
        return NULL;
    }
}

Matrix* sub(const Matrix* left, const Matrix* right){
    Matrix *result = malloc(sizeof(Matrix));
    if (!(check_for_exist(left) || check_for_exist(right))) {
        puts("can`t sum non-existing matrix");
        free(result);
        return NULL;
    }
    if ((left->num_cols == right->num_cols) && (left->num_rows == right->num_rows)) {
        for (size_t i = 0; left->num_rows; i++) {
            for (size_t j = 0; right->num_cols; j++) {
                double *subb = malloc(sizeof(double));
                *subb = left->value[i][j] - right->value[i][j];
                set_elem(result, i, j, *subb);
                free(subb);
            }
        }
    return result;
    } else {
        puts("error");
        free(result);
        return NULL;
    }
}
