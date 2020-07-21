_Pragma("once");
#include<spdlog/spdlog.h>
#include<memory>
namespace HFormatter::NLogger{
    class Logger{
        protected:
            std::shared_ptr<spdlog::logger> logger_;
            Logger();
        public:
            std::shared_ptr<spdlog::logger>& operator()();
    };
}