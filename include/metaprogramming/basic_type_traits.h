#ifndef ERDO_BASICTYPETRAITS_H
#define ERDO_BASICTYPETRAITS_H

namespace erdo {

template <typename T> struct IsVoid {
  static const bool value = false;
};

template <> struct IsVoid<void> {
  static const bool value = true;
};

// Integer
template <typename T> struct IsInt {
  static const bool value = false;
};

template <> struct IsInt<int> {
  static const bool value = true;
};

// Long
template <typename T> struct IsLong {
  static const bool value = false;
};

template <> struct IsLong<long> {
  static const bool value = true;
};

// IsIntegral
template <typename T> struct IsIntegral {
  static const bool value = IsInt<T>::value || IsLong<T>::value;
};

}
#endif