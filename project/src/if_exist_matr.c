#include <stdio.h>
#include "if_exist_matr.h"

int check_for_exist(Matrix *matrix) {
    size_t *rows, *cols;
    if ((get_rows(matrix, rows) == 0) || (get_cols(matrix, cols) == 0)) {
        puts("matrix doesnt`t exist");
        return 0;}
    return 1;
}
