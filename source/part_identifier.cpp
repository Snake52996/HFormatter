#include<part_identifier.hpp>
using HFormatter::NPartIdentifier::PartIdentifier;
PartIdentifier::PartIdentifier(const string& identifier):part_identifier_(identifier){}
void PartIdentifier::setIdentifier(const string& identifier){part_identifier_ = identifier;}
const string& PartIdentifier::getIdentifier()const{return part_identifier_;}