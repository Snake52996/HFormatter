_Pragma("once");
#include<spdlog/fmt/ostr.h>
#include<spdlog/spdlog.h>
#include<memory>
namespace HFormatter::NLogger{
	extern std::shared_ptr<spdlog::logger> logger;
}