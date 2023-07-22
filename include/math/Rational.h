#ifndef ERDO_RATIONAL_H
#define ERDO_RATIONAL_H

#include "erdo.h"
#include "math/Arithmetic.h"
#include <concepts>
#include <stdexcept>
#include <string>

namespace erdo {

template <std::integral T> class Rational {
public:
  constexpr Rational(const T &_numerator, const T &_denominator)
      : _numerator(_numerator), _denominator(_denominator) {
    if (_denominator == 0) {
      throw std::invalid_argument("Denominator cannot be zero.");
    }

    T devider = gcd(abs(this->_numerator), abs(this->_denominator));
    this->_numerator /= devider;
    this->_denominator /= devider;

    if (_denominator < 0) {
      this->_denominator = this->_denominator * (-1);
      this->_numerator = this->_numerator * (-1);
    }
  }

  constexpr Rational(Rational &&r) noexcept = default;

  constexpr Rational(const Rational &r) = default;

  ~Rational() = default;

  constexpr Rational &operator=(const Rational &other) = default;

  constexpr Rational &operator=(Rational &&other) noexcept = default;

  constexpr std::string toString() {
    return std::to_string(_numerator) + '/' + std::to_string(_denominator);
  }

  // Operators

  inline constexpr Rational<T> &operator+=(const Rational<T> &rhs) noexcept;
  inline constexpr Rational<T> &operator-=(const Rational<T> &rhs) noexcept;
  inline constexpr Rational<T> &operator*=(const Rational<T> &rhs) noexcept;
  inline constexpr Rational<T> &operator/=(const Rational<T> &rhs) noexcept;

  inline constexpr bool operator==(const Rational<T> &rhs) const;
  inline constexpr bool operator!=(const Rational<T> &rhs) const;

  // Not allowing change directly
private:
  T _numerator;
  T _denominator;

  // Inside:
public:
  inline constexpr void negate() {
    _numerator = _numerator * (-1);
    // std::abs(_denominator);
  }

  inline constexpr void plusplus() { _numerator = _numerator + _denominator; }

  inline constexpr std::pair<T, T> getRationalNumber() const {
    return std::pair<T, T>(_numerator, _denominator);
  }

  inline constexpr void gcdSqueeze() {
    T devider = gcd(_numerator, _denominator);
    _numerator /= devider;
    _denominator /= devider;
  }

  inline constexpr void inverse() { std::swap(_numerator, _denominator); }
};

template <class T>
concept RationalConcept = std::is_base_of<Rational<int>, T>::value ||
                          std::is_base_of<Rational<long int>, T>::value ||
                          std::is_base_of<Rational<long long int>, T>::value;

// Operators
template <std::integral T>
inline constexpr Rational<T> &operator++(Rational<T> &r) noexcept {
  r.plusplus();
  return r;
}

template <std::integral T>
inline constexpr Rational<T> operator-(const Rational<T> &r) noexcept {
  Rational<T> r1 = r;
  r1.negate();
  return r1;
}

template <std::integral T>
inline constexpr Rational<T> operator+(const Rational<T> &lhs,
                                       const Rational<T> &rhs) {
  Rational<T> rational{lhs};
  rational += rhs;

  return rational;
}

template <std::integral T>
inline constexpr Rational<T> operator-(const Rational<T> &lhs,
                                       const Rational<T> &rhs) {
  Rational<T> rational{lhs};
  rational -= rhs;

  return rational;
}

template <std::integral T>
inline constexpr Rational<T> operator*(const Rational<T> &lhs,
                                       const Rational<T> &rhs) {
  Rational<T> rational{lhs};
  rational *= rhs;

  return rational;
}

template <std::integral T>
inline constexpr Rational<T> operator/(const Rational<T> &lhs,
                                       const Rational<T> &rhs) {
  Rational<T> rational{lhs};
  rational /= rhs;

  return rational;
}

template <std::integral T>
inline constexpr Rational<T> &
Rational<T>::operator+=(const Rational<T> &rhs) noexcept {
  _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
  _denominator = _denominator * rhs._denominator;

  this->gcdSqueeze();

  return *this;
}

template <std::integral T>
inline constexpr Rational<T> &
Rational<T>::operator-=(const Rational<T> &rhs) noexcept {
  if (*this == rhs) {
    this->_numerator = 0;
    this->_denominator = 1;
    return *this;
  }

  Rational<T> newRational{rhs};
  newRational.negate();

  return *this += newRational;
}

template <std::integral T>
inline constexpr Rational<T> &
Rational<T>::operator*=(const Rational<T> &rhs) noexcept {
  this->_numerator *= rhs._numerator;
  this->_denominator *= rhs._denominator;
  this->gcdSqueeze();

  return *this;
}

template <std::integral T>
inline constexpr Rational<T> &
Rational<T>::operator/=(const Rational<T> &rhs) noexcept {
  Rational<T> rhsCopy{rhs};
  rhsCopy.inverse();

  return *this *= rhsCopy;
}

template <std::integral T>
inline constexpr bool Rational<T>::operator==(const Rational<T> &rhs) const {
  auto [a, b] = rhs.getRationalNumber();
  return this->_denominator == b && this->_numerator == a;
}

template <std::integral T>
inline constexpr bool Rational<T>::operator!=(const Rational<T> &rhs) const {
  auto [a, b] = rhs.getRationalNumber();
  return this->_denominator != b || this->_numerator != a;
}

} // namespace erdo

#endif