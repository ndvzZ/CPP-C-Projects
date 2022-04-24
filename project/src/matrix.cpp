#include "matrix.h"
#include "exceptions.h"
#include <iostream>
#include <fstream>
#include <math.h>

bool is_equal(double a_compare, double b_compare);

namespace prep {

    // Конструкторы

    Matrix::Matrix(size_t num_rows, size_t num_cols) {
    if (num_rows > 0 && num_cols > 0) {
        rows = num_rows;
        cols = num_cols;
        value.reserve(rows * cols);
        /*for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                value[i * cols + j] = 0;
            } 
        } */
    }
    rows = 0;
    cols = 0;
    value.reserve(1);
    }

    /* explicit Matrix::Matrix(std::istream& is) {
        ifstream file;
        if (!file) {
            std::cout << "error to open file";
        }
            while(!EOF(file)) {

            }
        } */

    // Базовые методы

    size_t Matrix::getRows() const {
        return rows;
    }
    size_t Matrix::getCols() const {
        return cols;
    }

    double Matrix::operator()(size_t i, size_t j) const {
        if (i > rows || j > cols) {
        //  OutOfRange(i, j, *this);
            return value[0];
        }
        return value[cols * i + j];
    }

    double& Matrix::operator()(size_t i, size_t j) {
        if (i > rows || j > cols) {
        //   OutOfRange(i, j, *this);
        }
        double &val = value[cols * i + j];
        return val;
    }

    // Операторы сравнения

    bool Matrix::operator==(const Matrix& rhs) const {
        if ((rows == rhs.rows) && (cols == rhs.cols)) {
            bool buf = true;
            for (size_t i = 0; i < rhs.rows; i++) {
                for (size_t j = 0; j < rhs.cols; j++) {
                    if (!is_equal(value[i * cols + j], rhs.value[i * cols + j]))
                        buf = false;
                }
            }
            return buf;
        }
        return false;
    }

    bool Matrix::operator!=(const Matrix& rhs) const {
        if ((rows == rhs.rows) && (cols == rhs.cols)) {
            bool buf = false;
            for (size_t i = 0; i < rhs.rows; i++) {
                for (size_t j = 0; j < rhs.cols; j++) {
                    if (!is_equal(value[i * cols + j], rhs.value[i * cols + j]))
                        buf = true;
                }
            }
            return buf;
        }
        return true;
    }

    bool is_equal(double a_compare, double b_compare) {
        double epsilon = 1e-07;
        if (fabs(a_compare - b_compare) <= epsilon)
            return true;
        return false;
    }

    // Вывод матрицы в поток

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; i++) {
                for (size_t j = 0; j < matrix.cols; j++) {
                    if (j == 0) {
                        os << matrix.value[i * matrix.cols];
                    }
                    if (j == matrix.cols) {
                        os << " " << matrix.value[i * matrix.cols + j] << std::endl;
                    }
                    os  << " " << matrix.value[i * matrix.cols + j];
                }
        }
        return os;
    }

    // Арифметические операторы

    Matrix Matrix::operator+(const Matrix& rhs) const {
        size_t num_rows = rhs.getRows();
        size_t num_cols = rhs.getCols();
        if (!((rows == num_rows) && (cols == num_cols))) {
        //    DimensionMismatch(*this, rhs);
            return *this;
        }
        Matrix Result(num_rows, num_cols);
        for (size_t i = 0; i < num_rows; i++) {
            for (size_t j = 0; j < num_cols; j++) {
                Result.value[i * num_cols + j] = value[i * num_cols + j] + rhs.value[i * num_cols + j];
            }
        }
        return Result;
    }

    Matrix Matrix::operator-(const Matrix& rhs) const {
        size_t num_rows = rhs.getRows();
        size_t num_cols = rhs.getCols();
        if (!((rows == num_rows) && (cols == num_cols))) {
        //    DimensionMismatch(*this, rhs);
            return *this;
        }
        Matrix Result(num_rows, num_cols);
        for (size_t i = 0; i < num_rows; i++) {
            for (size_t j = 0; j < num_cols; j++) {
                Result.value[i * num_cols + j] = value[i * num_cols + j] - rhs.value[i * num_cols + j];
            }
        }
        return Result;
    }

    Matrix Matrix::operator*(const Matrix& rhs) const {
    if ((rows == rhs.cols) || (cols == rhs.rows)) {
    Matrix multiply(rows, rhs.cols);
    size_t mid = cols;
    size_t n = multiply.rows;
    size_t m = multiply.cols;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            double buf = 0;
            for (size_t k = 0; k < mid; k++) {
                buf += value[i * cols + k] * rhs.value[k * rhs.cols + j];
            }
        multiply.value[i * multiply.cols + j] = buf;
        }
    }
    return multiply;
    }
    printf("Imposibble to multiply matrixes");
    return *this;
}

    Matrix Matrix::operator*(double val) const {
        Matrix mul_matrix(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                mul_matrix.value[i * cols + j] = value[i * cols + j] * val;
            }
        }
        return mul_matrix;
    }

    Matrix operator*(double val, const Matrix& matrix) {
        Matrix mul_matrix(matrix.rows, matrix.cols);
        for (size_t i = 0; i < matrix.rows; i++) {
            for (size_t j = 0; j < matrix.cols; j++) {
                mul_matrix.value[i * matrix.cols + j] = val * matrix.value[i * matrix.cols + j];
            }
        }
        return mul_matrix;
    }

    Matrix Matrix::transp() const {
        Matrix Result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                Result.value[i * cols + j] = value[j * cols + i];
            }
        }
        return Result;
    }



    // Дополнительные математические операции

    double Matrix::det() const {
    if (cols != rows) {
       // DimensionMismatch(*this);
       return -1;
    }
    size_t n = rows;
    if (n == 1) {
        return value[0];
    } else if (n == 2) {
        return value[0] * value[3] - value[2] * value[1];
    } else {
        int minor_sign = 1;
        double determinant = 0;
        Matrix minor = *this;
        for (size_t i = 0; i < n; i++) {
            minor.delete_i_j(0, i);
                determinant += minor_sign * minor.det() * minor.value[i];
                minor_sign *= -1;
            }
            minor.~Matrix();
            return determinant;
        }
    }

    Matrix Matrix::delete_i_j(size_t num_rows, size_t num_cols) const {
    Matrix minor(rows - 1, cols - 1);
        size_t n = rows;
        int pointer = 0;
        for (size_t i = 0; i < n; i++) {
            if (i != num_rows) {
                for (size_t j = 0; j < n; j++) {
                    if (j != num_cols) {
                        minor.value[pointer] = value[i * n + j];
                        pointer++;
                    }
                }
            }
        }
        return minor;
    }

    Matrix Matrix::adj() const {
    size_t n = rows;
    if (n < 1) {
        puts("uncountable det");
        return *this;
    }
    Matrix adject(n, n);
    if (n == 1) {
        adject.value[0] = 1;
        return adject;
    }
    double minor_det;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                Matrix minor = *this;
                minor.delete_i_j(j, i);
                minor_det = minor.det();
                int minor_sign = ((i + j) % 2)? -1: 1;
                adject.value[i * n + j] = minor_sign * minor_det;
                minor.~Matrix();
            }
        }
    return adject;
    }

    Matrix Matrix::inv() const {
    Matrix buf = *this;
    double determinant = buf.det();
    if (determinant == 0) {
        puts("error determinant");
        return buf;
    }
    double value = 1/determinant;
    Matrix adjected = buf.adj();
    Matrix invert_matr = adjected * value;
    adjected.~Matrix();
    return invert_matr;
    }

}   // namespace prep
