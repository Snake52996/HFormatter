#include<part_identifier.hpp>
#include<logger.hpp>
using HFormatter::NPartIdentifier::PartIdentifier;
using HFormatter::NLogger::logger;
PartIdentifier::PartIdentifier(const string& identifier):part_identifier_(identifier){
    logger->debug("new PartIdentifier {}", part_identifier_);
}
void PartIdentifier::setIdentifier(const string& identifier){
    logger->debug(
        "PartIdentifier changed: {} -> {}",
        part_identifier_,
        identifier
    );
    part_identifier_ = identifier;
}
const string& PartIdentifier::getIdentifier()const{
    logger->debug("accessed identifier {}", part_identifier_);
    return part_identifier_;
}