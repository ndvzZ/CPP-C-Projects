#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void free_matrix(Matrix* matrix) {
    free(matrix->value);
}
