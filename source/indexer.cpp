#include<indexer.hpp>
using HFormatter::NIndexer::Indexer;
using HFormatter::NPartInfo::PartInfo;
using HFormatter::NPartIdentifier::PartIdentifier;
Indexer::Indexer(){;}
PartInfo Indexer::getPartInfo(const PartIdentifier& non){return PartInfo("sense");}
void Indexer::close(){;}