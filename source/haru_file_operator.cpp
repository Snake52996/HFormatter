#include<haru_file_operator.hpp>
#include<string_counter.hpp>
#include<opencv2/opencv.hpp>
#include<filesystem.hpp>
#include<string>
#include<vector>
namespace fs = ghc::filesystem;
using HFormatter::NFileOperator::HaruFileOperator;
using HFormatter::NStringCounter::StringCounter;
using std::string;
using std::vector;
HaruFileOperator::HaruFileOperator():params_({cv::IMWRITE_JPEG_QUALITY, 100}){;}
void HaruFileOperator::operateItem(PartInfo& info){
    StringCounter counter((unsigned int)(log10(info.getItems().size())) + 1);
    for(auto& item: info.getItems()){
        new_path_ = item;
        new_path_.replace_filename(counter++()).concat(".jpg");
        cv::imwrite(new_path_.c_str(), cv::imread(item.c_str()), params_);
        item = new_path_.string();
    }
}