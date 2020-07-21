_Pragma("once");
#include<package_builder.hpp>
#include<hpdf.h>
#include<string>
namespace HFormatter::NPackageBuilder{
    class HaruPackageBuilder: public PackageBuilder{
        private:
            HPDF_Doc pdf_ = nullptr;
            HPDF_Page page_ = nullptr;
            HPDF_Image image_ = nullptr;
            fs::path filename_;
            unsigned int width_;
            unsigned int height_;
		protected:
			virtual void createPackage(const fs::path&);
            virtual void addItem(const std::string&);
            virtual void closePackage();
        public:
            ~HaruPackageBuilder();
    };
}