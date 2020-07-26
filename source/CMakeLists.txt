cmake_minimum_required(VERSION 3.16)
project(HFormatter_sources)

add_library(Logger SHARED console_logger.cpp logger.cpp)
target_include_directories(Logger PRIVATE spdlog)
target_link_libraries(Logger spdlog)

add_library(StringCounter SHARED string_counter.cpp)

add_library(FileOperator SHARED file_operator.cpp)
target_link_libraries(FileOperator StringCounter)

add_library(PartIdentifier SHARED part_identifier.cpp)

add_library(IdentifierGenerator SHARED identifier_generator.cpp)
target_link_libraries(IdentifierGenerator PartIdentifier)

add_library(PartInfo SHARED part_info.cpp)

add_library(Indexer SHARED indexer.cpp)
target_link_libraries(Indexer PartIdentifier PartInfo)

add_library(PartIterator SHARED part_iterator.cpp)

add_library(PathCompleter SHARED path_completer.cpp)

add_library(PackageBuilder SHARED package_builder.cpp haru_package_builder.cpp)
target_include_directories(PackageBuilder PRIVATE libharu)
target_link_libraries(PackageBuilder libharu PartInfo)