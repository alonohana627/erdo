#include "metaprogramming/basic_type_traits.h"
#include <gtest/gtest.h>

TEST(BasicTypeTraits, IsVoid) {
  constexpr bool notVoid = erdo::IsVoid<int>::value;
  constexpr bool yesVoid = erdo::IsVoid<void>::value;

  ASSERT_FALSE(notVoid);
  ASSERT_TRUE(yesVoid);
}

TEST(BasicTypeTraits, IsConstVoid) {
  constexpr bool notVoid = erdo::IsConstVoid<int>::value;
  constexpr bool yesVoid = erdo::IsConstVoid<const void>::value;

  ASSERT_FALSE(notVoid);
  ASSERT_TRUE(yesVoid);
}
TEST(BasicTypeTraits, IsInt) {
  constexpr bool notInt = erdo::IsInt<double>::value;
  constexpr bool yesInt = erdo::IsInt<int>::value;

  ASSERT_FALSE(notInt);
  ASSERT_TRUE(yesInt);
}

TEST(BasicTypeTraits, IsConstInt) {
  constexpr bool notConstInt = erdo::IsConstInt<int>::value;
  constexpr bool yesConstInt = erdo::IsConstInt<const int>::value;

  ASSERT_FALSE(notConstInt);
  ASSERT_TRUE(yesConstInt);
}

TEST(BasicTypeTraits, IsLong) {
  constexpr bool notLong = erdo::IsLong<int>::value;
  constexpr bool yesLong = erdo::IsLong<long>::value;

  ASSERT_FALSE(notLong);
  ASSERT_TRUE(yesLong);
}

TEST(BasicTypeTraits, IsConstLong) {
  constexpr bool notConstLong = erdo::IsConstLong<long>::value;
  constexpr bool yesConstLong = erdo::IsConstLong<const long>::value;

  ASSERT_FALSE(notConstLong);
  ASSERT_TRUE(yesConstLong);
}

TEST(BasicTypeTraits, IsShort) {
  constexpr bool notShort = erdo::IsShort<int>::value;
  constexpr bool yesShort = erdo::IsShort<short>::value;

  ASSERT_FALSE(notShort);
  ASSERT_TRUE(yesShort);
}

TEST(BasicTypeTraits, IsConstShort) {
  constexpr bool notConstShort = erdo::IsConstShort<short>::value;
  constexpr bool yesConstShort = erdo::IsConstShort<const short>::value;

  ASSERT_FALSE(notConstShort);
  ASSERT_TRUE(yesConstShort);
}

TEST(BasicTypeTraits, IsChar) {
  constexpr bool notChar = erdo::IsChar<int>::value;
  constexpr bool yesChar = erdo::IsChar<char>::value;

  ASSERT_FALSE(notChar);
  ASSERT_TRUE(yesChar);
}

TEST(BasicTypeTraits, IsConstChar) {
  constexpr bool notConstChar = erdo::IsConstChar<char>::value;
  constexpr bool yesConstChar = erdo::IsConstChar<const char>::value;

  ASSERT_FALSE(notConstChar);
  ASSERT_TRUE(yesConstChar);
}

TEST(BasicTypeTraits, IsUnsignedInt) {
  constexpr bool notUnsignedInt = erdo::IsUnsignedInt<int>::value;
  constexpr bool yesUnsignedInt = erdo::IsUnsignedInt<unsigned int>::value;

  ASSERT_FALSE(notUnsignedInt);
  ASSERT_TRUE(yesUnsignedInt);
}

TEST(BasicTypeTraits, IsConstUnsignedInt) {
  constexpr bool notConstUnsignedInt = erdo::IsConstUnsignedInt<int>::value;
  constexpr bool yesConstUnsignedInt = erdo::IsConstUnsignedInt<const unsigned int>::value;

  ASSERT_FALSE(notConstUnsignedInt);
  ASSERT_TRUE(yesConstUnsignedInt);
}

TEST(BasicTypeTraits, IsUnsignedLong) {
  constexpr bool notUnsignedLong = erdo::IsUnsignedLong<long>::value;
  constexpr bool yesUnsignedLong = erdo::IsUnsignedLong<unsigned long>::value;

  ASSERT_FALSE(notUnsignedLong);
  ASSERT_TRUE(yesUnsignedLong);
}

