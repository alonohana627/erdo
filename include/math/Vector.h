#ifndef ERDO_VECTOR_H
#define ERDO_VECTOR_H

#include "math/Rational.h"
#include <algorithm>
#include <concepts>
#include <mutex>
#include <omp_llvm.h>
#include <vector>

namespace erdo {

template <typename T>
concept VectorAligable =
    std::integral<T> || std::floating_point<T> || RationalConcept<T>;

template <typename T>
  requires VectorAligable<T>
class Vector {
public:
  // Constructor
  constexpr Vector() : _vec(), _mutex() {}
  constexpr explicit Vector(const std::vector<T> &vector)  : _vec(vector) {}

  // Destructor
  ~Vector() = default;

  // Copy constructor
  Vector(const Vector &other) {
    std::lock_guard<std::mutex> lock(_mutex);
    _vec = other._vec;
  }

  // Copy assignment operator
  Vector &operator=(const Vector &other) {
    if (this != &other) {
      std::lock_guard<std::mutex> lock(_mutex);
      _vec = other._vec;
    }
    return *this;
  }

  // Move constructor
  Vector(Vector &&other) noexcept {
    std::lock_guard<std::mutex> lock(_mutex);
    _vec = std::move(other._vec);
  }

  // Move assignment operator
  Vector &operator=(Vector &&other) noexcept {
    if (this != &other) {
      std::lock_guard<std::mutex> lock(_mutex);
      _vec = std::move(other._vec);
    }
    return *this;
  }

  // [] operator for non-const objects with bounds check
  T &operator[](size_t index) {
    std::lock_guard<std::mutex> lock(_mutex);
    if (index >= _vec.size()) {
      throw std::out_of_range("Index out of range.");
    }
    return _vec[index];
  }

  // [] operator for const objects with bounds check
  const T &operator[](size_t index) const {
    std::lock_guard<std::mutex> lock(_mutex);
    if (index >= _vec.size()) {
      throw std::out_of_range("Index out of range.");
    }
    return _vec[index];
  }

  constexpr T dot(Vector<T> other, T summit = 0) const {
    if (other.getLength() != this->getLength()) {
      throw std::invalid_argument("The length of the vectors are NOT equal!!");
    }
    T sum = summit;

#pragma omp parallel for 
    for (size_t i = 0; i < this->getLength(); i++) {
      sum += this->_vec[i] * other[i];
    }

    return sum;
  }

  constexpr size_t getLength() const { return _vec.size(); }

private:
  std::vector<T> _vec;
  mutable std::mutex _mutex;
};

} // namespace erdo

#endif