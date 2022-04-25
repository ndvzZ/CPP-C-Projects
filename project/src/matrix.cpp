#include "matrix.h"
#include "exceptions.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <limits>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

bool is_equal(double a_compare, double b_compare) {
        double epsilon = 1e-07;
        if (fabs(a_compare - b_compare) <= epsilon)
            return true;
        return false;
    }

namespace prep {

    // Конструкторы

    Matrix::Matrix(size_t num_rows, size_t num_cols) {
        if (num_rows > 0 && num_cols > 0) {
            rows = num_rows;
            cols = num_cols;
            value.reserve(rows * cols);
            for (size_t i = 0; i < rows * cols; i++) {
                value[i] = 0;
            }
        }
    }

    // Создание матрицы из файла

    Matrix::Matrix(std::istream& is) {
        is >> rows;
        is >> cols;
        if (rows == 0 || cols == 0 || is.fail()) {
            value.clear();
            throw InvalidMatrixStream();
        }
        value.reserve(rows * cols);
        for (size_t i = 0; i < rows * cols; i++) {
            is >> value[i];
            if (is.fail()) {
                value.clear();
                throw InvalidMatrixStream();
            }
        }
    }


    Matrix::Matrix(const Matrix& rhs) {
        rows = rhs.rows;
        cols = rhs.cols;
        value.reserve(cols * rows);
        for (size_t i = 0; i < rows * cols; i++) {
        value[i] = rhs.value[i];
        }
    }

    Matrix& Matrix::operator=(const Matrix& rhs) {
        rows = rhs.rows;
        cols = rhs.cols;
        value.reserve(cols * rows);
        for (size_t i = 0; i < rows * cols; i++) {
        value[i] = rhs.value[i];
        }
        return *this;
    }


    // Базовые методы

    size_t Matrix::getRows() const {
        return rows;
    }
    size_t Matrix::getCols() const {
        return cols;
    }

    double Matrix::operator()(size_t i, size_t j) const {
        if (i >= rows || j >= cols) {
            throw OutOfRange(i, j, *this);
            return value[0];
        }
        return value[cols * i + j];
    }

    double& Matrix::operator()(size_t i, size_t j) {
        if (i >= rows || j >= cols) {
            throw OutOfRange(i, j, *this);
        }
        return value[cols * i + j];
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
        return !(*this == rhs);
    }

    // Вывод матрицы в поток

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << matrix.rows << ' ' << matrix.cols << std::endl;
    for (size_t i = 0; i < matrix.rows; i++) {
        for (size_t j = 0; j < matrix.cols; j++) {
            os << std::fixed << std::setprecision(std::numeric_limits<float>::max_digits10)
               << matrix.value[i*matrix.cols+j];
            if (j != matrix.cols - 1) {
                os << ' ';
            }
        }
        os << std::endl;
    }
    return os;
    }

    // Арифметические операторы

    Matrix Matrix::operator+(const Matrix& rhs) const {
        size_t num_rows = rhs.getRows();
        size_t num_cols = rhs.getCols();
        if (num_rows == 0 || num_cols == 0)
            throw DimensionMismatch(*this, rhs);
        if (!((rows == num_rows) && (cols == num_cols))) {
            throw DimensionMismatch(*this, rhs);
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
        if (num_rows == 0 || num_cols == 0)
            throw DimensionMismatch(*this, rhs);
        if (!((rows == num_rows) && (cols == num_cols))) {
            throw DimensionMismatch(*this, rhs);
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
        if (rhs.rows == 0 || rhs.cols == 0)
            throw DimensionMismatch(*this, rhs);
        if (cols != rhs.rows) {
            throw DimensionMismatch(*this, rhs);
        }
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
        Matrix Result(cols, rows);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                Result.value[j * rows + i] = value[i * cols + j];
            }
        }
        return Result;
    }


    // Дополнительные математические операции

    double Matrix::det() const {
        if (cols != rows) {
            throw DimensionMismatch(*this);
        }
        size_t n = rows;
        if (n == 1) {
            return value[0];
        }
        if (n == 2) {
            return value[0] * value[3] - value[2] * value[1];
            }
        double determinant = 0;
        for (size_t i = 0; i < n; i++) {
                Matrix minor = this->delete_i_j(0, i);
                determinant += pow(-1, i + 2) * minor.det() * this->value[i];
            }
            return determinant;
        }

    Matrix Matrix::delete_i_j(size_t num_rows, size_t num_cols) const {
    Matrix minor(rows - 1, cols - 1);
        size_t n = rows;
        size_t pointer = 0;
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
        if (rows != cols) {
            throw DimensionMismatch(*this);
        }
        size_t n = rows;
        if (n < 1) {
            throw DimensionMismatch(*this);
        }
        Matrix adject(n, n);
        if (n == 1) {
            adject.value[0] = 1;
            return adject;
        }
        double minor_det;
        Matrix transp = this->transp();
            for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++) {
                    Matrix minor = transp.delete_i_j(i, j);
                    minor_det = minor.det();
                    int minor_sign = ((i + j) % 2)? -1: 1;
                    adject.value[i * n + j] = minor_sign * minor_det;
                }
            }
        return adject;
    }

    Matrix Matrix::inv() const {
        double determinant = this->det();
        if (determinant == 0) {
            throw SingularMatrix();
        }
        double value = 1/determinant;
        Matrix adjected = this->adj();
        Matrix invert_matr = adjected * value;
        adjected.value.clear();
        return invert_matr;
    }

}   // namespace prep
