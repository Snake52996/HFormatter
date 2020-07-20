#include<part_info.hpp>
using HFormatter::NPartInfo::PartInfo;
PartInfo::PartInfo(const string& title):part_title_(title){;}
void PartInfo::setTitle(const string& part_title){part_title_ = part_title;}
const string& PartInfo::getTitle()const{return part_title_;}
void PartInfo::addItem(const string& item){part_items_.push_back(item);}
const string& PartInfo::getItem(const unsigned int index)const{return part_items_.at(index);}
const vector<string>& PartInfo::getItems()const{return part_items_;}