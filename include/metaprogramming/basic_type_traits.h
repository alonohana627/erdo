#include <complex>

#ifndef ERDO_BASICTYPETRAITS_H
#define ERDO_BASICTYPETRAITS_H

#define BASIC_TYPE_TRAIT(Type, StructName)                                     \
  template <typename T> struct StructName {                                    \
    static const bool value = false;                                           \
  };                                                                           \
  template <> struct StructName<Type> {                                        \
    static const bool value = true;                                            \
  };

namespace erdo {

// Void
BASIC_TYPE_TRAIT(void, IsVoid)
BASIC_TYPE_TRAIT(const void, IsConstVoid)

// Character
BASIC_TYPE_TRAIT(char, IsChar)
BASIC_TYPE_TRAIT(const char, IsConstChar)

// Unsigned Character
BASIC_TYPE_TRAIT(unsigned char, IsUnsignedChar)
BASIC_TYPE_TRAIT(const unsigned char, IsConstUnsignedChar)

// Short
BASIC_TYPE_TRAIT(short, IsShort)
BASIC_TYPE_TRAIT(const short, IsConstShort)

// unsigned Short
BASIC_TYPE_TRAIT(unsigned short, IsUnsignedShort)
BASIC_TYPE_TRAIT(const unsigned short, IsConstUnsignedShort)

// int
BASIC_TYPE_TRAIT(int, IsInt)
BASIC_TYPE_TRAIT(const int, IsConstInt)

// Unsigned int
BASIC_TYPE_TRAIT(unsigned int, IsUnsignedInt)
BASIC_TYPE_TRAIT(const unsigned int, IsConstUnsignedInt)

// long
BASIC_TYPE_TRAIT(long int, IsLong)
BASIC_TYPE_TRAIT(const long int, IsConstLong)

// Unsigned long
BASIC_TYPE_TRAIT(unsigned long int, IsUnsignedLong)
BASIC_TYPE_TRAIT(const unsigned long int, IsConstUnsignedLong)

// long long
BASIC_TYPE_TRAIT(long long int, IsLongLongInt)
BASIC_TYPE_TRAIT(const long long int, IsConstLongLongInt)

// Unsigned long long
BASIC_TYPE_TRAIT(unsigned long long int, IsUnsignedLongLongInt)
BASIC_TYPE_TRAIT(const unsigned long long int, IsConstUnsignedLongLongInt)

// Double
BASIC_TYPE_TRAIT(double, IsDouble)
BASIC_TYPE_TRAIT(const double, IsConstDouble)

BASIC_TYPE_TRAIT(long double, IsLongDouble)
BASIC_TYPE_TRAIT(const long double, IsConstLongDouble)

BASIC_TYPE_TRAIT(float, IsFloat)
BASIC_TYPE_TRAIT(const float, IsConstFloat)

} // namespace erdo
#endif