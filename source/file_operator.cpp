#include<file_operator.hpp>
#include<string_counter.hpp>
#include<filesystem/filesystem.hpp>
#include<string>
#include<cmath>
namespace fs = ghc::filesystem;
using HFormatter::NFileOperator::FileOperator;
using HFormatter::NStringCounter::StringCounter;
using std::string;
void FileOperator::operateItem(PartInfo& info){
    StringCounter counter((unsigned int)(log10(info.getItems().size())) + 1);
    for(auto& item: info.getItems()){
        new_path_ = item;
        fs::rename(
            item,
            new_path_.replace_filename(counter++() + new_path_.extension().string())
        );
        item = new_path_.string();
    }
}