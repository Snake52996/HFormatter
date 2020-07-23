#include<logger.hpp>
using std::shared_ptr;
using HFormatter::NLogger::Logger;
Logger::Logger():logger_(nullptr){};
shared_ptr<spdlog::logger>& Logger::operator->(){return logger_;}