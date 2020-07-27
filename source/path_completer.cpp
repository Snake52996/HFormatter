#include<path_completer.hpp>
#include<logger.hpp>
#include<string>
using HFormatter::NLogger::logger;
using std::string;
using HFormatter::NPathCompleter::PathCompleter;
string PathCompleter::getBase()const{
    logger->debug("Accessed base of PathCompleter: {}", base_);
    return base_.string();
}
void PathCompleter::setBase(const string& new_base){
    logger->debug("PathCompleter base changed: {} -> {}", base_, new_base);
    base_ = new_base;
}
void PathCompleter::operator()(string& item){
    logger->debug("operated: {}->{}", item, base_ / item);
    item = (base_ / item).string();
}