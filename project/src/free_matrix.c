#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "if_exist_matr.h"

void free_matrix(Matrix* matrix) {
    if (!(check_for_exist(matrix)))
    puts("can`t free non-existing matrix");
    free(matrix->value);
}
