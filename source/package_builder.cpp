#include<package_builder.hpp>
#include<logger.hpp>
#include<string>
using HFormatter::NPackageBuilder::PackageBuilder;
using HFormatter::NLogger::logger;
using std::string;
void PackageBuilder::createPackage(const fs::path& package){
    logger->info("building package: doing nothing");
}
void PackageBuilder::addItem(const string& item_path){;}
void PackageBuilder::closePackage(){;}
void PackageBuilder::build(const PartInfo& info, const string& package_target){
    this->createPackage(fs::path(package_target) /= info.getTitle());
    logger->info("started building package: {}", info.getTitle());
    for(const auto& item: info.getItems()){
        logger->info("adding {} to package", item);
        this->addItem(item);
    }
    this->closePackage();
    logger->info("package {} saved", info.getTitle());
}