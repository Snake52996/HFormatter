/**
 * @file pica_indexer.cpp
 * @brief implements methods in class PicaIndexer
 * @author Snake52996
*/
#include<pica_indexer.hpp>
#include<logger.hpp>
#include<stdexcept>
using HFormatter::NLogger::logger;
using HFormatter::NIndexer::PicaIndexer;
using HFormatter::NPartInfo::PartInfo;
using HFormatter::NPartIdentifier::PartIdentifier;
void PicaIndexer::openDatabase(const std::string& database){
    if(database_ != nullptr)
        logger->warn("perviously opened database has not closed: non-null handle");
    if(sqlite3_open_v2(
        database.c_str(),
        &database_,
        SQLITE_OPEN_READONLY,
        NULL
    ) != SQLITE_OK){
        logger->critical("failed to open database. {}", sqlite3_errmsg(database_));
        closeDatabase();
        throw std::runtime_error("failed to open database");
    }
}
void PicaIndexer::closeDatabase(){
    if(database_ == nullptr) return;
    if(sqlite3_close(database_) != SQLITE_OK){
        logger->critical("failed to close database. {}", sqlite3_errmsg(database_));
        throw std::runtime_error("failed to close database");
    }
    database_ = nullptr;
    logger->info("database closed");
}
void PicaIndexer::prepareQuery(){
    if(sqlite3_prepare_v2(
        database_,
        sql_buffer_.c_str(),
        -1,
        &sql_handle_,
        NULL
    ) != SQLITE_OK){
        logger->critical("failed to query database. {}", sqlite3_errmsg(database_));
        closeDatabase();
        throw std::runtime_error("failed to query database");
    }
}
void PicaIndexer::prepareTitleQuery(const std::string& id){
    sql_buffer_ = "SELECT DB_COMIC_DETAIL_OBJECT.TITLE,DOWNLOAD_COMIC_EPISODE_OBJECT.TITLE FROM DB_COMIC_DETAIL_OBJECT INNER JOIN DOWNLOAD_COMIC_EPISODE_OBJECT ON DB_COMIC_DETAIL_OBJECT.COMIC_ID=DOWNLOAD_COMIC_EPISODE_OBJECT.COMIC_ID WHERE DOWNLOAD_COMIC_EPISODE_OBJECT.EPISODE_ID=\"";
    sql_buffer_ += id + '\"';
    prepareQuery();
}
void PicaIndexer::prepareItemQuery(const std::string& id){
    sql_buffer_ = "SELECT MEDIA_PATH FROM DOWNLOAD_COMIC_PAGE_OBJECT WHERE EPISODE_ID=\"";
    sql_buffer_ += id + '\"';
    prepareQuery();
}
PicaIndexer::PicaIndexer(const std::string& database){
    logger->debug("opening {}", database);
    openDatabase(database);
    logger->info("database {} opened", database);
}
PartInfo PicaIndexer::getPartInfo(const PartIdentifier& id){
    logger->info("start indexing {}", id.getIdentifier());
    // get title
    prepareTitleQuery(id.getIdentifier());
    if(sqlite3_step(sql_handle_) != SQLITE_ROW){
        logger->error("no informaton related to {} found", id.getIdentifier());
        return PartInfo("null");
    }
    PartInfo result(
        string((char*)(sqlite3_column_text(sql_handle_, 0))) + '-' +
        string((char*)(sqlite3_column_text(sql_handle_, 1)))
    );
    logger->debug("get temp title {}", result.getTitle());
    // justify title
    result.setTitle(std::regex_replace(result.getTitle(), unsafe_char_, safe_char_));
    logger->info("find title {}", result.getTitle());
    sqlite3_finalize(sql_handle_);
    // get items
    prepareItemQuery(id.getIdentifier());
    while(sqlite3_step(sql_handle_) == SQLITE_ROW){
        result.addItem((char*)(sqlite3_column_text(sql_handle_, 0)));
        logger->info("added item {}", (char*)(sqlite3_column_text(sql_handle_, 0)));
    }
    sqlite3_finalize(sql_handle_);
    logger->info("finished indexing {}", id.getIdentifier());
    return result;
}
PicaIndexer::~PicaIndexer(){
    if(database_ != nullptr){
        if(sql_handle_ != nullptr) sqlite3_finalize(sql_handle_);
        closeDatabase();
    }
}