#include <stdio.h>
#include "matrix.h"
#include "if_exist_matr.h"

Matrix* mul(const Matrix* left, const Matrix* right) {
    Matrix *result;
    size_t *rows_l, *cols_l, *rows_r, *cols_r;
    double *val1, *val2, res,res1;
    if (!(check_for_exist(left) || check_for_exist(right)))
        puts("can`t multiply non-existing matrix");
    if (get_rows(left, rows_l) == get_cols(right, cols_r)) {
        int k = 0;
        for (int i = 0; i < get_rows(left, rows_l); i++) { 
            while (k < get_cols(right, cols_r)) {
                res = 0;
                for (int j = 0; j < get_cols(left, cols_l); j++) {
                    res = res + get_elem(left, i, j, val1) * get_elem(right, j, i+k, val2);
                }
                set_elem(result, i, k, res);
                k++;
            }
        }
    }
    if (get_cols(left, cols_l) == get_rows(right, rows_r)) {
        int k1 = 0;
        for (int j = 0; get_cols(left, cols_l); j++) {
            while (k1 < get_rows(right, rows_r)) {
                res1 = 0;
                for (int i = 0; get_rows(left, rows_l); i++) {
                    res1 = res1 + get_elem(left, i, j, val1) * get_elem(right, i, j+k1, val2);
                }
            set_elem(result, j, k1, res1);
            k1++;
            }
        }
    }
