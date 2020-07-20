#include<string_counter.hpp>
#include<string>
#include<stdexcept>
using std::string;
using HFormatter::NStringCounter::StringCounter;
StringCounter::StringCounter(const unsigned int& length){
    if(length == 0) throw std::logic_error("Length of counter can't be 0");
    for(unsigned int i = 1; ; ++i){
        value_.push_back('0');
        if(i == length) break;
    }
}
StringCounter& StringCounter::operator++(){
    for(unsigned int i = value_.size() - 1; ; --i){
        if(value_[i] == '9'){
            if(i == 0) throw std::out_of_range("Counter overflow");
            else value_[i] = '0';
        }else{
            ++value_[i];
            break;
        }
    }
    return *this;
}
StringCounter StringCounter::operator++(int){
    StringCounter tmp(*this);
    for(unsigned int i = value_.size() - 1; ; --i){
        if(value_[i] == '9'){
            if(i == 0) throw std::out_of_range("Counter overflow");
            else value_[i] = '0';
        }else{
            ++value_[i];
            break;
        }
    }
    return tmp;
}
string StringCounter::operator()()const{return value_;}