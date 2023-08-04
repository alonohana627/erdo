#ifndef ERDO_COMPOUNDTYPETRAITS_H
#define ERDO_COMPOUNDTYPETRAITS_H

#include "metaprogramming/basic_type_traits.h"

namespace erdo {
template <typename T> struct CompoundAllIntegers {
  static const bool value = IsConstInt<T>::value || IsInt<T>::value ||
                            IsUnsignedInt<T>::value ||
                            IsConstUnsignedInt<T>::value;
};

template <typename T> struct CompoundAllLong {
  static const bool value =
      IsConstLong<T>::value || IsLong<T>::value || IsUnsignedLong<T>::value ||
      IsConstUnsignedLong<T>::value || IsLongLongInt<T>::value ||
      IsUnsignedLongLongInt<T>::value || IsConstLongLongInt<T>::value ||
      IsConstUnsignedLongLongInt<T>::value;
};

template <typename T> struct CompoundShort {
  static const bool value = IsShort<T>::value || IsConstShort<T>::value ||
                            IsConstUnsignedShort<T>::value ||
                            IsUnsignedShort<T>::value;
};

template <typename T> struct IsIntegral {
  static const bool value = CompoundAllIntegers<T>::value ||
                            CompoundAllLong<T>::value ||
                            CompoundShort<T>::value;
};

template <typename T> struct CompoundFloat {
  static const bool value = IsFloat<T>::value || IsConstFloat<T>::value ||
                            IsDouble<T>::value || IsConstDouble<T>::value ||
                            IsLongDouble<T>::value ||
                            IsConstLongDouble<T>::value;
};

template<typename T> struct IsNumber {
  static const bool value = IsIntegral<T>::value || CompoundFloat<T>::value;
};

} // namespace erdo

#endif