TEST(BasicTypeTraits, IsConstUnsignedLong) {
  constexpr bool notConstUnsignedLong = erdo::IsConstUnsignedLong<long>::value;
  constexpr bool yesConstUnsignedLong = erdo::IsConstUnsignedLong<const unsigned long>::value;

  ASSERT_FALSE(notConstUnsignedLong);
  ASSERT_TRUE(yesConstUnsignedLong);
}

TEST(BasicTypeTraits, IsUnsignedShort) {
  constexpr bool notUnsignedShort = erdo::IsUnsignedShort<short>::value;
  constexpr bool yesUnsignedShort = erdo::IsUnsignedShort<unsigned short>::value;

  ASSERT_FALSE(notUnsignedShort);
  ASSERT_TRUE(yesUnsignedShort);
}

TEST(BasicTypeTraits, IsConstUnsignedShort) {
  constexpr bool notConstUnsignedShort = erdo::IsConstUnsignedShort<short>::value;
  constexpr bool yesConstUnsignedShort = erdo::IsConstUnsignedShort<const unsigned short>::value;

  ASSERT_FALSE(notConstUnsignedShort);
  ASSERT_TRUE(yesConstUnsignedShort);
}

TEST(BasicTypeTraits, IsUnsignedChar) {
  constexpr bool notUnsignedChar = erdo::IsUnsignedChar<char>::value;
  constexpr bool yesUnsignedChar = erdo::IsUnsignedChar<unsigned char>::value;

  ASSERT_FALSE(notUnsignedChar);
  ASSERT_TRUE(yesUnsignedChar);
}

TEST(BasicTypeTraits, IsConstUnsignedChar) {
  constexpr bool notConstUnsignedChar = erdo::IsConstUnsignedChar<char>::value;
  constexpr bool yesConstUnsignedChar = erdo::IsConstUnsignedChar<const unsigned char>::value;

  ASSERT_FALSE(notConstUnsignedChar);
  ASSERT_TRUE(yesConstUnsignedChar);
}

TEST(BasicTypeTraits, IsDouble) {
  constexpr bool notDouble = erdo::IsDouble<int>::value;
  constexpr bool yesDouble = erdo::IsDouble<double>::value;

  ASSERT_FALSE(notDouble);
  ASSERT_TRUE(yesDouble);
}

TEST(BasicTypeTraits, IsConstDouble) {
  constexpr bool notConstDouble = erdo::IsConstDouble<int>::value;
  constexpr bool yesConstDouble = erdo::IsConstDouble<const double>::value;

  ASSERT_FALSE(notConstDouble);
  ASSERT_TRUE(yesConstDouble);
}

TEST(BasicTypeTraits, IsFloat) {
  constexpr bool notFloat = erdo::IsFloat<double>::value;
  constexpr bool yesFloat = erdo::IsFloat<float>::value;

  ASSERT_FALSE(notFloat);
  ASSERT_TRUE(yesFloat);
}

TEST(BasicTypeTraits, IsConstFloat) {
  constexpr bool notConstFloat = erdo::IsConstFloat<double>::value;
  constexpr bool yesConstFloat = erdo::IsConstFloat<const float>::value;

  ASSERT_FALSE(notConstFloat);
  ASSERT_TRUE(yesConstFloat);
}

TEST(BasicTypeTraits, IsLongDouble) {
  constexpr bool notLongDouble = erdo::IsLongDouble<float>::value;
  constexpr bool yesLongDouble = erdo::IsLongDouble<long double>::value;

  ASSERT_FALSE(notLongDouble);
  ASSERT_TRUE(yesLongDouble);
}

TEST(BasicTypeTraits, IsConstLongDouble) {
  constexpr bool notConstLongDouble = erdo::IsConstLongDouble<float>::value;
  constexpr bool yesConstLongDouble = erdo::IsConstLongDouble<const long double>::value;

  ASSERT_FALSE(notConstLongDouble);
  ASSERT_TRUE(yesConstLongDouble);
}


int main(int argc, char *argv[]) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}