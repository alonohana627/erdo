#ifndef ERDO_ARITHMETIC_H
#define ERDO_ARITHMETIC_H

#include <concepts>

namespace erdo {
template <std::integral T> constexpr T gcd(T a, T b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

template <std::integral T> constexpr T abs(T a) { return a < 0 ? -a : a; }
} // namespace erdo
#endif