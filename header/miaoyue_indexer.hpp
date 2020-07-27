_Pragma("once");
#include<indexer.hpp>
#include<filesystem/filesystem.hpp>
namespace fs = ghc::filesystem;
namespace HFormatter::NIndexer{
    class MiaoyueIndexer: public Indexer{
        private:
            fs::path base_;
        public:
            MiaoyueIndexer(const std::string&);
            virtual HFormatter::NPartInfo::PartInfo getPartInfo(const HFormatter::NPartIdentifier::PartIdentifier&);
            ~MiaoyueIndexer();
    };
}