#include "erdo.h"
#include "metaprogramming/basic_type_traits.h"
#include <gtest/gtest.h>

TEST(BasicTypeTraits, IsVoid){
  constexpr bool notVoid = erdo::IsVoid<int>::value;
  constexpr bool yesVoid = erdo::IsVoid<void>::value;
  
  ASSERT_FALSE(notVoid);
  ASSERT_TRUE(yesVoid);
}

int main(int argc, char *argv[]) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}