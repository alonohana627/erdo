#include "math/Rational.h"
#include <iostream>
#include <memory>


using ErdoRational = erdo::Rational<int>;
using UniqueRational = std::unique_ptr<ErdoRational>;

UniqueRational increaseRational(UniqueRational rat) {
  rat->plusplus();
  return rat;
}

int main() noexcept {
  erdo::Rational<int> r{1, 2};

  {
    auto rationalAsUnique = std::make_unique<ErdoRational>(r);
    rationalAsUnique = increaseRational(std::move(rationalAsUnique));
    std::cout << rationalAsUnique->toString() << std::endl;
  }

  r.inverse();

  std::cout << r.toString() << std::endl;
  return 0;
}