#include<file_operator.hpp>
#include<string_counter.hpp>
#include<logger.hpp>
#include<filesystem/filesystem.hpp>
#include<string>
namespace fs = ghc::filesystem;
using HFormatter::NFileOperator::FileOperator;
using HFormatter::NStringCounter::StringCounter;
using std::string;
using HFormatter::NLogger::logger;
void FileOperator::operateItem(PartInfo& info){
    StringCounter counter(info.getItems().size());
    for(auto& item: info.getItems()){
        new_path_ = item;
        new_path_.replace_filename(counter++() + new_path_.extension().string());
        if(!fs::exists(item)){
            if(!fs::exists(new_path_)){
            logger->error("item {} not found", item);
            continue;
            }else{
                logger->info("item {} already renamed", item);
            }
        }else{
            fs::rename(item, new_path_);
            logger->info("renamed {}->{}", item, new_path_);
        }
        item = new_path_.string();
    }
}