#include "erdo.h"
#include <memory>
#include <thread>


int main() noexcept {
  erdo::setInfoTemplate([=](const std::string &infoForTemplate) {
    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    return "nadav " +  std::to_string(t_c);
  });
  erdo::log("Wassup Man", erdo::LoggerSeverity::INFO);
  erdo::log("Wassup Man2", erdo::LoggerSeverity::ERROR);
  erdo::log("Wassup Man2", erdo::LoggerSeverity::ERROR);

  std::vector<int, erdo::ErdoCator<int>> vec{1,2,3};

  std::cout << vec[0] << std::endl;

  auto vec2 = std::move(vec);

  vec2[0] = 10;

  std::cout << vec2[0] << std::endl;

  return 0;
}