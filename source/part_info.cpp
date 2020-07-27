#include<part_info.hpp>
#include<logger.hpp>
using HFormatter::NPartInfo::PartInfo;
using HFormatter::NLogger::logger;
PartInfo::PartInfo(const string& title):part_title_(title){
    logger->debug("new PartInfo {}", part_title_);
}
void PartInfo::setTitle(const string& part_title){
    logger->debug("PartInfo title changed: {} -> {}", part_title_, part_title);
    part_title_ = part_title;
}
const string& PartInfo::getTitle()const{
    logger->debug("accessed title of PartInfo {}", part_title_);
    return part_title_;
}
void PartInfo::addItem(const string& item){
    part_items_.push_back(item);
    logger->debug("PartInfo {} added item {}", part_title_, item);
}
const string& PartInfo::getItem(const unsigned int index)const{
    logger->debug("accessed item of PartInfo {} at index {}", part_title_, index);
    return part_items_.at(index);
}
const vector<string>& PartInfo::getItems()const{
    logger->debug("referred item (const) of PartInfo {}", part_title_);
    return part_items_;
}
vector<string>& PartInfo::getItems(){
    logger->debug("referred item (non-const) of PartInfo {}", part_title_);
    return part_items_;
}
void PartInfo::updateItems(PathCompleter& operate){
    for(auto& item: part_items_){
        logger->debug("Updating item {} in PartInfo {}", item, part_title_);
        operate(item);
        logger->debug("\tto {}.", item);
    }
}