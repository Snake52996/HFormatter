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

# 3rd party
include_directories("3rd-header/")	# header-only library
SUBDIRLIST(THIRD_LIBS "${CMAKE_CURRENT_LIST_DIR}/3rd-lib")
foreach(THIRD_LIB ${THIRD_LIBS})
	add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/3rd-lib/${THIRD_LIB}")
endforeach()

# collect all headers
file(GLOB ALL_INCLUDES "header/*.hpp")
include_directories("header/")

# collect all sources
aux_source_directory("source/" ALL_SRCS)

# todo: add_executable/add_library

target_include_directories(${PROJECT_NAME} PRIVATE ${THIRD_LIBS})
target_link_libraries(${PROJECT_NAME} ${THIRD_LIBS})