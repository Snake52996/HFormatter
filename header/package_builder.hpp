_Pragma("once");
#include<string>
#include<part_info.hpp>
#include<filesystem.hpp>
namespace fs = ghc::filesystem;
using HFormatter::NPartInfo::PartInfo;
namespace HFormatter::NPackageBuilder{
    class PackageBuilder{
        protected:
            virtual void createPackage(const fs::path&);
            virtual void addItem(const std::string&);
            virtual void closePackage();
        public:
            void build(const PartInfo&, const std::string&);
    };
}