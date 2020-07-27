/**
 * @file pica_indexer.hpp
 * @brief defines class PicaIndexer
 * @author Snake52996
*/
_Pragma("once");
#include<indexer.hpp>
#include<sqlite3.h>
#include<regex>
namespace HFormatter::NIndexer{
    class PicaIndexer: public Indexer{
        private:
            sqlite3* database_ = nullptr;
            sqlite3_stmt* sql_handle_ = nullptr;
            std::string sql_buffer_;
            const std::regex unsafe_char_{"[/\\:\\*\\?\"<>\\|]"};
            const std::string safe_char_{" "};
            void openDatabase(const std::string&);
            void closeDatabase();
            void prepareQuery();
            void prepareTitleQuery(const std::string&);
            void prepareItemQuery(const std::string&);
        public:
            PicaIndexer(const std::string&);
            virtual HFormatter::NPartInfo::PartInfo getPartInfo(const HFormatter::NPartIdentifier::PartIdentifier&);
            ~PicaIndexer();
    };
}