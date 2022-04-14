#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void free_matrix(Matrix* matrix) {
    if (matrix != NULL) {
        if (matrix -> value != NULL) {
            free(matrix -> value);
        }
        free(matrix);
    }
}
