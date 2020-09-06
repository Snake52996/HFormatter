#include<string_counter.hpp>
#include<logger.hpp>
#include<string>
#include<stdexcept>
#include<cmath>
using std::string;
using HFormatter::NStringCounter::StringCounter;
using HFormatter::NLogger::logger;
void StringCounter::checkOverflow()const{
    if(this->is_overflow_) throw std::out_of_range("Counter overflow");
}
StringCounter::StringCounter(const unsigned int& max_count){
    if(max_count == 0) throw std::logic_error("Maximum value can't be 0");
    double temp_length = log10(max_count);
    unsigned int length = temp_length;
    if(fabs(temp_length - length) >= 1e-8) ++length;
    for(unsigned int i = 1; ; ++i){
        value_.push_back('0');
        if(i == length) break;
    }
    logger->debug(
        "StringCounter: requested max_count: {}, digital length set to {}",
        max_count,
        length
    );
    is_overflow_ = false;
}
StringCounter& StringCounter::operator++(){
    this->checkOverflow();
    for(unsigned int i = value_.size() - 1; ; --i){
        if(value_[i] == '9'){
            if(i == 0){is_overflow_ = true; break;}
            else value_[i] = '0';
        }else{
            ++value_[i];
            break;
        }
    }
    return *this;
}
StringCounter StringCounter::operator++(int){
    this->checkOverflow();
    StringCounter tmp(*this);
    for(unsigned int i = value_.size() - 1; ; --i){
        if(value_[i] == '9'){
            if(i == 0){is_overflow_ = true; break;}
            else value_[i] = '0';
        }else{
            ++value_[i];
            break;
        }
    }
    return tmp;
}
string StringCounter::operator()()const{
    this->checkOverflow();
    return value_;
}