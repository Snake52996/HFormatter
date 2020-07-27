cmake_minimum_required(VERSION 3.16)
project(HFormatter_sources)

add_library(Logger SHARED logger.cpp)
target_include_directories(Logger PRIVATE spdlog)
target_link_libraries(Logger spdlog)

add_library(StringCounter SHARED string_counter.cpp)
target_link_libraries(StringCounter spdlog Logger)

add_library(FileOperator SHARED file_operator.cpp miaoyue_file_operator.cpp)
target_link_libraries(FileOperator spdlog StringCounter)

add_library(PartIdentifier SHARED part_identifier.cpp)
target_link_libraries(PartIdentifier spdlog Logger)

add_library(IdentifierGenerator SHARED identifier_generator.cpp)
target_link_libraries(IdentifierGenerator spdlog PartIdentifier)

add_library(PartInfo SHARED part_info.cpp)
#target_include_directories(PartInfo PRIVATE spdlog)
target_link_libraries(PartInfo spdlog Logger)

add_library(Indexer SHARED indexer.cpp miaoyue_indexer.cpp pica_indexer.cpp)
target_link_libraries(Indexer spdlog PartIdentifier PartInfo sqlite3)

add_library(PartIterator SHARED part_iterator.cpp)
target_link_libraries(PartIterator spdlog Logger)

add_library(PathCompleter SHARED path_completer.cpp)
target_link_libraries(PathCompleter spdlog Logger)

add_library(PackageBuilder SHARED package_builder.cpp haru_package_builder.cpp)
target_include_directories(PackageBuilder PRIVATE libharu)
target_link_libraries(PackageBuilder spdlog libharu PartInfo)