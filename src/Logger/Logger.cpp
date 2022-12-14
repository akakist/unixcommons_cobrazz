#include <Logger/Logger.hpp>


namespace Logging
{
  const size_t StreamLogger::DEFAULT_BUFFER_SIZE;
  StreamLogger::ThreadBuffer StreamLogger::thread_buffer_;


  //
  // SimpleLoggerHolder class
  //

  SimpleLoggerHolder::SimpleLoggerHolder(Logger* logger) throw ()
    : logger_(ReferenceCounting::add_ref(logger))
  {
  }

  SimpleLoggerHolder::~SimpleLoggerHolder() throw ()
  {
  }

  unsigned long
  SimpleLoggerHolder::log_level() throw ()
  {
    return logger_->log_level();
  }

  void
  SimpleLoggerHolder::log_level(unsigned long value) throw ()
  {
    logger_->log_level(value);
  }

  bool
  SimpleLoggerHolder::log(const String::SubString& text,
    unsigned long severity, const char* aspect, const char* code) throw ()
  {
    return logger_->log(text, severity, aspect, code);
  }


  //
  // LoggerHolder class
  //

  LoggerHolder::LoggerHolder(Logger* logger) throw ()
    : SimpleLoggerHolder(logger),
      log_level_(logger ? logger->log_level() : 0)
  {
  }

  LoggerHolder::~LoggerHolder() throw ()
  {
  }

  void
  LoggerHolder::logger(Logger* new_logger) throw ()
  {
    QLogger_var nl(ReferenceCounting::add_ref(new_logger));
    {
      Sync::PosixSpinGuard guard(mutex_);
      std::swap(logger_, nl);
      log_level_ = logger_ ? logger_->log_level() : 0;
    }
  }

  unsigned long
  LoggerHolder::log_level() throw ()
  {
    return log_level_;
  }

  void
  LoggerHolder::log_level(unsigned long value) throw ()
  {
    Sync::PosixSpinGuard guard(mutex_);
    if (has_logger_())
    {
      logger_->log_level(value);
      log_level_ = value;
    }
  }

  bool
  LoggerHolder::log(const String::SubString& text, unsigned long severity,
    const char* aspect, const char* code) throw ()
  {
    if (severity > static_cast<unsigned long>(log_level_))
    {
      return true;
    }

    QLogger_var logger;
    {
      Sync::PosixSpinGuard guard(mutex_);
      logger = logger_;
    }
    return logger ? logger->log(text, severity, aspect, code) : false;
  }


  //
  // LoggerDefaultHolder class
  //

  LoggerDefaultHolder::LoggerDefaultHolder(Logger* logger,
    const char* aspect, const char* code) /*throw (eh::Exception)*/
    : LoggerHolder(logger), aspect_(aspect ? aspect : ""),
      code_(code ? code : "")
  {
  }

  bool
  LoggerDefaultHolder::log(const String::SubString& text,
    unsigned long severity, const char* aspect, const char* code) throw ()
  {
    return LoggerHolder::log(text, severity,
      aspect ? aspect : aspect_.c_str(), code ? code : code_.c_str());
  }
}
