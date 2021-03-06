cmake_minimum_required(VERSION 2.8)

# define a macro that helps defining an option
macro(sfml_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# set a default build type if none was provided
# this has to be done before the project() instruction!
sfml_set_option(CMAKE_BUILD_TYPE Release
  STRING "Choose the type of build (Debug or Release)")
string(TOLOWER ${CMAKE_BUILD_TYPE} LC_BUILD_TYPE)
sfml_set_option(CLASP_GC boehm
  STRING "Choose the clasp garbage collector (boehm or mps)")


#LIST(APPEND CMAKE_FIND_LIBRARY_SUFFIXES ".so")
#This always results in clang 3.7 for me, where clasp was compiled with clang 3.6
#set(CMAKE_CXX_COMPILER clang++)
#set(CMAKE_C_COMPILER clang)

# project name
project(clasp-sfml)

#Add library suffixes for OSX here.


find_path(CLASP_INCLUDE_PATH clasp/clbind/clbind.h HINTS $ENV{CLASP_HOME}/include
  DOC "The include directory of clasp")
find_path(CLASP_SRC_MAIN_PATH clasp_gc.cc HINTS $ENV{CLASP_HOME}/src/main/
  DOC "The path to clasp_gc.cc, hopefully a temporary necessity")
find_path(SFML_INCLUDE_PATH SFML/System.hpp HINTS $ENV{SFML_INCLUDE_DIR}
  DOC "The include directory of SFML")

find_library(CLASP_CLBIND_LIB clasp-clbind
  HINTS $ENV{CLASP_HOME}/build/clasp/Contents/execs/${CLASP_GC}/${LC_BUILD_TYPE}/lib
  DOC "The clasp clbind library")
#find_path(EXTERNALS_CLASP_PATH gc_cpp.h DOC "The directory of externals-clasp")

# add the SFML header path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CLASP_INCLUDE_PATH}
  ${CLASP_INCLUDE_PATH}/clasp/main
  ${CLASP_SRC_MAIN_PATH}
  ${SFML_INCLUDE_PATH})

add_compile_options(-std=c++11
   -v 
   -fPIC
   -D_TARGET_OS_LINUX
   -DX86
   -DNDEBUG
   -DUSE_BOEHM
   -DUSE_ALLOCA_FOR_FRAME
   -D_ADDRESS_MODEL_64
   -Wl,--start-group
   ${CLASP_CLBIND_LIB}
   -Wl,--end-group)
 
 set(BUILD_SHARED_LIBS TRUE)

 set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/${CLASP_GC}/${LC_BUILD_TYPE})
 
 # add the subdirectories
 add_subdirectory(src/clasp-sfml)
