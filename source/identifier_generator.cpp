#include<identifier_generator.hpp>
#include<part_identifier.hpp>
#include<filesystem.hpp>
#include<string>
namespace fs = ghc::filesystem;
using std::string;
using HFormatter::NIdentifierGenerator::IdentifierGenerator;
using HFormatter::NPartIdentifier::PartIdentifier;
PartIdentifier IdentifierGenerator::getIdentifier(const string& path){
    return PartIdentifier(fs::path(path).filename().string());
}