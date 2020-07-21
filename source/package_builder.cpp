#include<package_builder.hpp>
#include<string>
using HFormatter::NPackageBuilder::PackageBuilder;
using std::string;
void PackageBuilder::createPackage(const fs::path& package){;}
void PackageBuilder::addItem(const string& item_path){;}
void PackageBuilder::closePackage(){;}
void PackageBuilder::build(const PartInfo& info, const string& package_target){
    this->createPackage(fs::path(package_target) /= info.getTitle());
    for(const auto& item: info.getItems()) this->addItem(item);
    this->closePackage();
}