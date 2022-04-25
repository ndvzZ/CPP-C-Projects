#pragma once // NOLINT

#include <vector>
#include <istream>

bool is_equal(double a_compare, double b_compare);

namespace prep {
class Matrix {
  size_t rows;
  size_t cols;
  std::vector<double>value;

 public:
  explicit Matrix(size_t num_rows = 0, size_t num_cols = 0);
  explicit Matrix(std::istream& is);
  Matrix(const Matrix& rhs);
  Matrix& operator=(const Matrix& rhs);
  ~Matrix() = default;

  size_t getRows() const;
  size_t getCols() const;

  double operator()(size_t i, size_t j) const;
  double& operator()(size_t i, size_t j);

  bool operator==(const Matrix& rhs) const;
  bool operator!=(const Matrix& rhs) const;

  Matrix operator+(const Matrix& rhs) const;
  Matrix operator-(const Matrix& rhs) const;
  Matrix operator*(const Matrix& rhs) const;

  Matrix operator*(double val) const;

  friend
  Matrix operator*(double val, const Matrix& matrix);
  friend
  std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

  Matrix transp() const;
  double det() const;
  Matrix adj() const;
  Matrix inv() const;
  Matrix delete_i_j(size_t num_rows, size_t num_cols) const;
  //double Minor(size_t x, size_t y) const;
  //double AlgCompl(size_t x, size_t y) const;
};

Matrix operator*(double val, const Matrix& matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
}  // namespace prep
