#include<miaoyue_file_operator.hpp>
#include<string_counter.hpp>
using HFormatter::NFileOperator::MiaoyueFileOperator;
using HFormatter::NStringCounter::StringCounter;
void MiaoyueFileOperator::operateItem(PartInfo& info){
    StringCounter counter(info.getItems().size());
    for(auto& item: info.getItems()){
        new_path_ = item;
        fs::rename(
            item,
            new_path_.replace_filename(counter++() + ".jpg")
        );
        item = new_path_.string();
    }
}