#ifndef ERDO_MESSAGE_TEMPLATE_H
#define ERDO_MESSAGE_TEMPLATE_H

#include "logger/severity.h"
#include <functional>
#include <memory>
#include <mutex>
#include <string>

namespace erdo {

constexpr std::string defaultDebugTemplate(const std::string &statement) {
  return "[DEBUG] " + statement;
}

constexpr std::string defaultInfoTemplate(const std::string &statement) {
  return "[INFO] " + statement;
}

constexpr std::string defaultWarnTemplate(const std::string &statement) {
  return "[WARNING] " + statement;
}

constexpr std::string defaultErrorTemplate(const std::string &statement) {
  return "[ERROR] " + statement;
}

using stringToStringCallback = std::function<std::string(const std::string &)>;

class LoggerMessageTemplate {
public:
  // Constructors
  LoggerMessageTemplate()
      : debugTemplate(defaultDebugTemplate), infoTemplate(defaultInfoTemplate),
        warningTemplate(defaultWarnTemplate),
        errorTemplate(defaultErrorTemplate) {}

  LoggerMessageTemplate(stringToStringCallback debugTemp,
                        stringToStringCallback infoTemp,
                        stringToStringCallback warnTemp,
                        stringToStringCallback errorTemp)
      : debugTemplate(debugTemp), infoTemplate(infoTemp),
        warningTemplate(warnTemp), errorTemplate(errorTemp) {}

  // Copy constructor
  LoggerMessageTemplate(const LoggerMessageTemplate &other)
      : debugTemplate(other.debugTemplate), infoTemplate(other.infoTemplate),
        warningTemplate(other.warningTemplate),
        errorTemplate(other.errorTemplate) {}

  // Move constructor
  LoggerMessageTemplate(LoggerMessageTemplate &&other) noexcept
      : debugTemplate(std::move(other.debugTemplate)),
        infoTemplate(std::move(other.infoTemplate)),
        warningTemplate(std::move(other.warningTemplate)),
        errorTemplate(std::move(other.errorTemplate)) {}

  // Copy assignment operator
  LoggerMessageTemplate &operator=(const LoggerMessageTemplate &other) {
    if (this != &other) {
      debugTemplate = other.debugTemplate;
      infoTemplate = other.infoTemplate;
      warningTemplate = other.warningTemplate;
      errorTemplate = other.errorTemplate;
    }
    return *this;
  }

  // Move assignment operator
  LoggerMessageTemplate &operator=(LoggerMessageTemplate &&other) noexcept {
    if (this != &other) {
      debugTemplate = std::move(other.debugTemplate);
      infoTemplate = std::move(other.infoTemplate);
      warningTemplate = std::move(other.warningTemplate);
      errorTemplate = std::move(other.errorTemplate);
    }
    return *this;
  }

  // Destructor
  ~LoggerMessageTemplate() = default;

  // Getters
  stringToStringCallback getDebugTemplate() const { return debugTemplate; }
  stringToStringCallback getInfoTemplate() const { return infoTemplate; }
  stringToStringCallback getWarningTemplate() const { return warningTemplate; }
  stringToStringCallback getErrorTemplate() const { return errorTemplate; }

  // Setters
  void setDebugTemplate(stringToStringCallback callback) {
    debugTemplate = callback;
  }

  void setInfoTemplate(stringToStringCallback callback) {
    infoTemplate = callback;
  }

  void setWarningTemplate(stringToStringCallback callback) {
    warningTemplate = callback;
  }

  void setErrorTemplate(stringToStringCallback callback) {
    errorTemplate = callback;
  }

private:
  stringToStringCallback debugTemplate;
  stringToStringCallback infoTemplate;
  stringToStringCallback warningTemplate;
  stringToStringCallback errorTemplate;
};

} // namespace erdo

#endif