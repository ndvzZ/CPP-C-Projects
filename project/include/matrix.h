#ifndef PROJECT_INCLUDE_MATRIX_H_
#define PROJECT_INCLUDE_MATRIX_H_

#include <stddef.h>

#define INPUT_ERR     "Non-exising matrixes"
#define MULTIPLY_ERR  "Matrix can't be multiply"
#define DIMENTION_ERR "Diffrent nums or sizes"

typedef struct Matrix {
    size_t num_rows;
    size_t num_cols;
    double* value;
} Matrix;

    // Init/release operations
Matrix* create_matrix_from_file(const char* path_file);
Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* matrix);

    // Basic operations
int get_rows(const Matrix* matrix, size_t* rows);
int get_cols(const Matrix* matrix, size_t* cols);
int get_elem(const Matrix* matrix, size_t row, size_t col, double* val);
int set_elem(Matrix* matrix, size_t row, size_t col, double val);

    // Math operations
Matrix* mul_scalar(const Matrix* matrix, double val);
Matrix* transp(const Matrix* matrix);

Matrix* sum(const Matrix* left, const Matrix* right);
Matrix* sub(const Matrix* left, const Matrix* right);
Matrix* mul(const Matrix* left, const Matrix* right);

    // Extra operations
int det(const Matrix* matrix, double* val);
Matrix* adj(const Matrix* matrix);
Matrix* inv(const Matrix* matrix);

Matrix* delete_i_j(const Matrix* matrix, size_t row, size_t col);
int check_for_exist(const Matrix *matrix);
typedef double (* arifmetic_func)(double, double);
Matrix* arifmetic(const Matrix* left, const Matrix* right, arifmetic_func fn);
double summary(double x, double y);
double subtract(double x, double y);

#endif  // PROJECT_INCLUDE_MATRIX_H_
