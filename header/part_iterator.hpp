_Pragma("once");
#include<filesystem/filesystem.hpp>
#include<string>
namespace fs = ghc::filesystem;
namespace HFormatter::NPartIterator{
    class PartIterator{
        private:
            fs::directory_iterator source_iterator_;
            fs::directory_iterator end_;
        public:
            PartIterator(const std::string&);
            virtual std::string getNextPart();
    };
}