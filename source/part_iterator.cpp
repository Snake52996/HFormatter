#include<part_iterator.hpp>
#include<filesystem/filesystem.hpp>
#include<string>
using std::string;
namespace fs = ghc::filesystem;
using HFormatter::NPartIterator::PartIterator;
PartIterator::PartIterator(const string& path):
    source_iterator_(path),
    end_(fs::end(source_iterator_)){;}
string PartIterator::getNextPart(){
    while(source_iterator_ != end_ && !source_iterator_->is_directory()) source_iterator_++;
    if(source_iterator_ == end_) return "";
    auto temp = source_iterator_->path();
    source_iterator_++;
    return temp.string();
}