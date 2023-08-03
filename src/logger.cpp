#include "logger/logger.h"

void erdo::log(std::string stringToLog, erdo::LoggerSeverity severity) {
  erdo::logger.log(std::move(stringToLog), severity);
}

void erdo::setSeverity(erdo::LoggerSeverity LoggerSeverity) {
  erdo::logger.setSeverity(LoggerSeverity);
}

void erdo::setDebugTemplate(erdo::stringToStringCallback callback) {
  erdo::logger.setDebugTemplate(std::move(callback));
}

void erdo::setInfoTemplate(erdo::stringToStringCallback callback) {
  erdo::logger.setInfoTemplate(std::move(callback));
}

void erdo::setWarningTemplate(erdo::stringToStringCallback callback) {
  erdo::logger.setWarningTemplate(std::move(callback));
}

void erdo::setErrorTemplate(erdo::stringToStringCallback callback) {
  erdo::logger.setErrorTemplate(std::move(callback));
}
