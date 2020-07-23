_Pragma("once");
#include<filesystem/filesystem.hpp>
#include<string>
namespace fs = ghc::filesystem;
namespace HFormatter::NPathCompleter{
    class PathCompleter{
        private:
            fs::path base_;
        public:
            std::string getBase()const;
            void setBase(const std::string&);
            virtual void operator()(std::string&);
    };
}