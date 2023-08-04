#ifndef ERDO_LOGGER_H
#define ERDO_LOGGER_H

#include "logger/message_templates.h"
#include "logger/severity.h"

#include <iostream>
#include <memory>
#include <mutex>
#include <string>

namespace erdo {
class Logger {

public:
  // Default constructor
  Logger()
      : loggerSeverity(LoggerSeverity::INFO),
        outputStream(std::make_shared<std::ostream>(std::cout.rdbuf())) {}

  // Destructor
  ~Logger() = default;

  // Copy constructor
  Logger(const Logger &other);

  // Move constructor
  Logger(Logger &&other);

  // Copy assignment operator
  Logger &operator=(const Logger &other) {
    if (this == &other)
      return *this;
    std::lock(_mutex, other._mutex);
    std::lock_guard<std::mutex> lockThis(_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lockOther(other._mutex, std::adopt_lock);
    loggerSeverity = other.loggerSeverity;
    outputStream = other.outputStream;
    return *this;
  }

  // Move assignment operator
  Logger &operator=(Logger &&other) noexcept {
    if (this == &other)
      return *this;
    std::lock(_mutex, other._mutex);
    std::lock_guard<std::mutex> lockThis(_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lockOther(other._mutex, std::adopt_lock);
    loggerSeverity = other.loggerSeverity;
    outputStream = std::move(other.outputStream);
    return *this;
  }

  // Setting severity
  void setSeverity(LoggerSeverity LoggerSeverity) {
    std::lock_guard<std::mutex> lock(_mutex);
    this->loggerSeverity = LoggerSeverity;
  }

  // Templates
  void setDebugTemplate(stringToStringCallback callback) {
    std::lock_guard<std::mutex> lock(this->_mutex);
    this->loggerMessageTemplate.setDebugTemplate(callback);
  }

  void setInfoTemplate(stringToStringCallback callback) {
    std::lock_guard<std::mutex> lock(this->_mutex);
    this->loggerMessageTemplate.setInfoTemplate(callback);
  }

  void setWarningTemplate(stringToStringCallback callback) {
    std::lock_guard<std::mutex> lock(this->_mutex);
    this->loggerMessageTemplate.setWarningTemplate(callback);
  }

  void setErrorTemplate(stringToStringCallback callback) {
    std::lock_guard<std::mutex> lock(this->_mutex);
    this->loggerMessageTemplate.setErrorTemplate(callback);
  }

  void setOutputStream(std::shared_ptr<std::ostream> newOutputStream) {
    std::lock_guard<std::mutex> lock(_mutex);
    outputStream = newOutputStream;
  }

  void log(std::string stringToLog, LoggerSeverity severity);

private:
  mutable LoggerSeverity loggerSeverity;
  mutable std::mutex _mutex;
  std::shared_ptr<std::ostream> outputStream;
  LoggerMessageTemplate loggerMessageTemplate;
};

static Logger logger{};

// Severity
void setSeverity(LoggerSeverity LoggerSeverity);

// Templates
void setDebugTemplate(stringToStringCallback callback);

void setInfoTemplate(stringToStringCallback callback);

void setWarningTemplate(stringToStringCallback callback);

void setErrorTemplate(stringToStringCallback callback);

void log(std::string stringToLog, LoggerSeverity severity);

} // namespace erdo

#endif