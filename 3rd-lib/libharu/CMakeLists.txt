cmake_minimum_required(VERSION 3.16.0)
project(libharu)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)
# support all of the different variations of LIBPNG defines in HARU
set (LIBHPDF_HAVE_LIBPNG ${PNG_FOUND})
if (NOT PNG_FOUND)
   set (LIBHPDF_HAVE_NOPNGLIB 1)
   set (HPDF_NOPNGLIB 1)
endif (NOT PNG_FOUND)
# support different zlib defines
set (LIBHPDF_HAVE_LIBZ ${ZLIB_FOUND})
if (NOT ZLIB_FOUND)
   set (LIBHPDF_HAVE_NOZLIB 1)
endif (NOT ZLIB_FOUND)
# create hpdf_config.h
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/hpdf_config.h.cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/include/hpdf_config.h
)
add_library(${PROJECT_NAME} SHARED ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)