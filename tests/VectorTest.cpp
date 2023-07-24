#include "erdo.h"
#include <gtest/gtest.h>
#include <omp_llvm.h>

TEST(VectorTest, BasicTest) {
  using erdo::Rational;

  const std::vector<Rational<int>> veci{Rational<int>(1, 2),
                                        Rational<int>(2, 3)};
  erdo::Vector<Rational<int>> vec(veci);
  vec[1] = veci[0];

  EXPECT_EQ(vec[0], erdo::Rational<int>(1, 2));
  EXPECT_EQ(vec[1], erdo::Rational<int>(1, 2));
}

TEST(VectorTest, DotProduct) {
  using erdo::Vector;
  long long int num = 0L;

  std::vector<long long int> vec = std::vector<long long int>(10000);
  std::generate_n(vec.begin(), 10000, [&](){
    return num++;
  });

  const Vector<long long int> vec1{vec};
  const Vector<long long int> vec2{vec};

  const auto dotResult = vec1.dot(vec2);

  EXPECT_EQ(dotResult, 333283335000L);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
