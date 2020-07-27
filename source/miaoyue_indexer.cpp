#include<miaoyue_indexer.hpp>
#include<nlohmann/json.hpp>
#include<fstream>
#include<MD5/MD5.h>
using HFormatter::NIndexer::MiaoyueIndexer;
using HFormatter::NPartInfo::PartInfo;
using HFormatter::NPartIdentifier::PartIdentifier;
using nlohmann::json;
MiaoyueIndexer::MiaoyueIndexer(const std::string& base):base_(base){;}
PartInfo MiaoyueIndexer::getPartInfo(const PartIdentifier& id){
    // locate index file according to the pattern of Miaoyue
    std::ifstream index_file(
        base_ / fs::path(id.getIdentifier()) / fs::path(id.getIdentifier() + ".txt")
    );
    std::string temp_json;
    std::getline(index_file, temp_json, char(-1));    // read all content from file
    index_file.close();
    auto index_json = json::parse(temp_json);
    temp_json.clear();
    PartInfo info(index_json["title"]);
    MD5 md5_calculator;
    for(auto& url: index_json["img"]){
        md5_calculator.init();
        md5_calculator.update(string(url).c_str(), string(url).size());
        info.addItem(md5_calculator.finalize().hexdigest());
    }
    index_json.clear();
    return info;
}
MiaoyueIndexer::~MiaoyueIndexer(){;}