_Pragma("once");
#include<part_info.hpp>
#include<filesystem/filesystem.hpp>
#include<string>
namespace fs = ghc::filesystem;
using HFormatter::NPartInfo::PartInfo;
namespace HFormatter::NFileOperator{
    class FileOperator{
        protected:
            fs::path new_path_;
        public:
            virtual void operateItem(PartInfo&);
    };
}