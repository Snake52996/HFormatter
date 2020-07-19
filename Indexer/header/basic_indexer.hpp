_Pragma("once");
namespace HFormatter::Indexer{
    class Indexer{
        public:
			Indexer() = delete;
			virtual const HFormatter::ChapterInfo::ChapterInfo& getChapterInfo(const HFormatter::ChapterIdentifier::ChapterIdentifier&);
    };
}