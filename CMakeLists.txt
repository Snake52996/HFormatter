cmake_minimum_required(VERSION 3.16)
macro(SUBDIRLIST result curdir)
	file(GLOB children RELATIVE ${curdir} ${curdir}/*)
	set(dirlist "")
	foreach(child ${children})
		if(IS_DIRECTORY ${curdir}/${child})
			LIST(APPEND dirlist ${child})
		endif()
	endforeach()
	set(${result} ${dirlist})
endmacro()
project(HFormatter)

if(NOT DEFINED BUILD_TYPE)
  set(BUILD_TYPE "Release")
endif()

if("${BUILD_TYPE}" STREQUAL "Release")
	add_compile_options(-Wall -s -O3)
elseif("${BUILD_TYPE}" STREQUAL "Debug")
	add_compile_options(-Wall -g -O0)
else()
	message(FATAL_ERROR "Unknown build type")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Out")

# 3rd party
include_directories("3rd-header/")	# header-only library
SUBDIRLIST(THIRD_LIBS "${CMAKE_CURRENT_LIST_DIR}/3rd-lib")
set_property(GLOBAL PROPERTY G_THIRD_LIBS "${THIRD_LIBS}")
foreach(THIRD_LIB ${THIRD_LIBS})
	add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/3rd-lib/${THIRD_LIB}")
endforeach()

# collect all headers
file(GLOB ALL_INCLUDES "header/*.hpp")
include_directories("header/")

# collect all sources
#aux_source_directory("source/" ALL_SRCS)

#add_library(libHFormatter SHARED ${ALL_SRCS})
#target_include_directories(libHFormatter PRIVATE ${THIRD_LIBS})
#target_link_libraries(libHFormatter ${THIRD_LIBS})
add_subdirectory("source/")

# todo: add_executable/add_library

# target_include_directories(${PROJECT_NAME} PRIVATE ${THIRD_LIBS})
# target_link_libraries(${PROJECT_NAME} ${THIRD_LIBS})

# build tests
add_subdirectory("tests/")