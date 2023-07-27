#include "erdo.h"
#include <chrono>
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

  erdo::logger.~Logger();
  
  erdo::log("Wassup Man2", erdo::LoggerSeverity::ERROR);
  return 0;
}