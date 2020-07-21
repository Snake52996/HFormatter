#include<path_completer.hpp>
#include<string>
using std::string;
using HFormatter::NPathCompleter::PathCompleter;
string PathCompleter::getBase()const{return base_.string();}
void PathCompleter::setBase(const string& new_base){base_ = new_base;}
void PathCompleter::operator()(string& item){item = (base_ / item).string();}