#include "logger/logger.h"

using namespace erdo;

// logger constructor
Logger::Logger(const Logger &other) {
  std::lock_guard<std::mutex> lock(other._mutex);
  loggerSeverity = other.loggerSeverity;
  outputStream = other.outputStream;
}

Logger::Logger(Logger &&other) {
  std::lock_guard<std::mutex> lock(other._mutex);
  loggerSeverity = other.loggerSeverity;
  outputStream = std::move(other.outputStream);
}

// Class Methods
void Logger::log(std::string stringToLog, LoggerSeverity severity) {

  std::lock_guard<std::mutex> lock(_mutex);

  if (severity < loggerSeverity) {
    return;
  }

  switch (severity) {
  case LoggerSeverity::DEBUG:
    (*outputStream) << loggerMessageTemplate.getDebugTemplate()(stringToLog)
                    << std::endl;
    break;
  case LoggerSeverity::INFO:
    (*outputStream) << loggerMessageTemplate.getInfoTemplate()(stringToLog)
                    << std::endl;
    break;
  case LoggerSeverity::WARNING:
    (*outputStream) << loggerMessageTemplate.getWarningTemplate()(stringToLog)
                    << std::endl;
    break;
  case LoggerSeverity::ERROR:
    (*outputStream) << loggerMessageTemplate.getErrorTemplate()(stringToLog)
                    << std::endl;
    break;

  default:
    break;
  }
}

// non-class functions
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
