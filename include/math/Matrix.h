#ifndef ERDO_MATRIX_H
#define ERDO_MATRIX_H

#include <algorithm>
#include <iostream>
#include <omp.h>
#include <omp_llvm.h>
#include <vector>

namespace erdo {

// I don't like concepts. From now on - no concepts.
// (Maybe I will change my mind)
template <typename T, size_t rowSize = 1, size_t colSize = 1> class Matrix {
public:
  constexpr Matrix();
  constexpr Matrix(std::vector<std::vector<T>> mat);
  constexpr Matrix(T value) {
    using std::vector;

    matrix = vector<vector<T>>(rowSize, vector<T>(colSize));

    // Copy the elements from the input vector to the matrix data member
    for (size_t i = 0; i < rowSize; ++i) {
      for (size_t j = 0; j < colSize; ++j) {
        matrix[i][j] = value;
      }
    }
  }

  ~Matrix() = default;

  constexpr Matrix(const Matrix &other);
  constexpr Matrix(Matrix &&other) noexcept;

  constexpr Matrix &operator=(const Matrix &other);
  constexpr Matrix &operator=(Matrix &&other) noexcept;

  // Function to print the matrix
  void print() const {
    using std::cout;
    using std::endl;
    using std::for_each;
    using std::vector;

    auto innerLoop = [&](T val) { cout << std::setw(6) << std::left << val; };

    auto outerLoop = [&](const vector<T> &row) {
      cout << "  [";
      for_each(row.begin(), row.end(), innerLoop);
      cout << "]\n";
    };

    cout << "{\n";
    for_each(matrix.begin(), matrix.end(), outerLoop);
    cout << "}" << endl;
  }

  // Operators
  constexpr const std::vector<T> &operator[](size_t row) const {
    if (row >= rowSize) {
      throw std::out_of_range("Invalid row index");
    }
    return matrix[row];
  }

  constexpr std::vector<T> &operator[](size_t row) {
    if (row >= rowSize) {
      throw std::out_of_range("Invalid row index");
    }
    return matrix[row];
  }

  constexpr size_t getColSize() const { return colSize; }

  constexpr size_t getRowSize() const { return rowSize; }

  template <size_t realColSize>
  constexpr Matrix<T, rowSize, realColSize>
  operator*(Matrix<T, colSize, realColSize> &mat) {
    return mult<realColSize>(mat);
  }

  constexpr Matrix<T, rowSize, colSize>
  operator+(const Matrix<T, rowSize, colSize> &other) {
    Matrix<T, rowSize, colSize> result;
    for (size_t i = 0; i < rowSize; ++i) {
      for (size_t j = 0; j < colSize; ++j) {
        result[i][j] = matrix[i][j] + other[i][j];
      }
    }
    return result;
  }

  constexpr Matrix<T, rowSize, colSize>
  operator-(const Matrix<T, rowSize, colSize> &other) {
    Matrix<T, rowSize, colSize> result;
    for (size_t i = 0; i < rowSize; ++i) {
      for (size_t j = 0; j < colSize; ++j) {
        result[i][j] = matrix[i][j] - other[i][j];
      }
    }
    return result;
  }

  constexpr Matrix operator*(const T &scalar) const {
    Matrix result;
    for (size_t i = 0; i < rowSize; ++i) {
      for (size_t j = 0; j < colSize; ++j) {
        result[i][j] = matrix[i][j] * scalar;
      }
    }
    return result;
  }

  constexpr bool operator==(const Matrix &other) const {
    return matrix == other.matrix;
  }

  // Operators as functions As Function
  template <size_t realColSize>
  Matrix<T, rowSize, realColSize> mult(Matrix<T, colSize, realColSize> &mat) {
    Matrix<T, rowSize, realColSize> result{};

    // Parallelize the matrix multiplication using OpenMP
#pragma omp parallel
    {
      size_t i, j, k;
#pragma omp for private(i, j, k)
      for (i = 0; i < rowSize; ++i) {
        for (j = 0; j < realColSize; ++j) {
          T sum = 0;
          for (k = 0; k < colSize; ++k) {
            sum += matrix[i][k] * mat[k][j];
          }
          result[i][j] = sum;
        }
      }
    }

    return result;
  }

private:
  std::vector<std::vector<T>> matrix;
};

// Default constructor
template <typename T, size_t rowSize, size_t colSize>
constexpr Matrix<T, rowSize, colSize>::Matrix() {
  using std::vector;

  matrix = vector<vector<T>>(rowSize, vector<T>(colSize));
}

// By Vector
template <typename T, size_t rowSize, size_t colSize>
constexpr Matrix<T, rowSize, colSize>::Matrix(std::vector<std::vector<T>> mat) {
  // Ensure that the input vector has the correct dimensions
  using std::vector;

  if (mat.size() != rowSize || (mat.size() > 0 && mat[0].size() != colSize)) {
    throw std::invalid_argument("Invalid matrix dimensions");
  }
  matrix = vector<vector<T>>(rowSize, vector<T>(colSize));

  // Copy the elements from the input vector to the matrix data member
  for (size_t i = 0; i < rowSize; ++i) {
    for (size_t j = 0; j < colSize; ++j) {
      matrix[i][j] = mat[i][j];
    }
  }
}

// Copy constructor
template <typename T, size_t rowSize, size_t colSize>
constexpr Matrix<T, rowSize, colSize>::Matrix(const Matrix &other) {
  matrix = other.matrix;
}

// Move constructor
template <typename T, size_t rowSize, size_t colSize>
constexpr Matrix<T, rowSize, colSize>::Matrix(Matrix &&other) noexcept {
  matrix = std::move(other.matrix);
}

// Copy assignment operator
template <typename T, size_t rowSize, size_t colSize>
constexpr Matrix<T, rowSize, colSize> &
Matrix<T, rowSize, colSize>::operator=(const Matrix &other) {

  if (this == &other) {
    return *this;
  }

  matrix = other.matrix;

  return *this;
}

// Move assignment operator
template <typename T, size_t rowSize, size_t colSize>
constexpr Matrix<T, rowSize, colSize> &
Matrix<T, rowSize, colSize>::operator=(Matrix &&other) noexcept {

  if (this == &other) {
    return *this;
  }

  matrix = std::move(other.matrix);

  return *this;
}

} // namespace erdo

#endif
