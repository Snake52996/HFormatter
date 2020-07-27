#include<indexer.hpp>
#include<logger.hpp>
using HFormatter::NIndexer::Indexer;
using HFormatter::NPartInfo::PartInfo;
using HFormatter::NPartIdentifier::PartIdentifier;
using HFormatter::NLogger::logger;
Indexer::Indexer(){;}
PartInfo Indexer::getPartInfo(const PartIdentifier& non){
    logger->error("You've reached Indexer::getPartInfo, which is not supposed to be called.");
    return PartInfo("sense");
}
Indexer::~Indexer(){;}