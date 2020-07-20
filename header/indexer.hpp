_Pragma("once");
#include<part_identifier.hpp>
#include<part_info.hpp>
#include<string>
namespace HFormatter::NIndexer{
    class Indexer{
        public:
			Indexer();
			virtual HFormatter::NPartInfo::PartInfo getPartInfo(const HFormatter::NPartIdentifier::PartIdentifier&);
            virtual void close();
    };
}