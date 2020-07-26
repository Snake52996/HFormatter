#include<console_logger.hpp>
#include<spdlog/sinks/stdout_color_sinks.h>
using HFormatter::NLogger::ConsoleLogger;
ConsoleLogger::ConsoleLogger(){
    logger_ = spdlog::stdout_color_st("console logger");
    logger_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
}