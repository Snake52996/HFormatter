#include<identifier_generator.hpp>
#include<logger.hpp>
#include<part_identifier.hpp>
#include<filesystem/filesystem.hpp>
#include<string>
namespace fs = ghc::filesystem;
using std::string;
using HFormatter::NIdentifierGenerator::IdentifierGenerator;
using HFormatter::NPartIdentifier::PartIdentifier;
using HFormatter::NLogger::logger;
PartIdentifier IdentifierGenerator::getIdentifier(const string& path){
    logger->debug("generating identifier for {}", path);
    return PartIdentifier(fs::path(path).filename().string());
}