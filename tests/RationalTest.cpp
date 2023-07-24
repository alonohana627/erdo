#include "erdo.h"
#include "gtest/gtest.h"

TEST(RationalTest, BasicTest) {
  erdo::Rational<int> rationalNum{1, 3};
  const std::string rationalAsString = rationalNum.toString();

  auto [numerator, denominator] = rationalNum.getRationalNumber();

  EXPECT_EQ(rationalAsString, "1/3");
  EXPECT_EQ(numerator, 1);
  EXPECT_EQ(denominator, 3);
}

TEST(RationalTest, SignConstructorTest) {
  erdo::Rational<int> firstRational{-1, -3};
  erdo::Rational<int> secondRational{1, -3};

  const std::string firstRationalAsString = firstRational.toString();
  const std::string secondRationalAsString = secondRational.toString();

  auto [firstNumerator, firstDenominator] = firstRational.getRationalNumber();
  auto [secondNumerator, secondDenominator] =
      secondRational.getRationalNumber();

  EXPECT_EQ(firstRationalAsString, "1/3");
  EXPECT_EQ(firstNumerator, 1);
  EXPECT_EQ(firstDenominator, 3);

  EXPECT_EQ(secondRationalAsString, "-1/3");
  EXPECT_EQ(secondNumerator, -1);
  EXPECT_EQ(secondDenominator, 3);
}

TEST(RationalTest, GCDConstructor) {
  erdo::Rational<int> firstRational{2, 6};
  erdo::Rational<int> secondRational{-2, -6};
  erdo::Rational<int> thirdRational{-2, 6};
  erdo::Rational<int> fourthRational{2, -6};
  erdo::Rational<int> fithRational{16, 4};

  const std::string firstRationalAsString = firstRational.toString();
  const std::string secondRationalAsString = secondRational.toString();
  const std::string thirdRationalAsString = thirdRational.toString();

  auto [firstNumerator, firstDenominator] = firstRational.getRationalNumber();
  auto [secondNumerator, secondDenominator] =
      secondRational.getRationalNumber();
  auto [thirdNumerator, thirdDenominator] = thirdRational.getRationalNumber();
  const auto thirdAsPair = std::make_pair(-1, 3);
  const auto forthAsPair = std::make_pair(4, 1);

  EXPECT_EQ(firstRationalAsString, "1/3");
  EXPECT_EQ(firstNumerator, 1);
  EXPECT_EQ(firstDenominator, 3);

  EXPECT_EQ(secondRationalAsString, "1/3");
  EXPECT_EQ(secondNumerator, 1);
  EXPECT_EQ(secondDenominator, 3);

  EXPECT_EQ(thirdRationalAsString, "-1/3");
  EXPECT_EQ(thirdNumerator, -1);
  EXPECT_EQ(thirdDenominator, 3);

  EXPECT_EQ(fourthRational.toString(), "-1/3");
  EXPECT_EQ(thirdAsPair, fourthRational.getRationalNumber());

  EXPECT_EQ(fithRational.toString(), "4/1");
  EXPECT_EQ(forthAsPair, fithRational.getRationalNumber());
}

TEST(RationalTest, ZeroDenominatorTest) {
  EXPECT_THROW(const erdo::Rational<int> firstRational(5, 0),
               std::invalid_argument);
}

TEST(RationalTest, NegateTest) {
  const erdo::Rational<int> firstRational{2, 3};
  const erdo::Rational<int> negatedRational = -firstRational;

  auto [rnumerator, rdenominator] = firstRational.getRationalNumber();
  auto [r1numerator, r1denominator] = negatedRational.getRationalNumber();

  EXPECT_EQ(rnumerator, 2);
  EXPECT_EQ(rdenominator, 3);
  EXPECT_EQ(r1numerator, -2);
  EXPECT_EQ(r1denominator, 3);
}

TEST(RationalTest, PlusPlusTest) {
  erdo::Rational<int> firstRational{1, 3};

  ++firstRational;
  auto [rnumerator, rdenominator] = firstRational.getRationalNumber();

  EXPECT_EQ(rnumerator, 4);
  EXPECT_EQ(rdenominator, 3);
}

TEST(RationalTest, AdditionOperator) {
  const erdo::Rational<int> firstRational(1, 2);
  const erdo::Rational<int> secondRational(1, 3);

  erdo::Rational<int> result = firstRational + secondRational;

  EXPECT_EQ(result.toString(), "5/6");
}

TEST(RationalTest, PlusAdditionOperator) {
  erdo::Rational<int> firstRational(1, 2);
  const erdo::Rational<int> secondRational(1, 3);

  firstRational += secondRational;

  EXPECT_EQ(firstRational.toString(), "5/6");
}

TEST(RationalTest, SubstructionEqualOperator) {
  erdo::Rational<int> firstRational(5, 6);
  const erdo::Rational<int> secondRational(3, 2);
  firstRational -= secondRational;

  EXPECT_EQ(firstRational, erdo::Rational<int>(-2, 3));
}

TEST(RationalTest, SubstructionOperator) {
  const erdo::Rational<int> firstRational(5, 6);
  const erdo::Rational<int> secondRational(3, 2);
  auto fourthRational = firstRational - secondRational;

  EXPECT_EQ(fourthRational, erdo::Rational<int>(-2, 3));
}

TEST(RationalTest, MultEqualOperator) {
  erdo::Rational<int> firstRational(5, 6);
  const erdo::Rational<int> secondRational(3, 2);
  firstRational *= secondRational;

  EXPECT_EQ(firstRational, erdo::Rational<int>(5, 4));
}

TEST(RationalTest, MultOperator) {
  const erdo::Rational<int> firstRational(5, 6);
  const erdo::Rational<int> secondRational(3, 2);
  auto fourthRational = firstRational * secondRational;

  EXPECT_EQ(fourthRational, erdo::Rational<int>(5, 4));
}

TEST(RationalTest, DivEqualOperator) {
  erdo::Rational<int> firstRational(5, 6);
  const erdo::Rational<int> secondRational(3, 2);
  firstRational /= secondRational;

  EXPECT_EQ(firstRational, erdo::Rational<int>(5, 9));
}

TEST(RationalTest, DivOperator) {
  const erdo::Rational<int> firstRational(5, 6);
  const erdo::Rational<int> secondRational(3, 2);
  auto thirdRational = firstRational / secondRational;

  EXPECT_EQ(thirdRational, erdo::Rational<int>(5, 9));
}

TEST(RationalTest, EqualityOperator) {
  const erdo::Rational<int> firstRational(1, 2);
  const erdo::Rational<int> secondRational(2, 4);
  const erdo::Rational<int> thirdRational(1, 2);

  EXPECT_EQ(firstRational, thirdRational);
  EXPECT_EQ(firstRational, thirdRational);
  EXPECT_EQ(firstRational, secondRational);
}

TEST(RationalTest, NotEqualityOperator) {
  const erdo::Rational<int> firstRational(1, 2);
  const erdo::Rational<int> secondRational(1, 4);
  EXPECT_NE(firstRational, secondRational);
}

TEST(RationalTest, InverseTest) {
  erdo::Rational<int> rationalNum(1, 2);
  rationalNum.inverse();
  EXPECT_EQ(rationalNum, erdo::Rational<int>(2, 1));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
